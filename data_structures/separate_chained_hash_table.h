#ifndef ALGOS_DATA_STRUCTURES_SEPARATE_CHAINED_HASH_TABLE_H_
#define ALGOS_DATA_STRUCTURES_SEPARATE_CHAINED_HASH_TABLE_H_

#include<vector>
#include<iostream>
#include<unordered_map>

/**
* @brief hash table implemented using separate chaining
*
* @tparam K type of keys in the table
* @tparam V type of values in the table
*/
template<class K, class V>
class SeparateChainedHashTable {

private:
  class Node {
  public:
    K key_;
    V value_;
    Node *next_;

    Node(K key, V value) : key_(key), value_(value), next_(nullptr) {};
  };

  std::vector<Node *> data_;
  int size_;
public:
  std::hash<K> hasher_;

  explicit SeparateChainedHashTable(int size) : data_(size), size_(size) {};

  void Put(K, V);

  V *Get(K);
};

/**
* @brief insert new key value pair into hash table
* Complexity O(M/N) for unifomly random hash..so basically conastant time
*
* @tparam K type of key 
* @tparam V type of value
* @param key key to insert
* @param value value to insert
*/
template<class K, class V>
void SeparateChainedHashTable<K, V>::Put(K key, V value) {
  int i = std::abs(static_cast<int>(hasher_(key))) % size_;
  if (data_[i] == nullptr) {
    data_[i] = new Node(key, value);
  }

  Node *current = data_[i];
  while (current->next_ != nullptr and current->key_ != key) {
    current = current->next_;
  }
  if (current->key_ == key) {
    current->value_ = value;
  } else {
    current->next_ = new Node(key, value);
  }
}


/**
* @brief returns pointer a value associated with given key
* in the hash table
* Complexity O(N/M) for uniformly random hash
*
* @tparam K type of keys in hash table
* @tparam V type of values in hash table
* @param key key we look for
*
* @return value associated with given key or nullptr
*/
template<class K, class V>
V *SeparateChainedHashTable<K, V>::Get(K key) {
  int i = std::abs(static_cast<int>(hasher_(key))) % size_;
  Node *current = data_[i];
  if (current == nullptr) {
    return nullptr;
  }
  while (current->next_ != nullptr and current->key_ != key) {
    current = current->next_;
  }
  if (current->key_ == key) {
    return &current->value_;
  }
  return nullptr;
}

#endif // ALGOS_DATA_STRUCTURES_SEPARATE_CHAINED_HASH_TABLE_H_
