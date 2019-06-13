#ifndef ALGOS_TERNARY_SEARCH_TRIES_H_
#define ALGOS_TERNARY_SEARCH_TRIES_H_

#include <memory>
#include <vector>
#include <string>
#include <iostream>

/**
* @brief Node for ternary search trie
*
* @tparam T data type 
*/
template <class T>
class Node{
  public:
    std::shared_ptr<Node> left_;
    std::shared_ptr<Node> middle_;
    std::shared_ptr<Node> right_;
    char key_char_;
    T value_;
    Node() : left_(nullptr), right_(nullptr), middle_(nullptr) {};
};


/**
* @brief implementation of ternary search trie
*
* @tparam T data type
*/
template <class T>
class TernarySearchTrie{
  private:
    std::shared_ptr<Node<T>> root_;
    std::shared_ptr<Node<T>> RecursivePut(std::shared_ptr<Node<T>>,\
                                          std::string key,\
                                          T value,
                                          int key_index);
  public:
    TernarySearchTrie() : root_(nullptr) {};
    void Put(std::string key, T value);
    T* Get(std::string key);
};



/**
* @brief helper recursive function to add new data to the trie
*
* @tparam T data type
* @param a_node root of a subtree to insert data in
* @param key key to insert
* @param value value to insert
* @param key_index current position in the key stinrg
*
* @return a subtree with inserted nodes
*/
template <class T>
std::shared_ptr<Node<T>> TernarySearchTrie<T>::RecursivePut(\
                                          std::shared_ptr<Node<T>> a_node,\
                                          std::string key,\
                                          T value,\
                                          int key_index){
  if (a_node == nullptr){
    a_node = std::make_shared<Node<T>>();
    a_node->key_char_ = key[key_index];
  }  
  if (a_node->key_char_ > key[key_index]){
    a_node->left_ = RecursivePut(a_node->left_, key, value, key_index);  
  }
  else if (a_node->key_char_ < key[key_index]){
    a_node->right_ = RecursivePut(a_node->right_, key, value, key_index);  
  }
  else if (key.length() > key_index + 1){
    a_node->middle_ = RecursivePut(a_node->middle_, key, value, key_index + 1);   
  }
  else{
    a_node->value_ = value;  
  }
  return a_node;
}


/**
* @brief insert new data into the trie
* complexity O(L) where L is length of the key
*
* @param key key to insert 
* @param value value to insert
*/
template <class T>
void TernarySearchTrie<T>::Put(std::string key, T value){
  root_ = RecursivePut(root_, key, value, 0);
}

/**
* @brief get data from the trie
*
* @tparam T type of data
* @param key key to search for
*
* @return data assiciated with given key or a nullptr
*/
template <class T>
T* TernarySearchTrie<T>::Get(std::string key){
  std::shared_ptr<Node<T>> current = root_;
  int key_index = 0;
  while(current != nullptr){
    if (current->key_char_ > key[key_index]){
       current = current->left_;
    }
    else if (current->key_char_ < key[key_index]){
      current = current->right_;
    }
    else if(key_index + 1 < key.length()){
      current = current->middle_;
      key_index += 1;
    }
    else{
      return &(current->value_);  
    }
  }
  return nullptr;
}


#endif //  ALGOS_TERNARY_SEARCH_TRIES_H_
