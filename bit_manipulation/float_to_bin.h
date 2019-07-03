//
// Created by michal on 03/07/19.
//

#ifndef ALGOS_BIT_MANIPULATION_FLOAT_TO_BIN_H_
#define ALGOS_BIT_MANIPULATION_FLOAT_TO_BIN_H_

#include <string>
#include <cassert>

/**
 * translate given decimal input to string of bits
 * @param an_input a float < 1
 * @return bit representation of decimal part of given number
 */
std::string FloatToBin(float an_input){
  assert(an_input < 1);
  std::string result;
  for(int i = 0; i < 32; i++){
    an_input *= 2;
    if(an_input > 1){
      result += "1";
      an_input -= 1;
    }
    else{
      result += "0";
    }
  }
  return result;
}


#endif //ALGOS_BIT_MANIPULATION_FLOAT_TO_BIN_H_
