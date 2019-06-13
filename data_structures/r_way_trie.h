#ifndef ALGOS_DATA_STRUCTURES_R_WAY_TRIE_H_
#define ALGOS_DATA_STRUCTURES_R_WAY_TRIE_H_

#include<string>
#include<vector>
#include<memory>
#include<iostream>

namespace trie{
template <class T>
class Node{
  public:
    std::vector<std::shared_ptr<Node>> next_;
    T value_;
    Node(int radix) : next_(radix, nullptr) {};
};


template <class T>
class RWayTrie{
  private:
    std::shared_ptr<Node<T>> RecursivePut(std::shared_ptr<Node<T>> a_node,\
                                          std::string key,\
                                          T value, int string_index);
    const int radix_;
  public:
    std::shared_ptr<Node<T>> root_;
    RWayTrie(int radix) :\
        radix_(radix), root_(std::make_shared<Node<T>>(radix)) {};
    void Put(std::string key, T value);
    T* Get(std::string key);
};

template <class T>
void RWayTrie<T>::Put(std::string key, T value){
  root_->next_[key[0]] = RecursivePut(root_->next_[key[0]], key, value, 0);  
}


template <class T>
std::shared_ptr<Node<T>> RWayTrie<T>::RecursivePut(std::shared_ptr<Node<T>> a_node,\
                                                   std::string key,\
                                                   T value, int string_index){
  
  if (a_node == nullptr){
    a_node = std::make_shared<Node<T>>(radix_);
  }
  string_index += 1;
  if(string_index >= key.length()){
    a_node->value_ = value;
    return a_node;
  }
  else{
    a_node->next_[key[string_index]] = RecursivePut(a_node->next_[key[string_index]], key,\
                 value, string_index);
  }
  return a_node;
}


template <class T>
T* RWayTrie<T>::Get(std::string key){
  std::shared_ptr<Node<T>> crnt = root_;
  int key_index = 0;
  while (crnt != nullptr){
    if (key_index == key.length()){
      return &(crnt->value_);
    }
    crnt = crnt->next_[key[key_index]];
    key_index++;
  }
  return nullptr;
}

} // trie

#endif //  ALGOS_DATA_STRUCTURES_R_WAY_TRIE_H_
