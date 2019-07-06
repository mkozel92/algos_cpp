//
// Created by michal on 06/07/19.
//

#ifndef ALGOS_DYNAMIC_PROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H_
#define ALGOS_DYNAMIC_PROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H_

/**
 * compute longest common subsequence of given strings
 * complexity O(MN)
 * @param first_string first string to process
 * @param second_string second string to process
 * @return length of longest common subsequence
 */
int LongestCommonSubsequence(const std::string &first_string,
                             const std::string &second_string) {
  Array2D dp(first_string.length() + 1, second_string.length() + 1);

  for (int i = 0; i <= first_string.length(); i++)
    dp[i][0] = 0;

  for (int i = 0; i <= second_string.length(); i++)
    dp[0][i] = 0;

  for (int column = 1; column <= second_string.length(); column++) {
    for (int row = 1; row <= first_string.length(); row++) {
      if (first_string[row] == second_string[column])
        dp[row][column] = 1 + dp[row - 1][column - 1];
      else
        dp[row][column] = std::max(dp[row][column - 1], dp[row - 1][column]);
    }
  }
  return dp[first_string.length()][second_string.length()];
}

/**
 * comute longest common subsequence
 * complexity O(NM)
 * @param first_string first string to process
 * @param second_string second string to process
 * @param first_index current index in the first string
 * @param second_index current index in the second string
 * @param mem_dict memoized results
 * @return length of longest common subsequence
 */
int LongestCommonSubsequenceRecursive(const std::string &first_string,
                                      const std::string &second_string,
                                      int first_index, int second_index,
                                      std::unordered_map<int, int> *mem_dict) {

  if (first_index < 0 || second_index < 0)
    return 0;

  int current_pair = 0.5 * (first_index + second_index + 2)
                     * (first_index + second_index + 3) + second_index + 1;
  if (mem_dict->find(current_pair) != mem_dict->end())
    return (*mem_dict)[current_pair];

  int match = 0;
  if (first_string[first_index] == second_string[second_index])
    match = 1 + LongestCommonSubsequenceRecursive(first_string, second_string,
                                                  first_index - 1, second_index - 1, mem_dict);

  int left_skip = LongestCommonSubsequenceRecursive(first_string, second_string,
                                                    first_index - 1, second_index, mem_dict);

  int right_skip = LongestCommonSubsequenceRecursive(first_string, second_string,
                                                     first_index, second_index - 1, mem_dict);

  int result = std::max(match, left_skip);
  result = std::max(result, right_skip);

  (*mem_dict)[current_pair] = result;
  return result;
}

#endif //ALGOS_DYNAMIC_PROGRAMMING_LONGEST_COMMON_SUBSEQUENCE_H_
