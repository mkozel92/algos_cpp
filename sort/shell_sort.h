#include"sort_utils.h"
#include"insertion_sort.h"
#include<vector>

using namespace std;


/**
* @brief performs inplace shell sort
* Complexity O(N^(3/2))...in practice runs faster
*
* @tparam T
* @param a_vector vector to sort 
* @param h_vector vector of h distances for insertion sort
*/
template <class T>
void shell_sort(vector<T> *a_vector, const vector<int> &h_vector){
  for(int h: h_vector){
    insertion_sort(a_vector, h);
  }
}