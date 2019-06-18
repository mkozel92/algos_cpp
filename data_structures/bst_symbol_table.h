#ifndef ALGOS_DATA_STRUCTURES_BST_SYMBOL_TABLE_H_
#define ALGOS_DATA_STRUCTURES_BST_SYMBOL_TABLE_H_

#include<string>
#include<iostream>

namespace symbol_table {
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
  Node *left_;
  Node *right_;
  int count_;

  Node(K key, V value) : key_(key), value_(value), count_(1) {
    left_ = nullptr;
    right_ = nullptr;
  };
};


/**
* @brief binary tree represented symbol table
*
* @tparam K type of key values in symbol table
* @tparam V type of values in symbol table
*/
template<class K, class V>
class BSTSymbolTable {

private:
  Node<K, V> *Put(Node<K, V> *, K, V);

  Node<K, V> *Min(Node<K, V> *);

  Node<K, V> *DeleteMin(Node<K, V> *);

  Node<K, V> *DeleteKey(Node<K, V> *, K);

  int Size(Node<K, V> *);

public:
  Node<K, V> *root_;

  BSTSymbolTable() : root_(nullptr) {};

  void Put(K, V);

  V *Get(K);

  void InorderPrint(Node<K, V> *);

  void DeleteKey(K);
};

template<class K, class V>
void BSTSymbolTable<K, V>::Put(K key, V value) {
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
Node<K, V> *BSTSymbolTable<K, V>::Put(Node<K, V> *node, K key, V value) {
  if (node == nullptr) {
    return new Node<K, V>(key, value);
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
int BSTSymbolTable<K, V>::Size(Node<K, V> *node) {
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
V *BSTSymbolTable<K, V>::Get(K key) {
  Node<K, V> *current = root_;
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

/**
* @brief deletes a key from the tree
*
* @tparam K type of key
* @tparam V type of value
* @param key key to delete
*/
template<class K, class V>
void BSTSymbolTable<K, V>::DeleteKey(K key) {
  root_ = DeleteKey(root_, key);
}

/**
* @brief deletes node with a given key using Hibbard deletion
*
* @tparam K type of key
* @tparam V type of value
* @param node root of the tree to delete from
* @param key key to delete
*
* @return pointer to the new subree with deleted node
*/
template<class K, class V>
Node<K, V> *BSTSymbolTable<K, V>::DeleteKey(Node<K, V> *node, K key) {

  if (node == nullptr) {
    return nullptr;
  }
  if (node->key < key) {
    node->right_ = DeleteKey(node->right_, key);
  } else if (node->key_ > key) {
    node->left_ = DeleteKey(node->left, key);
  } else {
    if (node->left_ == nullptr) {
      return node->right_;
    } else if (node->right_ == nullptr) {
      return node->left_;
    }

    Node<K, V> *t = node;
    node = Min(t->right_);
    node->right_ = DeleteMin(t->right_);
    node->left_ = t->left_;
  }
  node->count_ = 1 + Size(node->left_) + Size(node->right_);
  return node;
}


/**
* @brief deletes the node with minimal value key
*
* @tparam K type of key
* @tparam V type of value
* @param node root of the tree to delete from
*
* @return pointer to the new subtree with deleted node
*/
template<class K, class V>
Node<K, V> *BSTSymbolTable<K, V>::DeleteMin(Node<K, V> *node) {
  if (node == nullptr) {
    return nullptr;
  }
  if (node->left_ == nullptr) {
    return node->right_;
  }
  node->left_ = DeleteMin(node->left_);
  node->count_ = 1 + Size(node->left_) + Size(node->right_);
  return node;
}


/**
* @brief returns a pointer to the node with minamal value key
*
* @tparam K type of key
* @tparam V type of value
* @param node root of the tree to search
*
* @return pointer to the node with minimal key
*/
template<class K, class V>
Node<K, V> *BSTSymbolTable<K, V>::Min(Node<K, V> *node) {
  if (node == nullptr) {
    return nullptr;
  }
  Node<K, V> *current = node;
  while (current->left_ != nullptr) {
    current = current->left_;
  }
  return current;
}


/**
* @brief inorder print of the symbol table
*
* @tparam K type of key
* @tparam V type of value
* @param node root of the tree to print
*/
template<class K, class V>
void BSTSymbolTable<K, V>::InorderPrint(Node<K, V> *node) {
  if (node == nullptr) {
    return;
  }
  InorderPrint(node->left_);
  std::cout << node->key_ << " " << node->value_ << std::endl;
  InorderPrint(node->right);
}

} //symbol_table namespace

#endif // ALGOS_DATA_STRUCTURES_BST_SYMBOL_TABLE_H_
