#include<gtest/gtest.h>
#include"../../data_structures/bit_array.h"


TEST(data_structure_test, bit_array){
  BitArray<100> bit_array;
  bit_array.SetBit(80, true);
  bit_array.SetBit(70, true);
  bit_array.SetBit(60, true);

  EXPECT_TRUE(bit_array.GetBit(80));
  EXPECT_TRUE(bit_array.GetBit(70));
  EXPECT_TRUE(bit_array.GetBit(60));

  bit_array.SetBit(60, false);

  EXPECT_FALSE(bit_array.GetBit(60));
  EXPECT_FALSE(bit_array.GetBit(50));
  EXPECT_FALSE(bit_array.GetBit(40));
}
