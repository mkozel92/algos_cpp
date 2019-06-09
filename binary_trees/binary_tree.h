#ifndef ALGOS_BINARY_TREES_BINARY_TREE_H_
#define ALGOS_BINARY_TREES_BINARY_TREE_H_

#include<string>
#include<iostream>
#include<memory>

namespace binary_tree{
/**
* @brief A node for a binary tree
*
* @tparam K type of keys in the tree
* @tparam V type of values in the tree
*/

template<class K, class V>
class Node{
  public:
    K key;
    V value;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    std::shared_ptr<Node> next;
    int count;
    Node(K key, V value) : key(key), value(value), count(1) {
        left = nullptr;
        right = nullptr;
        next = nullptr;
      };
};
 
template<class K, class V>
using node_ptr = std::shared_ptr<Node<K,V>>;


/**
* @brief simple binary tree
*
* @tparam K type of key values in tree nodes
* @tparam V type of values in tree nodes
*/
template <class K, class V>
class BinaryTree{
  private:    
    node_ptr<K, V> put(node_ptr<K, V>, K, V);
    node_ptr<K, V> _min(node_ptr<K, V>);
    node_ptr<K, V> _delete_min(node_ptr<K, V>);
    node_ptr<K, V> _delete_key(node_ptr<K, V>, K);
    int size(node_ptr<K, V>);
 public:
    node_ptr<K, V> root;
    BinaryTree() : root(nullptr) {};
    void put(K, V);
    V *get(K);
    void inorder_print(node_ptr<K, V>);
    void delete_key(K);
};

template <class K, class V>
void BinaryTree<K, V>::put(K key, V value){
  root = put(root, key, value);  
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
template <class K, class V>
node_ptr<K, V> BinaryTree<K, V>::put(node_ptr<K, V> node, K key, V value){
  if (node == nullptr){
    return std::make_shared<Node<K, V>>(key, value);
  }
  if (node->key > key){
    node->left = put(node->left, key, value);
  }
  else if(node->key < key){
    node->right = put(node->right, key, value);  
  }
  else{
    node->value = value;  
  }
  node->count = 1 + size(node->left) + size(node->right);
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
int BinaryTree<K, V>::size(node_ptr<K, V> node){
  if(node == nullptr){
    return 0;  
  }  
  return node->count;
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
template <class K, class V>
V *BinaryTree<K, V>::get(K key){
  node_ptr<K, V> current = root;
  while(current != nullptr){
    if(current->key > key){
      current = current->left;  
    }  
    else if(current->key < key){
      current = current->right;  
    }
    else{
      return &(current->value);
    }
  }
  return nullptr;
}

template<class K, class V>
void BinaryTree<K, V>::inorder_print(node_ptr<K, V> node){
  if (node == nullptr){
   return;
  }  
  inorder_print(node->left);
  std::cout<<node->key<<" "<<node->value<<std::endl;
  inorder_print(node->right);
}

} //binary_tree

#endif // ALGOS_BINARY_TREES_BINARY_TREE_H_

