//
// Created by michal on 01/07/19.
//

#ifndef ALGOS_BIT_MANIPULATION_INSERT_H_
#define ALGOS_BIT_MANIPULATION_INSERT_H_

/**
 * insert given integer b in to integer a
 * between from and to indices in their binary representation
 *
 * example a 1111011111111
 * b = 101
 * from = 2
 * to = 5
 * result 1111011 0101 11
 *
 * @param a first integer
 * @param b second integer
 * @param from index
 * @param to index
 * @return result as int
 */
int insert(int a, int b, int from, int to) {
  int mask = -1;
  mask <<= to;
  mask |= (2 ^ from - 1);
  a &= mask;
  b <<= from;
  return a | (b);
}

#endif //ALGOS_BIT_MANIPULATION_INSERT_H_
