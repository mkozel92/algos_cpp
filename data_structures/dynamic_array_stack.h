//
// Created by michal on 17/06/19.
//

#ifndef ALGOS_DATA_STRUCTURES_DYNAMIC_ARRAY_STACK_H_
#define ALGOS_DATA_STRUCTURES_DYNAMIC_ARRAY_STACK_H_

#include<memory>
#include<array>
#include<stdio.h>
#include<cstring>
#include<iostream>

/**
 * DYnamic array stack
 * @tparam T data type store in the stack
 */
template<class T>
class DynamicArrayStack {
private:
  T *array_;
  int current_capacity_;
  int current_size_;
public:
  DynamicArrayStack(int initial_capacity = 10)
      : current_capacity_(initial_capacity), current_size_(0) {
    array_ = new T[current_capacity_];

  }

  T &operator[](unsigned int index);

  void Push(T data);

  T Pop();

  int GetSize();

  int GetCapacity();

};

/**
 * access operator
 * @tparam T data type in the stack
 * @param index index to access
 * @return data on given index
 */
template<class T>
T &DynamicArrayStack<T>::operator[](unsigned int index) {
  return array_[index];
}

/**
 * push data to the stack
 * amortized constant complexity
 * O(N) whin resizing
 *
 * @tparam T data type in the stack
 * @param data data to push
 */
template<class T>
void DynamicArrayStack<T>::Push(T data) {
  if (current_size_ >= current_capacity_) {
    current_capacity_ *= 2;
    T *tmp = new T[current_capacity_];
    memcpy(tmp, array_, (current_size_ * sizeof(T)));
    delete array_;
    array_ = tmp;
  }
  array_[current_size_] = data;
  current_size_ += 1;
}

/**
 * pop data from the stack
 * amortized constant complexity
 * O(N) when resizing
 * @tparam T data type on the stack
 * @return data from the top of the stack
 */
template<class T>
T DynamicArrayStack<T>::Pop() {
  current_size_ -= 1;
  T data = array_[current_size_];
  if (current_size_ <= current_capacity_ / 4) {
    current_capacity_ /= 2;
    T *tmp = new T[current_capacity_];
    memcpy(tmp, array_, (current_size_ * sizeof(T)));
    delete array_;
    array_ = tmp;
  }
  return data;
}

/**
 *
 * @return size of the stack
 */
template<class T>
int DynamicArrayStack<T>::GetSize() {
  return current_size_;
}

/**
 *
 * @return current capacity of the array storing the data on the stack
 */
template<class T>
int DynamicArrayStack<T>::GetCapacity() {
  return current_capacity_;
}

#endif //ALGOS_DATA_STRUCTURES_DYNAMIC_ARRAY_STACK_H_
