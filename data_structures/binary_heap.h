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
  bool (*compare_)(T, T);

  int current_size_;
  std::vector<T> data_;

  void Sink(int);

  void Swim(int);

public:
  explicit BinaryHeap(bool (*compare)(T, T), \
               int capacity = 100) : data_(capacity), \
                                     current_size_(0), \
                                     compare_(compare) {};

  explicit BinaryHeap(int capacity = 100) : data_(capacity), \
                                     current_size_(0), \
                                     compare_([](T a, T b) -> bool { return a > b; })\
 {};

  void Insert(T);

  bool IsEmpty();

  void PrintHeap();

  int Size();

  T Remove();
};


/**
* @brief sink element at index K to maintain heap ordering
*
* @tparam T data type the heap stores
* @param k index of element to sink
*/
template<class T>
void BinaryHeap<T>::Sink(int k) {

  while (2 * k <= current_size_) {
    int _child;
    int left_child = 2 * k;
    int right_child = std::min(2 * k + 1, current_size_);
    if (compare_(data_[left_child], data_[right_child])) {
      _child = left_child;
    } else {
      _child = right_child;
    }

    if (compare_(data_[_child], data_[k])) {
      swap(&data_, _child, k);
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
void BinaryHeap<T>::Swim(int k) {

  while (k > 1) {
    if (compare_(data_[k], data_[k / 2])) {
      swap(&data_, k, k / 2);
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
void BinaryHeap<T>::Insert(T data) {
  current_size_ += 1;
  data_[current_size_] = data;
  Swim(current_size_);
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
T BinaryHeap<T>::Remove() {
  T tmp = data_[1];
  swap(&data_, 1, current_size_);
  current_size_ -= 1;
  Sink(1);
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
bool BinaryHeap<T>::IsEmpty() {
  return current_size_ == 0;
}

/**
* @brief prints contents of the heap
*
* @tparam T data type the heap stores
*/
template<class T>
void BinaryHeap<T>::PrintHeap() {
  for (int i = 1; i <= current_size_; i++) {
    std::cout << data_[i] << " ";
  }
  std::cout << std::endl;
}

/**
 *
 * @tparam T type of data in the heap
 * @return size of the heap
 */
template<class T>
int BinaryHeap<T>::Size() {
  return current_size_;
}


#endif // ALGOS_DATA_STRUCTURES_BINARY_HEAP_H_
