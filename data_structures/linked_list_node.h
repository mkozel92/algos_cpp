#ifndef LINKED_LIST_NODE
#define LINKED_LIST_NODE

template <class T>
class Node{
  public:
    T data;
    Node<T> * next;
    Node(T data) : next(nullptr), data(data) {};
};

#endif
