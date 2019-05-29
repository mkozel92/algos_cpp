#include<vector>
#include<iostream>
#include<string>

using namespace std;


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
template <class T>
void merge(vector<T> *a_vector, vector<T> *aux_vector, int low, int hi, int mid){
  
  for(int i = low; i <= hi; i++){
      (*aux_vector)[i] = (*a_vector)[i];
  }
  
  int i = low;
  int j = mid + 1;
  int k = low;

  while(k <= hi){
    if(i > mid){
      (*a_vector)[k++] = (*aux_vector)[j++];
    }
    else if(j > hi){
      (*a_vector)[k++] = (*aux_vector)[i++];
    }
    else if((*aux_vector)[j] < (*aux_vector)[i]){
      (*a_vector)[k++] = (*aux_vector)[j++];
    }
    else{
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
template <class T>
void recursive_sort(vector<T> *a_vector, vector<T> *aux_vector, int low, int hi){
  
  if(hi <= low){
    return;
  }

  int mid = (low + hi) / 2;
  recursive_sort(a_vector, aux_vector, low, mid);
  recursive_sort(a_vector, aux_vector, mid + 1, hi);
  if((*a_vector)[mid] <= (*a_vector)[mid + 1]){
    return;  
  }
  merge(a_vector, aux_vector, low, hi, mid);
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
template <class T>
void iterative_sort(vector<T> *a_vector, vector<T> *aux_vector, int low, int hi){
  for(int sz = 1; sz < a_vector->size(); sz = sz+sz){
    for(int i = 0; i < a_vector->size(); i += sz+sz){
      merge(a_vector, aux_vector, i, min(hi, i+2*sz-1), i+sz-1);    
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
template <class T>
void merge_sort(vector<T> *a_vector, string implementation="recursive"){
  vector<T> aux_vector(a_vector->size());  
  if (implementation == "recursive"){
    recursive_sort(a_vector, &aux_vector, 0, a_vector->size()-1);
  }
  else if (implementation == "iterative"){ 
    iterative_sort(a_vector, &aux_vector, 0, a_vector->size()-1);
  }
  else{
    throw runtime_error("unknown implemntation of merge sort");
  }
}

