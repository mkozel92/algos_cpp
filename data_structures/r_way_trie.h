#ifndef ALGOS_DATA_STRUCTURES_R_WAY_TRIE_H_
#define ALGOS_DATA_STRUCTURES_R_WAY_TRIE_H_

#include<string>
#include<vector>
#include<memory>
#include<iostream>

namespace trie {
/**
* @brief Node of a r way trie
*
* @tparam T data type in the trie
*/
template<class T>
class Node {
public:
  std::vector<std::shared_ptr<Node>> next_;
  T value_;

  explicit Node(int radix) : next_(radix, nullptr) {};
};


/**
* @brief implementation of a r way trie
*
* @tparam T data type to store in the trie
*/
template<class T>
class RWayTrie {
private:
  std::shared_ptr<Node<T>> RecursivePut(std::shared_ptr<Node<T>> a_node, \
                                          std::string key, \
                                          T value, int string_index);

  const int radix_;
public:
  std::shared_ptr<Node<T>> root_;

  explicit RWayTrie(int radix) : \
        radix_(radix), root_(std::make_shared<Node<T>>(radix)) {};

  void Put(std::string key, T value);

  T *Get(std::string key);
};

/**
* @brief put new data in the trie
* complexity O(L) where L is the length of key
*
* @tparam T data type 
* @param key key to insert 
* @param value value to insert
*/
template<class T>
void RWayTrie<T>::Put(std::string key, T value) {
  root_->next_[key[0]] = RecursivePut(root_->next_[key[0]], key, value, 0);
}


/**
* @brief recursive helper function to insert new data
*
* @tparam T type of data
* @param a_node root of subtree to insert to
* @param key key to insert
* @param value value to insert
* @param string_index current position in out key
*
* @return subtree with new nodes inserted
*/
template<class T>
std::shared_ptr<Node<T>> RWayTrie<T>::RecursivePut(std::shared_ptr<Node<T>> a_node, \
                                                   std::string key, \
                                                   T value, int string_index) {

  if (a_node == nullptr) {
    a_node = std::make_shared<Node<T>>(radix_);
  }
  string_index += 1;
  if (string_index >= key.length()) {
    a_node->value_ = value;
    return a_node;
  } else {
    a_node->next_[key[string_index]] = RecursivePut(a_node->next_[key[string_index]], key, \
                 value, string_index);
  }
  return a_node;
}


/**
* @brief get data from the trie
* complexity O(L) for search hit and sub liear for search miss
*
* @tparam T type of data
* @param key key to search for
*
* @return value assiciated with given key or nullptr
*/
template<class T>
T *RWayTrie<T>::Get(std::string key) {
  std::shared_ptr<Node<T>> current = root_;
  int key_index = 0;
  while (current != nullptr) {
    if (key_index == key.length()) {
      return &(current->value_);
    }
    current = current->next_[key[key_index]];
    key_index++;
  }
  return nullptr;
}

} // trie

#endif //  ALGOS_DATA_STRUCTURES_R_WAY_TRIE_H_
