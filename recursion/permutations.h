#ifndef ALGOS_RECURSION_PERMUTATION_H_
#define ALGOS_RECURSION_PERMUTATION_H_

#include<unordered_set>
#include<string>
#include<iostream>

/**
* @brief gets all permutations of a given string
* complexity O(N!)
*
* @param a_string input string
*
* @return unordered_set of all unique permutations
*/
std::unordered_set<std::string> get_permutations(std::string a_string){
  if(a_string.length() == 1){
    std::unordered_set<std::string> a_set = {a_string};
    return a_set;
  }  
  std::string tmp;
  std::unordered_set<std::string> a_set;
  for(int i = 0; i < a_string.length(); i++){
    tmp = a_string;
    tmp.erase(i, 1);
    for(std::string s : get_permutations(tmp)){
      a_set.insert(a_string[i] + s);  
    }
  }
  return a_set;
}

#endif // ALGOS_RECURSION_PERMUTATION_H_
