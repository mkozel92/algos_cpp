#ifndef ALGOS_DATA_STRUCTURES_LINKED_LIST_STACK_H_
#define ALGOS_DATA_STRUCTURES_LINKED_LIST_STACK_H_


#include<iostream>

/**
* @brief Stack implemented using a linked list
*/
template<class T>
class LinkedListStack {
private:

  class Node {
  public:
    explicit Node(T data) : data_(data) {};
    Node *next_;
    T data_;
  };

  Node *first_;

public:
  LinkedListStack() : first_(nullptr) {};

  void Push(T);

  T Pop();

  bool IsEmpty();

  void PrintStack();
};

/**
* @brief push to the top of the stack
* complexity O(1)
*
* @tparam T data type the stack stores
* @param data data to push
*/
template<class T>
void LinkedListStack<T>::Push(T data) {
  Node *new_node = new Node(data);
  new_node->next_ = first_;
  first_ = new_node;
}

/**
* @brief pop from the top of the stack
*
* @tparam T data type tha stack stores
*
* @return value in the top element of the stack
*/
template<class T>
T LinkedListStack<T>::Pop() {
  if (IsEmpty()) {
    throw std::out_of_range("stack underflow");
  }
  Node *first_node = first_;
  first_ = first_node->next_;
  T data = first_node->data_;
  delete first_node;
  return data;
}

/**
* @brief checks if the stack is empty
*
* @tparam T data type the stack stores
*
* @return returns True if the stack is empty
*/
template<class T>
bool LinkedListStack<T>::IsEmpty() {
  return first_ == nullptr;
}

/**
* @brief prints whole stack
*
* @tparam T data type the stack stores
*/
template<class T>
void LinkedListStack<T>::PrintStack() {
  Node *ptr = first_;
  while (ptr != nullptr) {
    std::cout << ptr->data_ << std::endl;
    ptr = ptr->next_;
  }
}

#endif // ALGOS_DATA_STRUCTURES_LINKED_LIST_STACK_H_
