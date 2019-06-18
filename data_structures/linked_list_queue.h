#ifndef ALGOS_DATA_STRUCTURES_LINKED_LIST_QUEUE_H_
#define ALGOS_DATA_STRUCTURES_LINKED_LIST_QUEUE_H_


#include<iostream>
#include"linked_list_node.h"

template<class T>
class LLIterator {
private:
  Node<T> *NodePtr;

  explicit LLIterator(Node<T> *node) : NodePtr(node) {};
public:
  template<class>
  friend
  class LinkedListQueue;

  LLIterator() : NodePtr(nullptr) {};

  bool operator!=(const LLIterator &itr) const {
    return NodePtr != itr.NodePtr;
  }

  T &operator*() const {
    return NodePtr->data_;
  }

  T &operator->() const {
    return NodePtr->data_;
  }

  const LLIterator operator++(int) {
    LLIterator temp = *this;
    NodePtr = NodePtr->next_;
    return temp;
  }
};


/**
* @brief Queue implemented using a linked list
*/
template<class T>
class LinkedListQueue {
private:
  Node<T> *first_;
  Node<T> *last_;

public:
  LinkedListQueue() {
    first_ = nullptr;
    last_ = nullptr;
  };

  void Enqueue(T);

  T Dequeue();

  bool IsEmpty();

  void PrintQueue();

  LLIterator<T> begin();

  LLIterator<T> end();

  ~LinkedListQueue();
};

template<class T>
LinkedListQueue<T>::~LinkedListQueue() {
  Node<T> *current = first_;
  Node<T> *tmp;
  while (current != nullptr) {
    tmp = current;
    current = current->next_;
    delete tmp;
  }
}

template<class T>
LLIterator<T> LinkedListQueue<T>::begin() {
  return LLIterator<T>(first_);
}

template<class T>
LLIterator<T> LinkedListQueue<T>::end() {
  return LLIterator<T>(last_);
}

/**
* @brief enqueue to the end of the queue
* complexity O(1)
*
* @tparam T data type the queue stores
* @param data data to push
*/
template<class T>
void LinkedListQueue<T>::Enqueue(T data) {
  auto new_node = new Node<T>(data);
  new_node->next_ = nullptr;
  if (IsEmpty()) {
    first_ = new_node;
    last_ = new_node;
  } else {
    last_->next_ = new_node;
    last_ = new_node;
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
template<class T>
T LinkedListQueue<T>::Dequeue() {
  if (IsEmpty()) {
    throw std::out_of_range("queue underflow");
  }
  Node<T> *first_node = first_;
  first_ = first_node->next_;
  return first_node->data_;
}

/**
* @brief checks if the queue is empty
*
* @tparam T data type the queue stores
*
* @return returns True if the queue is empty
*/
template<class T>
bool LinkedListQueue<T>::IsEmpty() {
  return first_ == nullptr;
}

/**
* @brief prints whole queue
*
* @tparam T data type the queue stores
*/
template<class T>
void LinkedListQueue<T>::PrintQueue() {
  Node<T> *ptr = first_;
  while (ptr != nullptr) {
    std::cout << ptr->data_ << std::endl;
    ptr = ptr->next_;
  }
}

#endif // ALGOS_DATA_STRUCTURES_LINKED_LIST_QUEUE_H_
