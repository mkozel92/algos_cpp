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
    explicit Node(T data) : data(data) {};
    Node *next;
    T data;
  };

  Node *first;

public:
  LinkedListStack() { first = nullptr; };

  void push(T);

  T pop();

  bool is_empty();

  void print_stack();
};

/**
* @brief push to the top of the stack
* complexity O(1)
*
* @tparam T data type the stack stores
* @param data data to push
*/
template<class T>
void LinkedListStack<T>::push(T data) {
  Node *new_node = new Node(data);
  new_node->next = first;
  first = new_node;
}

/**
* @brief pop from the top of the stack
*
* @tparam T data type tha stack stores
*
* @return value in the top element of the stack
*/
template<class T>
T LinkedListStack<T>::pop() {
  if (is_empty()) {
    throw std::out_of_range("stack underflow");
  }
  Node *first_node = first;
  first = first_node->next;
  T data_ = first_node->data;
  delete first_node;
  return data_;
}

/**
* @brief checks if the stack is empty
*
* @tparam T data type the stack stores
*
* @return returns True if the stack is empty
*/
template<class T>
bool LinkedListStack<T>::is_empty() {
  return first == nullptr;
}

/**
* @brief prints whole stack
*
* @tparam T data type the stack stores
*/
template<class T>
void LinkedListStack<T>::print_stack() {
  Node *ptr = first;
  while (ptr != nullptr) {
    std::cout << ptr->data << std::endl;
    ptr = ptr->next;
  }
}

#endif // ALGOS_DATA_STRUCTURES_LINKED_LIST_STACK_H_
