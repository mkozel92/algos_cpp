#include<string>
#include<vector>
#include"knuth_morris_pratt.h"

/**
* @brief build deterministic finite automata for substring search
* complexity O(MR) r is radix and m is length of pattern
*
* @param pattern pattern to build dfa for
* @param dfa vector to hold dfs
*/
void BuildDFA(std::string pattern, std::vector<std::vector<int>> *dfa) {
  const int pattern_length = pattern.length();

  (*dfa)[pattern[0]][0] = 1;
  int current_state = 1;
  int delayed_state = 0;
  while (current_state < pattern_length) {
    for (int i = 0; i < 256; i++) {
      (*dfa)[i][current_state] = (*dfa)[i][delayed_state];
    }
    (*dfa)[pattern[current_state]][current_state] = current_state + 1;
    current_state++;
    delayed_state = (*dfa)[pattern[current_state]][delayed_state];
  }
}


/**
* @brief KMP algo to search for substring 
* comlexity O(N) for substring search and O(MR) to build dfa
*
* @param a_string a string to search in
* @param pattern pattern to search for
*
* @return position of pattern in the string
*/
int KnuthMorrisPratt(const std::string &a_string, const std::string &pattern) {

  const int string_length = a_string.length();
  const int pattern_length = pattern.length();

  std::vector<std::vector<int>> \
 dfa(256, std::vector<int>(pattern_length + 1, 0));
  BuildDFA(pattern, &dfa);

  int i = 0;
  int j = 0;
  while (i < string_length && j < pattern_length) {
    j = dfa[a_string[i]][j];
    i++;
  }
  if (j == pattern_length) {
    return i - j;
  }
  return -1;
}
