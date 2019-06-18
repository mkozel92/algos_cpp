#include<gtest/gtest.h>
#include <string>
#include "../../data_structures/bit_stream.h"
#include "../../compression/run_length.h"

TEST(compression, test_run_length){
  std::string a_string = "this is some string";
  BitStream bs(a_string);
  int original_length = bs.Length();
  BitStream compressed = Compress(&bs);

  int compressed_lenght = compressed.Length();
  BitStream expanded = Expand(&compressed);
  int expanded_length =  expanded.Length();
  std::string retrieved_string = expanded.ReadStream();

  EXPECT_EQ(a_string, retrieved_string);
  EXPECT_EQ(original_length, expanded_length);
  EXPECT_NE(original_length, compressed_lenght);
}
