#ifndef ALGOS_SORT_INSERTION_SORT_H_
#define ALGOS_SORT_INSERTION_SORT_H_

#include"sort_utils.h"
#include<vector>


/**
* @brief performs inplace insertion sort
* complexity O(N^2) ...~1/4 N^2
*
* @tparam T
* @param a_vector vector to sort 
* @param h_distance exchange distance (if bigger then 1 vector will be just patially h-sorted)
* this is used for shell sort
*/
template<class T>
void InsertionSort(std::vector<T> *a_vector, int h_distance) {
  for (int i = 0; i < a_vector->size(); i++) {
    int j = i;
    while (j >= h_distance && Less((*a_vector)[j], (*a_vector)[j - h_distance])) {
      Swap(a_vector, j, j - h_distance);
      j -= h_distance;
    }
  }
}

#endif // ALGOS_SORT_INSERTION_SORT_H_
