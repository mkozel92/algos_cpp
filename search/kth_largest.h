#ifndef ALGOS_SEARCH_KTH_LARGEST_H_
#define ALGOS_SEARCH_KTH_LARGEST_H_

#include<vector>
#include<utility>
#include"../sort/knuth_shuffle.h"
#include"../sort/quick_sort.h"

/**
* @brief finds kth larges element in a vector using 
* quick sort partitioning
* complexity O(N log N) but with shuffle basically runs in linear time
*
* @tparam T
* @param a_vector vector to search 
* @param k find kth largest elemnt
*
* @return value of the kth larges elemnt
*/
template <class T>
int quick_find(std::vector<T> *a_vector, int k){
  
  knuth_shuffle(a_vector);

  int low = 0;
  int hi = a_vector->size() - 1;

  while (low <= hi){
      
    int j = partition(a_vector, low, hi);

    if(j < k){
      low = j + 1;
    }
    else if (j > k){
      hi = j - 1;  
    }
    else{
      return (*a_vector)[k];    
    }
  }
  return (*a_vector)[k];
}


/**
* @brief three way partitioning
* the vector is separated into 3 parts, bigger, equal and lesser than
* partitioning element
*
* @tparam T data type in the vector
* @param a_vector vector to partition
* @param to_ partition to this index
* @param from_ partition from this index
*
* @return pair of lt, gt separators
*/
template <class T>
std::pair<int, int> three_way_partition(std::vector<T> *a_vector,\
                                       int from_, int to_){
  int lt = from_;
  int i = from_;
  int gt = to_;
  T v = (*a_vector)[from_];

  while(i <= gt){
    if((*a_vector)[i] < v){
      swap(a_vector, i, lt);
      i++;
      lt++;
    }  
    else if((*a_vector)[i] > v){
      swap(a_vector, i, gt);
      gt--;  
    }
    else{
      i++;  
    }
  }
  std::pair<int, int> p = std::make_pair(lt, gt);
  return p;
}


/**
* @brief finds kth larges element in a vector using 
* quick sort three way partitioning
* complexity O(N log N) but with shuffle basically runs in linear time
*
* @tparam T
* @param a_vector vector to search 
* @param k find kth largest elemnt
*
* @return value of the kth larges elemnt
*/
template <class T>
T quick_find_three(std::vector<T> *a_vector, int k){
  
  knuth_shuffle(a_vector);
  int low = 0;
  int high = a_vector->size() - 1;
  
  while(low <= high){
    
    std::pair<int, int> p = three_way_partition(a_vector, low, high);

    if(k < p.first){
      high = p.first - 1;  
    }
    else if (k > p.second){
      low = p.second + 1;  
    }
    else{
      return (*a_vector)[p.first];  
    }
  }
  return (*a_vector)[low];
}

#endif // ALGOS_SEARCH_KTH_LARGEST_H_
