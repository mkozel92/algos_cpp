#ifndef ALGOS_BINARY_TREES_BINARY_TREE_H_
#define ALGOS_BINARY_TREES_BINARY_TREE_H_

#include<string>
#include<iostream>
#include<memory>

namespace binary_tree {
/**
* @brief A node for a binary tree
*
* @tparam K type of keys in the tree
* @tparam V type of values in the tree
*/


template<class K, class V>
class Node {
public:
  K key_;
  V value_;
  std::shared_ptr<Node> left_;
  std::shared_ptr<Node> right_;
  std::shared_ptr<Node> next_;
  int count_;

  Node(K key, V value) : key_(key), value_(value), count_(1) {
    left_ = nullptr;
    right_ = nullptr;
    next_ = nullptr;
  };
};

template<class K, class V>
using NodePtr = std::shared_ptr<Node<K, V>>;


/**
* @brief simple binary tree
*
* @tparam K type of key values in tree nodes
* @tparam V type of values in tree nodes
*/
template<class K, class V>
class BinaryTree {
private:
  NodePtr <K, V> Put(NodePtr <K, V>, K, V);

  int Size(NodePtr <K, V>);

public:
  NodePtr <K, V> root_;

  BinaryTree() : root_(nullptr) {};

  void Put(K, V);

  V *Get(K);

  void InorderPrint(NodePtr <K, V>);
};

template<class K, class V>
void BinaryTree<K, V>::Put(K key, V value) {
  root_ = Put(root_, key, value);
}

/**
* @brief insert new Node to the tree
*
* @tparam K type of key
* @tparam V type of value
* @param node root of the tree to insert to
* @param key key to insert
* @param value value to insert
*
* @return pointer to the new node or subtree with added node
*/
template<class K, class V>
NodePtr <K, V> BinaryTree<K, V>::Put(NodePtr <K, V> node, K key, V value) {
  if (node == nullptr) {
    return std::make_shared<Node<K, V>>(key, value);
  }
  if (node->key_ > key) {
    node->left_ = Put(node->left_, key, value);
  } else if (node->key_ < key) {
    node->right_ = Put(node->right_, key, value);
  } else {
    node->value_ = value;
  }
  node->count_ = 1 + Size(node->left_) + Size(node->right_);
  return node;
}

/**
* @brief returns size of a tree with root in given node
*
* @tparam K type of keys
* @tparam V type of values
* @param node root of the tree to get the size of
*
* @return size of the tree
*/
template<class K, class V>
int BinaryTree<K, V>::Size(NodePtr <K, V> node) {
  if (node == nullptr) {
    return 0;
  }
  return node->count_;
}


/**
* @brief returns pointer to the value associated with the node with the given key
*
* @tparam K type of key
* @tparam V type of value
* @param key key to search
*
* @return pointer to the value of given key
*/
template<class K, class V>
V *BinaryTree<K, V>::Get(K key) {
  NodePtr <K, V> current = root_;
  while (current != nullptr) {
    if (current->key_ > key) {
      current = current->left_;
    } else if (current->key_ < key) {
      current = current->right_;
    } else {
      return &(current->value_);
    }
  }
  return nullptr;
}

template<class K, class V>
void BinaryTree<K, V>::InorderPrint(NodePtr <K, V> node) {
  if (node == nullptr) {
    return;
  }
  InorderPrint(node->left_);
  std::cout << node->key_ << " " << node->value_ << std::endl;
  InorderPrint(node->right_);
}

} //binary_tree

#endif // ALGOS_BINARY_TREES_BINARY_TREE_H_

