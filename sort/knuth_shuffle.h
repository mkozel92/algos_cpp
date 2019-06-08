#ifndef ALGOS_SORT_KNUTH_SHUFFLE_H_
#define ALGOS_SORT_KNUTH_SHUFFLE_H_

#include<vector>
#include"sort_utils.h"
#include<random>
#include<iostream>

template <class T>
/**
* @brief perform inplace knuth shuffle that produces 
* uniformly random permutation of the vector
* complexity O(N) 
*
* @param a_vector vector to shuffle
*/
void knuth_shuffle(std::vector<T> *a_vector){
  std::random_device r;
  std::default_random_engine e1(r());
  
  for(int i = 1; i<a_vector->size(); i++){
    std::uniform_int_distribution<int> dist(0, i);
    int j = dist(e1);
    swap(a_vector, i, j);
  }  
}

#endif // ALGOS_SORT_KNUTH_SHUFFLE_H_
