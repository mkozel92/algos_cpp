#ifndef ALGOS_SORT_SELECTION_SORT_H_
#define ALGOS_SORT_SELECTION_SORT_H_

#include<vector>
#include"sort_utils.h"
#include<iostream>


/**
* @brief performs inplace selection sort on a given vector
* complexity O(N^2)...~1/2 N^2
*
* @tparam T
* @param a_vector a_vector sort
*/
template<class T>
void SelectionSort(std::vector<T> *a_vector) {
  for (int i = 0; i < a_vector->size(); i++) {
    int min_index = i;
    for (int j = i + 1; j < a_vector->size(); j++) {
      if (Less((*a_vector)[j], (*a_vector)[min_index])) {
        min_index = j;
      }
    }
    Swap(a_vector, i, min_index);
  }
}

#endif // ALGOS_SORT_SELECTION_SORT_H_
