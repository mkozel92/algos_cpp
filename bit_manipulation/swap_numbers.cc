#include "swap_numbers.h"

/**
 * @brief swap numbers withot temp variable
 *
 * @param a first number
 * @param b second number
 */
void SwapNumbers(int *a, int *b){
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

