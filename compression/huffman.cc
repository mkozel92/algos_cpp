//
// Created by michal on 16/06/19.
//
#include "huffman.h"

namespace huffman {
/**
 * comparator function for min heap that compares two binary trie nodes
 * @param first_node to compare
 * @param second_node to compare
 * @return true if the first node has smaller frequency value
 */
bool CompareNodes(NodePtr first_node, NodePtr second_node) {
  return first_node->frequency_ < second_node->frequency_;
}

/**
 * build a trie using character frequencies in given text
 */
void BinaryTrie::BuildTrie(const std::string &text) {
  std::unordered_map<char, int> frequencies;
  for (auto c : text)
    frequencies[c] += 1;

  BinaryHeap<NodePtr> min_heap(CompareNodes);
  for (const auto &f : frequencies) {
    NodePtr new_node = std::make_shared<Node>(f.second, true);
    new_node->value_ = f.first;
    min_heap.insert(new_node);
  }

  NodePtr left;
  NodePtr right;
  while (min_heap.size() > 2) {
    left = min_heap.remove();
    right = min_heap.remove();

    int frequency = left->frequency_ + right->frequency_;
    NodePtr new_node = std::make_shared<Node>(frequency, false);
    new_node->left_ = left;
    new_node->right_ = right;
    min_heap.insert(new_node);
  }
  left = min_heap.remove();
  right = min_heap.remove();
  int frequency = left->frequency_ + right->frequency_;

  root_ = std::make_shared<Node>(frequency, false);
  root_->left_ = left;
  root_->right_ = right;
}

void BinaryTrie::BuildEncodingMap() {
  std::vector<bool> code;
  RecBuildEncodingMap(root_, &code);
}

/**
 * helper function for building encoding map
 * @param node root of current subtrie
 * @param code vector with code representing the way to current node
 */
void BinaryTrie::RecBuildEncodingMap(NodePtr node, std::vector<bool> *code) {
  if (node->is_leaf_) {
    encoding_map_.emplace(node->value_, std::vector<bool>());
    for (auto bit: *code)
      encoding_map_[node->value_].push_back(bit);
  } else {
    code->push_back(true);
    RecBuildEncodingMap(node->left_, code);
    code->push_back(false);
    RecBuildEncodingMap(node->right_, code);
  }
  code->pop_back();
}

/**
 * encode a string to BitStream using huffman encoding
 * @return encoded bit stream
 */
BitStream BinaryTrie::Encode(const std::string &a_string) {
  BitStream bit_stream;
  for (const auto &c : a_string) {
    auto encoded = encoding_map_[c];
    for (auto bit : encoded)
      bit_stream.WriteBit(bit);
  }
  return bit_stream;
}

/**
 * decodes bit stream into a string
 * @param bit_stream encoded bit stream
 * @return decoded sttring
 */
std::string BinaryTrie::Decode(BitStream *bit_stream) {
  std::string decoded;
  NodePtr current = root_;
  while (!bit_stream->Empty()) {
    bool bit = bit_stream->ReadBit();
    if (bit)
      current = current->left_;
    else
      current = current->right_;

    if (current->is_leaf_) {
      decoded += current->value_;
      current = root_;
    }
  }
  return decoded;
}

}// huffman

