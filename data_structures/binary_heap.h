#include<vector>
#include"../sort/sort_utils.h"
#include<iostream>


/**
* @brief implementation of binary heap with fixed size
*
* @tparam T data type that the heap stores
*/
template <class T>
class MaxHeap{
  private:
    int current_size;
    std::vector<T> data;
    void sink(int);
    void swim(int);
  public:
    MaxHeap(int capacity = 100) : data(capacity), current_size(0) {};
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
template <class T>
void MaxHeap<T>::sink(int k){
  
  while(2*k <= current_size){
    int bigger_child;
    int left_child = 2*k;
    int right_child = std::min(2*k + 1, current_size);
    if(data[left_child] > data[right_child]){
      bigger_child = left_child;  
    }
    else{
      bigger_child = right_child;  
    }
    
    if(data[bigger_child] > data[k]){
      swap(&data, bigger_child, k);
      k = bigger_child;
    }
    else{
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
template <class T>
void MaxHeap<T>::swim(int k){
  
  while(k > 1){
    if(data[k] > data[k/2]){
      swap(&data, k, k/2);
      k /= 2;
    }
    else{
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
template <class T>
void MaxHeap<T>::insert(T d){
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
template <class T>
T MaxHeap<T>::remove(){
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
template <class T>
bool MaxHeap<T>::is_empty(){
  return current_size == 0;  
}

/**
* @brief prints contents of the heap
*
* @tparam T data type the heap stores
*/
template <class T>
void MaxHeap<T>::print_heap(){
  for (int i = 1; i<= current_size; i++){
    std::cout<<data[i]<<" ";
  }  
  std::cout<<std::endl;
}

