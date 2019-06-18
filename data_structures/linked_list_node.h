#ifndef ALGOS_DATA_STRUCTURES_LINKED_LIST_NODE_H_
#define ALGOS_DATA_STRUCTURES_LINKED_LIST_NODE_H_

template<class T>
class Node {
public:
  T data_;
  Node<T> *next_;

  explicit Node(T data) : next_(nullptr), data_(data) {};
};

#endif // ALGOS_DATA_STRUCTURES_LINKED_LIST_NODE_H_
