//
// Created by michal on 03/07/19.
//

#ifndef ALGOS_BIT_MANIPULATION_CONVERSION_H_
#define ALGOS_BIT_MANIPULATION_CONVERSION_H_

/**
 * computes number of bits that needs to be flipped to convert int a to int b
 * @param a first integer
 * @param b second integer
 * @return number of required bit flips
 */
int Conversion(int a, int b){
  int c = a ^ b;
  int count = 0;
  while(c != 0){
    count++;
    c &= c - 1;
  }
  return count;
}


#endif //ALGOS_BIT_MANIPULATION_CONVERSION_H_
