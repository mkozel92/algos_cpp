#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>


/**
 * Function to determine whether a given word is squashable.
 * A word is squashable if it can be reduced to empty string by removing letters from the original string
 * in such a way that every newly created word in the process is in a dictionary of valid words
 *
 * example: a_dictionary = {'hello', 'hell', 'hel', 'hl', 'l'}
 * 'hello' can be reduced to empty string through series of valid words and is therefore squashable
 *
 * complexity: O(N!)
 *
 * @param a_word: the word to examine
 * @param a_dictionary: dictionary of valid words
 * @param mem_dict: memoized solutions
 * @return: whether or not a_word is squashable
			         */
bool is_squashable(std::string a_word, const std::unordered_set<std::string> &dictionary,\
                   std::unordered_map<std::string, bool> *mem_dict){
  
  if(mem_dict->find(a_word) != mem_dict->end()){
    return (*mem_dict)[a_word];
  }  
	
  if (dictionary.find(a_word) == dictionary.end()){
    return false;
  }
  
  std::string tmp;
  for (int i = 0; i < a_word.length(); i++){
    tmp = a_word;
    tmp.erase(i, 1);
    if (is_squashable(tmp, dictionary, mem_dict) || tmp.length() == 0){
      (*mem_dict)[a_word] = true;
      return true;
    }
  }
  (*mem_dict)[a_word] = false;
  return false;
}


