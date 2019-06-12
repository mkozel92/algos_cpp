#include<vector>
#include<string>
#include<iostream>

int GetCharAt(const std::string& a_string, int index){
  if(a_string.length() < index)
    return '\0';
  return a_string[index];
}


void RecursiveRadix(std::vector<std::string> *a_vector,\
                    int radix, int string_index, int sort_from, int sort_to,\
                    std::vector<std::string> *aux_vector){
  
  if(sort_from >= sort_to)
    return;
  std::vector<int> counts(radix + 1, 0);

  for (int j = sort_from; j <= sort_to; j++){
    counts[GetCharAt((*a_vector)[j], string_index)] += 1;  
  }

  for (int i = 1; i < counts.size(); i++){
    counts[i] += counts[i-1];  
  }
  for (int j = sort_from; j <= sort_to; j++){
    (*aux_vector)[counts[GetCharAt((*a_vector)[j], string_index) - 1]\
          + sort_from] = (*a_vector)[j];  
    counts[GetCharAt((*a_vector)[j], string_index) - 1] += 1;  
  }
  
  for (int j = sort_from; j <= sort_to; j++){
    (*a_vector)[j] = (*aux_vector)[j];  
  }
  
  for(int i = 1; i < counts.size(); i++){
    RecursiveRadix(a_vector, radix, string_index + 1,\
                   sort_from + counts[i-1], sort_from + counts[i] - 1,\
                   aux_vector);
  }
}


void MSDRadixSort(std::vector<std::string> *a_vector, int radix){
  std::vector<std::string> aux_vector(a_vector->size());
  RecursiveRadix(a_vector, radix, 0, 0, a_vector->size() - 1, &aux_vector);
}


