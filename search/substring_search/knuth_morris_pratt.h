#ifndef ALGOS_SEARCH_SUBSTRING_SEARCH_KNUTH_MORRIS_PRATT_H_
#define ALGOS_SEARCH_SUBSTRING_SEARCH_KNUTH_MORRIS_PRATT_H_

#include<vector>
#include<string>

void BuildDFA(std::string pattern, std::vector<std::vector<int>>* dfa);

int KnuthMorrisPratt(const std::string& a_string, const std::string& pattern);

#endif //  ALGOS_SEARCH_SUBSTRING_SEARCH_KNUTH_MORRIS_PRATT_H_
