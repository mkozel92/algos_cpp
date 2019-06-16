//
// Created by michal on 16/06/19.
//

#include "run_length.h"
#include "../data_structures/bit_stream.h"


int Count(BitStream* bit_stream, int max_count, bool which_bit){
  int count = 0;
  while (!bit_stream->Empty() && count < max_count){
    if(bit_stream->PeakBit() != which_bit)
      break;
    count++;
    bit_stream->ReadBit();
  }
  return count;
}


BitStream compress(BitStream* bit_stream){
  bool which_bit = true;
  BitStream compressed;
  int count;
  while(!bit_stream->Empty()){
    count = Count(bit_stream, 256, which_bit);
    compressed.WriteByte(count);
    which_bit = !which_bit;
  }
  return compressed;
}

BitStream expand(BitStream* bit_stream){
  bool which_bit = true;
  BitStream expanded;
  int count;
  while(!bit_stream->Empty()){
    count = (int)bit_stream->ReadByte();
    while(count) {
      expanded.WriteBit(which_bit);
      count--;
    }
    which_bit = !which_bit;
  }
  return expanded;
}

