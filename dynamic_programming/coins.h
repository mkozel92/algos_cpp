#ifndef ALGOS_DYNAMIC_PROGRAMMING_COINs_H_
#define ALGOS_DYNAMIC_PROGRAMMING_COINs_H_

#include <array>
/**
 * @brief compute num of ways to arrive at given change using given coins
 *
 * @tparam N num of different coins
 * @tparam C change to get
 * @param coin_values values of diggerent coins
 *
 * @return num of ways to get given change
 */
template <int N, int C>
int Coins(const std::array<int, N> &coin_values){
  int dp[C + 1];
  for (int i = 0; i <= C; i++)
    dp[i] = 0;
  
  dp[0] = 1;
  for(int c: coin_values){
    for(int j = 0; j <= C; j++){
      if (j - c >= 0)
        dp[j] += dp[j - c];
    }
  }

  return dp[C];
}

#endif // ALGOS_DYNAMIC_PROGRAMMING_COINs_H_
