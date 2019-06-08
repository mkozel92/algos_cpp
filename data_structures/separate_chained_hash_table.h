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
template <class K, class V>
class SeparateChainedHashTable{
  
  private:
    class Node{
      public:
        K key;
        V value;
        Node* next;
        Node(K key, V value): key(key), value(value), next(nullptr) {};
      };  
      
      std::vector<Node*> data;
      int size;   
    public:
      std::hash<K> hasher;
      SeparateChainedHashTable(int size) : data(size), size(size) {};
      void put(K, V);
      V *get(K);
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
template <class K, class V>
void SeparateChainedHashTable<K, V>::put(K key, V value){ 
    int i = std::abs(static_cast<int>(hasher(key))) % size;
    if (data[i] == nullptr){
      data[i] = new Node(key, value); 
    }
    
    Node *current = data[i];
    while(current->next != nullptr and current->key != key){
      current = current->next;  
    }
    if(current->key == key){
      current->value = value;
    }
    else{
      current->next = new Node(key, value);
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
template <class K, class V>
V *SeparateChainedHashTable<K, V>::get(K key){
    int i = std::abs(static_cast<int>(hasher(key))) % size;
    Node *current = data[i];
    if (current == nullptr){
      return nullptr;  
    }
    while(current->next != nullptr and current->key != key){
      current = current->next;  
    }
    if(current->key == key){
      return &current->value;
    } 
}

#endif // ALGOS_DATA_STRUCTURES_SEPARATE_CHAINED_HASH_TABLE_H_
