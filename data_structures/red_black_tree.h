#ifndef ALGOS_DATA_STRUCTURES_RED_BLACK_TREE_H_
#define ALGOS_DATA_STRUCTURES_RED_BLACK_TREE_H_


#include<iostream>


/**
* @brief node implementation for red black tree
*
* @tparam K type of data the node store
*/
template<class K>
class Node {
public:
  Node *left_;
  Node *right_;
  bool red_;
  K key_;

  explicit Node(K key) : key_(key), red_(true), \
  left_(nullptr), right_(nullptr) {};
};


/**
* @brief implementation of red black tree
* tree maintains its balance regardeless of the order of incoming elements
*
* @tparam K type of data in the tree
*/
template<class K>
class RedBlackTree {
private:
  Node<K> *root_;

  void FlipColours(Node<K> *);

  Node<K> *RotateLeft(Node<K> *);

  Node<K> *RotateRight(Node<K> *);

  Node<K> *RecursivePut(Node<K> *, K);

  bool IsRed(Node<K> *);

  void RecursivePrint(Node<K> *);

public:
  RedBlackTree() : root_(nullptr) {};

  void PrintTree();

  void Put(K);
};


/**
* @brief check colour of a link leading to a node
*
* @tparam K type of key
* @param node node to check color for
*
* @return True if link leading to the node is red
*/
template<class K>
bool RedBlackTree<K>::IsRed(Node<K> *node) {
  if (node == nullptr) {
    return false;
  }
  return node->red_;
}

/**
* @brief helper function to maintain balance in the tree
*
* @tparam K type of key
* @param node node to rotate
*
* @return pointer to new three with rotated node
*/
template<class K>
Node<K> *RedBlackTree<K>::RotateLeft(Node<K> *node) {
  Node<K> *new_node;
  new_node = node->right_;
  node->right_ = new_node->left_;
  new_node->left_ = node;
  new_node->red_ = node->red_;
  node->red_ = true;
  return new_node;
}

/**
* @brief helper function to maintain balance in the tree
*
* @tparam K type of key
* @param node node to rotate
*
* @return pointer to new three with rotated node
*/
template<class K>
Node<K> *RedBlackTree<K>::RotateRight(Node<K> *node) {
  Node<K> *new_node;
  new_node = node->left_;
  node->left_ = new_node->right_;
  new_node->right_ = node;
  new_node->red_ = node->red_;
  node->red_ = true;
  return new_node;
}

/**
* @brief helper function to maintain balance in the tree
*
* @tparam K type of key
* @param node node for which to swich colours
*/
template<class K>
void RedBlackTree<K>::FlipColours(Node<K> *node) {
  node->right_->red_ = false;
  node->left_->red_ = false;
  node->red_ = true;
}

template<class K>
void RedBlackTree<K>::Put(K key) {
  root_ = recursive_put(root_, key);
}

/**
* @brief insert new node into RBT and mainain balance
* comlexity O(log N) as the tree is guaranteed to be balanced
*
* @tparam K type of key
* @param node root of tree to insert to
* @param key key to indsert
*
* @return pointer to the new tree with inserted node
*/
template<class K>
Node<K> *RedBlackTree<K>::RecursivePut(Node<K> *node, K key) {
  if (node == nullptr) {
    return new Node<K>(key);
  }
  if (key < node->key_) {
    node->left_ = RecursivePut(node->left_, key);
  } else if (key > node->key_) {
    node->right_ = RecursivePut(node->right_, key);
  } else {
    node->key_ = key;
  }

  if (!IsRed(node->left_) && IsRed(node->right_)) {
    node = RotateLeft(node);
  }
  if (IsRed(node->left_) && IsRed(node->left_->left_)) {
    node = RotateRight(node);
  }
  if (IsRed(node->left_) && IsRed(node->right_)) {
    FlipColours(node);
  }
  return node;
}


/**
* @brief preorder print
*
* @tparam K type of key
*/
template<class K>
void RedBlackTree<K>::PrintTree() {
  RecursivePrint(root_);
}

/**
* @brief recursive function for preorder print
*
* @tparam K type of key
* @param node root of the tree to print
*/
template<class K>
void RedBlackTree<K>::RecursivePrint(Node<K> *node) {
  if (node == nullptr) {
    return;
  }
  std::cout << node->key_ << std::endl;
  RecursivePrint(node->left_);
  RecursivePrint(node->right_);
}


#endif // ALGOS_DATA_STRUCTURES_RED_BLACK_TREE_H_
