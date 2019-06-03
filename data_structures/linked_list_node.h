

template <class T>
class Node{
  public:
    T data;
    Node<T> * next;
    Node(T data) : next(nullptr), data(data) {};
};
