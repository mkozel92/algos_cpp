//
// Created by michal on 16/06/19.
//

#ifndef ALGOS_COMPRESSION_HUFFMAN_H_
#define ALGOS_COMPRESSION_HUFFMAN_H_
//
// Created by michal on 15/06/19.
//

#include <string>
#include <iostream>
#include <memory>
#include <unordered_map>
#include "../data_structures/binary_heap.h"
#include "../data_structures/bit_stream.h"


namespace huffman {

class Node;

typedef std::shared_ptr<Node> NodePtr;

/**
 * a Node for binary trie
 */
class Node {
public:
  NodePtr left_;
  NodePtr right_;
  bool is_leaf_;
  char value_;
  int frequency_;

  explicit Node(int frequency, bool is_leaf = false)
      : is_leaf_(is_leaf), left_(nullptr), \
      right_(nullptr), value_('\0'), frequency_(frequency) {};
};

/**
 * Binary trie used to represent huffman encodings
 */
class BinaryTrie {
private:
  NodePtr root_;
  std::unordered_map<char, std::vector<bool>> encoding_map_;

  /**
   * build a trie using character frequencies in given text
   */
  void BuildTrie(const std::string &);

  /**
   * build symbol table to store encodings for characters
   */
  void BuildEncodingMap();

  /**
   * helper function for building encoding map
   * @param node root of current subtrie
   * @param code vector with code representing the way to current node
   */
  void RecBuildEncodingMap(NodePtr node, std::vector<bool> *code);

public:
  explicit BinaryTrie(const std::string &text) {
    BuildTrie(text);
    BuildEncodingMap();
  };

/**
 * encode a string to BitStream using huffman encoding
 * @return encoded bit stream
 */
  BitStream Encode(const std::string &);

/**
 * decodes bit stream into a string
 * @param bit_stream encoded bit stream
 * @return decoded sttring
 */
  std::string Decode(BitStream *bit_stream);
};

} //huffman
#endif //ALGOS_COMPRESSION_HUFFMAN_H_
