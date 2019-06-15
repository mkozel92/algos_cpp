#ifndef ALGOS_DATA_STRUCTURES_BINARY_HEAP_H_
#define ALGOS_DATA_STRUCTURES_BINARY_HEAP_H_


#include<vector>
#include"../sort/sort_utils.h"
#include<iostream>


/**
* @brief implementation of binary heap with fixed size
*
* @tparam T data type that the heap stores
*/
template<class T>
class BinaryHeap {
private:
  bool (*compare)(T, T);

  int current_size;
  std::vector<T> data;

  void sink(int);

  void swim(int);

public:
  explicit BinaryHeap(bool (*compare)(T, T), \
               int capacity = 100) : data(capacity), \
                                     current_size(0), \
                                     compare(compare) {};

  explicit BinaryHeap(int capacity = 100) : data(capacity), \
                                     current_size(0), \
                                     compare([](T a, T b) -> bool { return a > b; })\
 {};

  void insert(T);

  bool is_empty();

  void print_heap();

  T remove();
};


/**
* @brief sink element at index K to maintain heap ordering
*
* @tparam T data type the heap stores
* @param k index of element to sink
*/
template<class T>
void BinaryHeap<T>::sink(int k) {

  while (2 * k <= current_size) {
    int _child;
    int left_child = 2 * k;
    int right_child = std::min(2 * k + 1, current_size);
    if (compare(data[left_child], data[right_child])) {
      _child = left_child;
    } else {
      _child = right_child;
    }

    if (compare(data[_child], data[k])) {
      swap(&data, _child, k);
      k = _child;
    } else {
      break;
    }
  }
}


/**
* @brief swim element at index K to maintain heap ordering
*
* @tparam T data type that the heap stores
* @param k index of the element to swim
*/
template<class T>
void BinaryHeap<T>::swim(int k) {

  while (k > 1) {
    if (compare(data[k], data[k / 2])) {
      swap(&data, k, k / 2);
      k /= 2;
    } else {
      break;
    }
  }
}

/**
* @brief insert new element into the heap
* complexity O(log N)
*
* @tparam T data type the heap stores
* @param d data to insert into the heap
*/
template<class T>
void BinaryHeap<T>::insert(T d) {
  current_size += 1;
  data[current_size] = d;
  swim(current_size);
}

/**
* @brief remove biggest element in the heap
* complexity O(log N)
*
* @tparam T data type of the heap
*
* @return biggest element of the heap
*/
template<class T>
T BinaryHeap<T>::remove() {
  T tmp = data[1];
  swap(&data, 1, current_size);
  current_size -= 1;
  sink(1);
  return tmp;
}

/**
* @brief chcecks of the heap is empty
*
* @tparam T data type the heap stores
*
* @return true if the heap is empty
*/
template<class T>
bool BinaryHeap<T>::is_empty() {
  return current_size == 0;
}

/**
* @brief prints contents of the heap
*
* @tparam T data type the heap stores
*/
template<class T>
void BinaryHeap<T>::print_heap() {
  for (int i = 1; i <= current_size; i++) {
    std::cout << data[i] << " ";
  }
  std::cout << std::endl;
}


#endif // ALGOS_DATA_STRUCTURES_BINARY_HEAP_H_
