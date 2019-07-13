#ifndef _ALGOS_DATA_STRUCTURES_BIT_ARRAY_H_
#define _ALGOS_DATA_STRUCTURES_BIT_ARRAY_H_

/**
 * @brief memory efficient array represented by bit
 * we can set and get bit values from given locations
 *
 * @tparam N size of the array
 */
template <int N>
class BitArray{
  public:
    int buffer_[N];
    BitArray(){
      for (int i = 0; i< N; i++)
        buffer_[i] = 0;
    }
  bool GetBit(int i);
  void SetBit(int i, bool value);
};

/**
 * @brief got value of the bit at given postion
 *
 * @tparam N size of bir array
 * @param i index to get
 *
 * @return value of bit at given index
 */
template <int N>
bool BitArray<N>::GetBit(int i){
  int int_position = i >> 5;
  int bit_position = i % 8;
  return buffer_[int_position] & (1 << bit_position);
}

/**
 * @brief set bit at given index
 *
 * @tparam N size of bit array
 * @param i index to set
 * @param value to set
 */
template <int N>
void BitArray<N>::SetBit(int i, bool value){
  int int_position = i >> 5;
  int bit_position = i % 8;

  if (value){
    buffer_[int_position] |= (1 << bit_position);
  }
  else{
    buffer_[int_position] &= ((1 << bit_position)^-1);
  }
}


#endif // _ALGOS_DATA_STRUCTURES_BIT_ARRAY_H_
