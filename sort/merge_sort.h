#ifndef ALGOS_SORT_MERGE_SORT_H_
#define ALGOS_SORT_MERGE_SORT_H_

#include<vector>
#include<iostream>
#include<string>


/**
* @brief merges two sorted vectors into one sorted vector
* complexity O(N)
*
* @tparam T
* @param a_vector data to merge are in this vector
* @param aux_vector helper vector to keep addition data
* @param low start of first vector to merge
* @param hi end of second vector to merge
* @param mid saparates vectors to merge
*/
template<class T>
void Merge(std::vector<T> *a_vector, std::vector<T> *aux_vector, int low, int hi, int mid) {

  for (int i = low; i <= hi; i++) {
    (*aux_vector)[i] = (*a_vector)[i];
  }

  int i = low;
  int j = mid + 1;
  int k = low;

  while (k <= hi) {
    if (i > mid) {
      (*a_vector)[k++] = (*aux_vector)[j++];
    } else if (j > hi) {
      (*a_vector)[k++] = (*aux_vector)[i++];
    } else if ((*aux_vector)[j] < (*aux_vector)[i]) {
      (*a_vector)[k++] = (*aux_vector)[j++];
    } else {
      (*a_vector)[k++] = (*aux_vector)[i++];
    }
  }
}


/**
* @brief recursive implementation of merge sort
*
* @tparam T
* @param a_vector a vector to sort
* @param aux_vector helper vector to keep additional data while merging
* @param low sort from this index
* @param hi sort to this index
*/
template<class T>
void RecursiveSort(std::vector<T> *a_vector, std::vector<T> *aux_vector, int low, int hi) {

  if (hi <= low) {
    return;
  }

  int mid = (low + hi) / 2;
  RecursiveSort(a_vector, aux_vector, low, mid);
  RecursiveSort(a_vector, aux_vector, mid + 1, hi);
  if ((*a_vector)[mid] <= (*a_vector)[mid + 1]) {
    return;
  }
  Merge(a_vector, aux_vector, low, hi, mid);
}


/**
* @brief iterative implementation of merge sort
*
* @tparam T
* @param a_vector a vector to sort
* @param aux_vector helper vector to keep additional data while merging
* @param low sort from this index
* @param hi sort to this index
*/
template<class T>
void IterativeSort(std::vector<T> *a_vector, std::vector<T> *aux_vector, int hi) {
  for (int sz = 1; sz < a_vector->size(); sz = sz + sz) {
    for (int i = 0; i < a_vector->size(); i += sz + sz) {
      Merge(a_vector, aux_vector, i, std::min(hi, i + 2 * sz - 1), i + sz - 1);
    }
  }
}

/**
* @brief merge sort with recursive and iterative implementations
* complexity O(N log N)
*
* @tparam T
* @param a_vector a vector to sort
* @param implementation wheter to use iterative or recursive implementation
*/
template<class T>
void MergeSort(std::vector<T> *a_vector, const std::string &implementation = "recursive") {
  std::vector<T> aux_vector(a_vector->size());
  if (implementation == "recursive") {
    RecursiveSort(a_vector, &aux_vector, 0, a_vector->size() - 1);
  } else if (implementation == "iterative") {
    IterativeSort(a_vector, &aux_vector, a_vector->size() - 1);
  } else {
    throw std::runtime_error("unknown implementation of merge sort");
  }
}

#endif // ALGOS_SORT_MERGE_SORT_H_
