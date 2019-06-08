#ifndef ALGOS_SEARCH_BINARY_SEARCH_H_
#define ALGOS_SEARCH_BINARY_SEARCH_H_

#include<iostream>
#include<vector>


/**
* @brief binary search that looks for and elemnt in an sorted array 
* by halving the array
*
*
* @param a_vector vector of sorted intigers
* @param to_search elemnt to search for
*
* @return index of the elemnt to search or -1 if this element is not present
*/
int my_binary_search(const std::vector<int>& a_vector, int to_search){
  int low = 0;
  int hi = a_vector.size() - 1;
  
  while(low <= hi){
    int mid = (hi + low) / 2;
    if(to_search < a_vector[mid]){
      hi = mid - 1;  
    }
    else if(to_search > a_vector[mid]){
      low = mid + 1;  
    }
    else{
      return mid;
    }
  }
  return -1;
}



/**
* @brief recursive implementation of binary search
* complexity O( log N)
*
* @param a_vector a vector to search
* @param to_searh element to search for
* @param from_ search from this index
* @param to_ search to this index
*
* @return index of the element or -1
*/
int recursive_binary_search(const std::vector<int> &a_vector,\
                            int to_search, int from_, int to_){
  if(from_ > to_){
    return -1;
  }  
  int mid = from_ + (to_ - from_) / 2;

  if (a_vector[mid] > to_search){
    return recursive_binary_search(a_vector, to_search, from_, mid - 1);  
  }
  else if (a_vector[mid] < to_search){
    return recursive_binary_search(a_vector, to_search, mid + 1, to_);  
  }
  else{
    return mid;  
  }
}

#endif // ALGOS_SEARCH_BINARY_SEARCH_H_
