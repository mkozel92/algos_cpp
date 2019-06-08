#ifndef ALGOS_DATA_STRUCTURES_LINKED_LIST_NODE_H_
#define ALGOS_DATA_STRUCTURES_LINKED_LIST_NODE_H_

template <class T>
class Node{
  public:
    T data;
    Node<T> * next;
    Node(T data) : next(nullptr), data(data) {};
};

#endif // ALGOS_DATA_STRUCTURES_LINKED_LIST_NODE_H_
