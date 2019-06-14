#include<gtest/gtest.h>
#include"../../../search/substring_search/knuth_morris_pratt.h"
#include<string>

TEST(substring_search, knuth_morris_pratt){
  std::string a_string = "this is some long string";
  std::string pattern_1 = "string";
  std::string pattern_2 = "so";
  std::string pattern_3 = "not";

  EXPECT_EQ(KnuthMorrisPratt(a_string, pattern_1), 18);
  EXPECT_EQ(KnuthMorrisPratt(a_string, pattern_2), 8);
  EXPECT_EQ(KnuthMorrisPratt(a_string, pattern_3), -1);
}
