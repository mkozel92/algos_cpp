#ifndef ALGOS_DYNAMIC_PROGRAMMING_TROPLE_STEP_H_
#define ALGOS_DYNAMIC_PROGRAMMING_TROPLE_STEP_H_

#include<array>

template <int N>
int GetPrevious(const std::array<int, N> &an_array, int i){
  if(i < 0)
    return 0;
  return an_array[i];
}


/**
 * @brief get num of ways to climb N steps going 1,2, or 3 steps at time
 *
 * @tparam N num of steps to climb
 *
 * @return num of ways to do so
 */
template <int N>
int TripleStep(){
  std::array<int, N + 1> dp;
  dp[0] = 1;
  for (int i = 1; i <= N; i++){
    int res = 0;
    for(int j = 1; j <= 3; j++)
      res += GetPrevious(dp, i - j);
    dp[i] = res;
  }
  return dp[N]
}


#endif // ALGOS_DYNAMIC_PROGRAMMING_TROPLE_STEP_H_
