#include<vector>
#include<string>
#include<iostream>

void LSDRadixSort(std::vector<std::string> *a_vector, int radix){
  
  std::vector<std::string> aux(a_vector->size());
  int length = (*a_vector)[0].length();
  
  for(int i = length - 1; i >=0; i--){
    
    std::vector<int> counts(radix + 1, 0);

    for (auto a_string: (*a_vector)){
      counts[a_string[i]] += 1;  
    }  
    
    for (int j = 1; j < counts.size(); j++){
      counts[j] += counts[j-1];  
    }
    
    for (auto a_string: (*a_vector)){
      aux[counts[a_string[i] - 1]] = a_string;    
      counts[a_string[i] - 1] += 1;    
    }
    for (int j = 0; j < a_vector->size(); j++){
      (*a_vector)[j] = aux[j];  
    }
  }
}


