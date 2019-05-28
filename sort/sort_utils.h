#ifndef _SORT_UTILS
#define _SORT_UTILS

#include<vector>

using namespace std;


/**
* @brief elements comparison
*
* @tparam T
* @param p the first element
* @param q the second element
*
* @return True if the first element is strictly smaller
*/
template <class T>
bool my_less(T p, T q){
  return p < q;  
}


/**
* @brief implace swap on a given vector
*
* @tparam T
* @param a_vector vector on which to perform the swap
* @param p first index
* @param q second index
*/
template <class T>
void my_swap(vector<T> *a_vector, int p, int q){
  T tmp = (*a_vector)[p];
  (*a_vector)[p] = (*a_vector)[q];
  (*a_vector)[q] = tmp;
}

#endif
