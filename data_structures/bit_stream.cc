//
// Created by michal on 16/06/19.
//

#include "bit_stream.h"

void BitStream::WriteByte(const char &a_char) {
  for (int i = 1; i < 256; i *= 2)
    buffer_.push((a_char & i));
}

void BitStream::WriteByte(int a_byte) {
  for (int i = 0; i < 8; i++) {
    bool bit = a_byte % 2;
    a_byte /= 2;
    buffer_.push(bit);
  }
}

void BitStream::WriteBit(bool a_bit) {
  buffer_.push(a_bit);
}

std::string BitStream::ReadStream() {
  std::string a_string;
  while (!this->Empty()){
    a_string += ReadByte();
  }
  return a_string;
}

char BitStream::ReadByte() {
  char byte = 0;
  for (int i = 1; i < 256; i *= 2){
    if (ReadBit())
      byte += i;
  }
  return byte;
}

bool BitStream::ReadBit() {
  bool a_bit = buffer_.front();
  buffer_.pop();
  return a_bit;
}

