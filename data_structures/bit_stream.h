//
// Created by michal on 16/06/19.
//

#ifndef ALGOS_DATA_STRUCTURES_BIT_STREAM_H_
#define ALGOS_DATA_STRUCTURES_BIT_STREAM_H_

#include <iostream>
#include <string>
#include <utility>
#include <queue>


/**
 * Class to hold bit representations of data
 */
class BitStream {
private:
  std::queue<bool> buffer_;
public:
  explicit BitStream(const std::string &a_string) {
    for (auto character : a_string)
      WriteByte(character);
  };

  BitStream() = default;

  void WriteByte(const char& a_char);

  void WriteByte(int a_byte);
  void WriteBit(bool a_bit);

  std::string ReadStream();

  char ReadByte();

  bool ReadBit();

  bool PeakBit() const {
    return buffer_.front();
  }

  bool Empty() const {
    return buffer_.empty();
  }

  int Length() const {
    return buffer_.size();
  }
};

#endif //ALGOS_CPP_BIT_STREAM_H
