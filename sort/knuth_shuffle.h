#include<vector>
#include"sort_utils.h"
#include<random>

using namespace std;

template <class T>
/**
* @brief perform inplace knuth shuffle that produces 
* uniformly random permutation of the vector
* complexity O(N) 
*
* @param a_vector vector to shuffle
*/
void knuth_shuffle(vector<T> *a_vector){
  random_device r;
  default_random_engine e1(r());
  
  for(int i = 1; i<a_vector->size; i++){
    uniform_int_distribution<int> dist(0, i);
    int j = dist(e1);
    my_swap(a_vector, i, j);
  }  
}