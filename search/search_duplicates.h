#ifndef ALGOS_SEARCH_SEARCH_DUPLICATES_H_
#define ALGOS_SEARCH_SEARCH_DUPLICATES_H_

#include <unordered_set>
#include <array>
#include "../data_structures/bit_array.h"
#include <iostream>

/**
 * @brief find duplicates in list of ints with values up to 32000
 *
 * @tparam N size of array with ints
 * @param an_array array with ints
 *
 * @return set of duplicates
 */
template <int N>
std::unordered_set<int> SearchDuplicates(const std::array<int, N> &an_array){
  BitArray<32000> a_bit_array;
  std::unordered_set<int> duplicates;
  for (auto element: an_array){
    if(a_bit_array.GetBit(element))
      duplicates.insert(element);
    a_bit_array.SetBit(element, true);
  }
  return duplicates;
}

#endif // ALGOS_SEARCH_SEARCH_DUPLICATES_H_
