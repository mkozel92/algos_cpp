#include<iostream>

using namespace std;

/**
* @brief node implementation for red black tree
*
* @tparam K type of data the node store
*/
template<class K>
class Node{
  public:
    Node* left;
    Node* right;
    bool red;
    K key;
    Node(K key) : key(key), red(true), left(nullptr), right(nullptr) {};
};


/**
* @brief implementation of red black tree
* tree maintains its balance regardeless of the order of incoming elements
*
* @tparam K type of data in the tree
*/
template <class K>
class RedBlackTree{
  private:
    Node<K> *root;
    void flip_colours(Node<K>*);
    Node<K>* rotate_left(Node<K>*);
    Node<K>* rotate_right(Node<K>*);
    Node<K>* recursive_put(Node<K>*, K);
    bool is_red(Node<K>*);
    void recursive_print(Node<K>*);
  public:
    RedBlackTree() : root(nullptr) {};
    void print_tree();
    void put(K);
};


/**
* @brief check colour of a link leading to a node
*
* @tparam K type of key
* @param node node to check color for
*
* @return True if link leading to the node is red
*/
template <class K>
bool RedBlackTree<K>::is_red(Node<K> *node){
  if(node == nullptr){
    return false;  
  }
  return node->red;
}

/**
* @brief helper function to maintain balance in the tree
*
* @tparam K type of key
* @param node node to rotate
*
* @return pointer to new three with rotated node
*/
template <class K>
Node<K> *RedBlackTree<K>::rotate_left(Node<K>* node){
  Node<K> *new_node;
  new_node = node->right;
  node->right = new_node->left;
  new_node->left = node;
  new_node->red = node->red;
  node->red = true;
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
template <class K>
Node<K> *RedBlackTree<K>::rotate_right(Node<K> *node){
  Node<K> *new_node;
  new_node = node->left;
  node->left = new_node->right;
  new_node->right = node;
  new_node->red = node->red;
  node->red = true;
  return new_node;
}

/**
* @brief helper function to maintain balance in the tree
*
* @tparam K type of key
* @param node node for which to swich colours
*/
template <class K>
void RedBlackTree<K>::flip_colours(Node<K> *node){
  node->right->red = false;
  node->left->red = false;
  node->red = true;
}

template<class K>
void RedBlackTree<K>::put(K key){
  root = recursive_put(root, key);
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
Node<K> *RedBlackTree<K>::recursive_put(Node<K> *node, K key){
  if(node == nullptr){
    return new Node<K>(key);  
  }  
  if(key < node->key){
    node->left = recursive_put(node->left, key);
  }
  else if(key > node->key){
    node->right = recursive_put(node->right, key);
  }
  else{
    node->key = key;
  }
  
  if(!is_red(node->left) && is_red(node->right)){
    node = rotate_left(node);  
  }
  if(is_red(node->left) && is_red(node->left->left)){
    node = rotate_right(node);  
  }
  if(is_red(node->left) && is_red(node->right)){
  flip_colours(node);  
  }
  return node;
}


/**
* @brief preorder print
*
* @tparam K type of key
*/
template <class K>
void RedBlackTree<K>::print_tree(){
  recursive_print(root);  
}

/**
* @brief recursive function for preorder print
*
* @tparam K type of key
* @param node root of the tree to print
*/
template<class K>
void RedBlackTree<K>::recursive_print(Node<K> *node){
  if(node == nullptr){
    return;  
  }  
  cout<<node->key<<endl;
  recursive_print(node->left);
  recursive_print(node->right);
}

