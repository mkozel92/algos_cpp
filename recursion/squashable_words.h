#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

bool is_squashable(string a_word, unordered_set<string> dictionary){
  
  if (dictionary.find(a_word) == dictionary.end()){
    return false;
  }
  
  string tmp;
  for (int i = 0; i < a_word.length(); i++){
    tmp = a_word;
    tmp.erase(i, 1);
    if (is_squashable(tmp, dictionary) || tmp.length() == 0){
      return true;
    }
  }
  return false;
}


