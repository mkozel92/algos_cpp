//
// Created by michal on 05/07/19.
//

#ifndef ALGOS_DYNAMIC_PROGRAMMING_MAX_INDEPENDENT_SET_H_
#define ALGOS_DYNAMIC_PROGRAMMING_MAX_INDEPENDENT_SET_H_

/**
 * compute sum of max independent set using dynamic programming array;
 * independent set is set of non-consecutive elements of given array
 * complexity O(N)
 * @tparam N size of given array
 * @param an_array : array of elements
 * @return sum of max independent set
 */
template<int N>
int MaxIndependentSet(const std::array<int, N> &an_array) {
  std::array<int, N> solution;
  solution[0] = an_array[0];
  solution[1] = std::max(an_array[0], an_array[1]);
  for (int i = 2; i < N; i++) {
    solution[i] = std::max(solution[i - 1], solution[i - 2] + an_array[i]);
  }
  return solution[N - 1];
}

/**
 * recursively compute sum of max independent set using dynamic programming;
 * independent set is set of non-consecutive elements of given array
 * complexity O(N)
 * @tparam N size of given array
 * @param an_array array to process
 * @param index process up to this index in current recursive call
 * @param mem_dict memoized results from previous calls
 * @return sum of max independent set
 */
template<int N>
int MaxIndependentSetRecursive(const std::array<int, N> &an_array, int index,
                               std::unordered_map<int, int> *mem_dict) {
  if (index == 0)
    return an_array[index];

  if (index < 0){
    return 0;
  }

  if (mem_dict->find(index) != mem_dict->end())
    return (*mem_dict)[index];

  int result = std::max(an_array[index] +
                        MaxIndependentSetRecursive<N>(an_array, index - 2, mem_dict),
                        MaxIndependentSetRecursive<N>(an_array, index - 1, mem_dict));
  (*mem_dict)[index] = result;
  return result;
}


#endif //ALGOS_DYNAMIC_PROGRAMMING_MAX_INDEPENDENT_SET_H_
