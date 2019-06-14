#include<string>
#include"brute_force_search.h"

/**
* @brief find position of patterin in a given string
* complexity O(MN)
*
* @param a_string a string to search in
* @param pattern pattern to search for
*
* @return position of the pattern in the given string or -1
*/
int BruteForceSearch(const std::string& a_string, const  std::string& pattern){
  int pattern_length = pattern.length();  
  int string_length = a_string.length();

  for(int i = 0; i < string_length - pattern_length + 1; i++){
    int current_match = 0;
    for (int j = 0; j < pattern_length; j++){
      if(pattern[j] != a_string[j+i])
         break;
      current_match++;
    }
    if(current_match == pattern_length)
      return i;
  }
  return -1;
}
