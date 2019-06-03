#include<vector>
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
