#ifndef ALGOS_SORT_QUICK_SORT_H_
#define ALGOS_SORT_QUICK_SORT_H_

#include<vector>
#include<string>
#include<iostream>
#include"sort_utils.h"
#include"knuth_shuffle.h"

template<class T>
/**
* @brief partitioning for quick sort
*
* @param a_vector vector to partition
* @param low partition from this index
* @param hi partition to this index
*
*/
int Partition(std::vector<T> *a_vector, int low, int hi) {

  int i = low + 1;
  int j = hi;

  while (j >= i) {

    while ((*a_vector)[low] > (*a_vector)[i]) {
      i++;
      if (i > hi) {
        break;
      }
    }

    while ((*a_vector)[low] < (*a_vector)[j]) {
      j--;
    }
    if (i >= j) {
      break;
    }
    Swap(a_vector, i, j);
  }
  Swap(a_vector, low, j);
  return j;
}


/**
* @brief recursive implementation a quick sort
*
* @tparam T
* @param a_vector vector to sort
* @param low sort from this index
* @param hi sort to this index
*/
template<class T>
void RecursiveSort(std::vector<T> *a_vector, int low, int hi) {

  if (hi <= low) {
    return;
  }
  int part = Partition(a_vector, low, hi);
  RecursiveSort(a_vector, low, part - 1);
  RecursiveSort(a_vector, part + 1, hi);
}


/**
* @brief recursive implementation of three way version of quick sort
*
* @tparam T
* @param a_vector a vector to sort
* @param low sort from this index
* @param hi sort to this index
*/
template<class T>
void ThreeWaySort(std::vector<T> *a_vector, int low, int hi) {

  if (hi <= low) {
    return;
  }
  int lt = low;
  int gt = hi;
  T v = (*a_vector)[low];
  int i = low;

  while (i <= gt) {
    if ((*a_vector)[i] < v) {
      Swap(a_vector, lt, i);
      i++;
      lt++;
    } else if ((*a_vector)[i] > v) {
      Swap(a_vector, gt, i);
      gt--;
    } else {
      i++;
    }

  }
  ThreeWaySort(a_vector, low, lt - 1);
  ThreeWaySort(a_vector, gt + 1, hi);
}


/**
* @brief quick sort with basic and three way implementations
* complexity O(N^2) but random shuffling basically ensures O(N log N)
* three way version ensures N log N with duplicate keys and 
* runs basically linear on lists with just few distinct keys
*
* @tparam T
* @param a_vector vector to sort 
* @param implementation which inplemntation to use (three_way, basic)
*/
template<class T>
void QuickSort(std::vector<T> *a_vector, const std::string &implementation = "basic") {
  KnuthShuffle(a_vector);
  if (implementation == "basic") {
    RecursiveSort(a_vector, 0, a_vector->size() - 1);
  } else if (implementation == "three_way") {
    ThreeWaySort(a_vector, 0, a_vector->size() - 1);
  } else {
    throw std::runtime_error("unknown quick sort implementation");
  }
}

#endif // ALGOS_SORT_QUICK_SORT_H_
