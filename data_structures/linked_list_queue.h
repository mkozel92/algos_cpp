#ifndef ALGOS_DATA_STRUCTURES_LINKED_LIST_QUEUE_H_
#define ALGOS_DATA_STRUCTURES_LINKED_LIST_QUEUE_H_


#include<iostream>
#include"linked_list_node.h"

template <class T>
class LLIterator{
  private:
    Node<T> *node_ptr;
    LLIterator(Node<T> *node) : node_ptr(node) {};
  public:
    template <class>
    friend class LinkedListQueue;
    LLIterator() : node_ptr(nullptr) {};
    bool operator!= (const LLIterator &itr) const {
      return node_ptr != itr.node_ptr;  
    }

    T& operator* () const {
      return node_ptr->data;  
    }
    
    T& operator-> () const {
      return node_ptr->data;  
    }
    
    LLIterator operator++ (int){
      LLIterator temp = *this;
      node_ptr = node_ptr->next;
      return temp;
    }
};


/**
* @brief Queue implemented using a linked list
*/
template <class T>
class LinkedListQueue{
  private:
    Node<T> *first;
    Node<T> *last;
    
  public:
    LinkedListQueue(){first = nullptr; last = nullptr;};
    void enqueue(T);
    T dequeue();
    bool is_empty();
    void print_queue();
    Node<T>* get_first();
    LLIterator<T> begin();
    LLIterator<T> end();
};

template <class T>
LLIterator<T> LinkedListQueue<T>::begin(){
  return LLIterator<T>(first);  
}

template <class T>
LLIterator<T> LinkedListQueue<T>::end(){
  return LLIterator<T>(last);  
}

/**
* @brief enqueue to the end of the queue
* complexity O(1)
*
* @tparam T data type the queue stores
* @param data data to push
*/
template <class T>
void LinkedListQueue<T>::enqueue(T data){
  Node<T> *new_node = new Node<T>(data);
  new_node->next = nullptr;
  if (is_empty()){
    first = new_node;
    last = new_node;
  }
  else{
    last->next = new_node;
    last = new_node;
  }
}

/**
* @brief dequeue from the beginning of the queue
* complexity O(1)
*
* @tparam T data type the queue store
*
* @return value from the beginning of the queue
*/
template <class T>
T LinkedListQueue<T>::dequeue(){
  if(is_empty()){
    throw std::out_of_range("queue underflow");
  }
  Node<T> *first_node = first;
  first = first_node->next;
  return first_node->data;
}

/**
* @brief checks if the queue is empty
*
* @tparam T data type the queue stores
*
* @return returns True if the queue is empty
*/
template <class T>
bool LinkedListQueue<T>::is_empty(){
  return first == nullptr;  
}

/**
* @brief prints whole queue
*
* @tparam T data type the queue stores
*/
template <class T>
void LinkedListQueue<T>::print_queue(){
  Node<T> *ptr = first;
  while (ptr != nullptr){
    std::cout<<ptr->data<<std::endl;
    ptr = ptr->next;
  }
}

#endif // ALGOS_DATA_STRUCTURES_LINKED_LIST_QUEUE_H_
