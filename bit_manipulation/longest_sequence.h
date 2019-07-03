//
// Created by michal on 03/07/19.
//

#ifndef ALGOS_BIT_MANIPULATION_LONGEST_SEQUENCE_H_
#define ALGOS_BIT_MANIPULATION_LONGEST_SEQUENCE_H_

#include <algorithm>

/**
 * find longest possible consecutive sequence of 1s
 * that can be created by flipping one bit in geven int
 * @param a int to process
 * @return length of the longes sequence
 */
int LongestSequence(int a){
  int current_length = 0;
  int last_length = 0;
  int max = 0;

  for(int i = 0; i < 32; i++) {
    int mask = 1 << i;
    int bit_value = mask & a;
    if (bit_value != 0) {
      current_length++;
    } else {
      mask = 1 << (i + 1);
      if (mask & a){
        last_length = current_length;
      }
      else{
        last_length = 0;
      }
      current_length = 0;
    }
    max = std::max(max, current_length + last_length + 1);
  }
  return max;
}


#endif //ALGOS_BIT_MANIPULATION_LONGEST_SEQUENCE_H_
