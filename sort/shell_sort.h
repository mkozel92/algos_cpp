#ifndef ALGOS_SORT_SHELL_SORT_H_
#define ALGOS_SORT_SHELL_SORT_H_

#include"sort_utils.h"
#include"insertion_sort.h"
#include<vector>


/**
* @brief performs inplace shell sort
* Complexity O(N^(3/2))...in practice runs faster
*
* @tparam T
* @param a_vector vector to sort 
* @param h_vector vector of h distances for insertion sort
*/
template<class T>
void ShellSort(std::vector<T> *a_vector, const std::vector<int> &h_vector) {
  for (int h: h_vector) {
    InsertionSort(a_vector, h);
  }
}

#endif // ALGOS_SORT_SHELL_SORT_H_
