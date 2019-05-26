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

using namespace std;

int my_binary_search(const vector<int>& a_vector, int to_search){
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

