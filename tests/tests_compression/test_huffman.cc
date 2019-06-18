#include<gtest/gtest.h>
#include"../../compression/huffman.h"


TEST(compression, test_huffman) {
  std::string original_text = "sample text to encode";
  huffman::BinaryTrie bt(original_text);
  BitStream original_stream(original_text);
  int original_length = original_stream.Length();

  BitStream encoded_stream = bt.Encode(original_text);
  int encoded_length = encoded_stream.Length();

  std::string decoded_text = bt.Decode(&encoded_stream);
  EXPECT_TRUE(original_length > encoded_length);
  EXPECT_EQ(decoded_text, original_text);
}
