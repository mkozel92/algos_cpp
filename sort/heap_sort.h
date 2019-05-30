#include<vector>
#include"sort_utils.h"
#include<iostream>

using namespace std;

/**
* @brief binary heap sink that maintains heap order in given vector
*
* @tparam T data type in the vector
* @param a_vector a vector in which to perform the sink
* @param k index of elemnt to sink
* @param n don't sink beyon this index
*/
template <class T>
void sink(vector<T> *a_vector, int k, int n){
  
  while(2*(k+1) <= n+1){
    int bigger_child;
    int left_child = 2*(k+1) - 1;
    int right_child = min(2*(k+1), n);
    if ((*a_vector)[left_child] < (*a_vector)[right_child]){
      bigger_child = right_child;  
    }
    else{
      bigger_child = left_child;  
    }
    if((*a_vector)[k] < (*a_vector)[bigger_child]){
      my_swap(a_vector, k, bigger_child);
      k = bigger_child;
    }
    else{
      break;  
    }
  }
}



/**
* @brief heap sort implementation
* first the vector is heap sorted and then the biggest elements are pulled from
* the heap and moved to the end of the vector
* complexity O (N log N)
*
* @tparam T data type of the vector
* @param a_vector a vector to sort
*/
template <class T>
void heap_sort(vector<T> *a_vector){
  int vector_size = a_vector->size();
  for(int i = vector_size/2; i >= 0; i--){
    sink(a_vector, i, vector_size - 1);  
  }
  for(int j = 0; j < vector_size; j++){
    my_swap(a_vector, 0, vector_size - 1 - j);
    sink(a_vector, 0, vector_size - 2 - j);
  }
}


