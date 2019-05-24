#include<gtest/gtest.h>
#include"../recursion/squashable_words.h"
#include<unordered_set>
#include<unordered_map>
#include<string>

TEST(test_is_squashable, true_tests){
  unordered_set<string> dictionary({"hello", "hell", "hel", "el", "l", "b"});
  unordered_map<string, bool> mem_dict;
  EXPECT_TRUE(is_squashable("hello", dictionary, mem_dict));
  EXPECT_TRUE(is_squashable("hel", dictionary, mem_dict));
  EXPECT_TRUE(is_squashable("b", dictionary, mem_dict));
}

TEST(test_is_squashable, false_tests){
  unordered_set<string> dictionary({"hello", "hell", "hel", "el", "l", "b"});
  unordered_map<string, bool> mem_dict;
  EXPECT_FALSE(is_squashable("helalo", dictionary, mem_dict));
  EXPECT_FALSE(is_squashable("heh", dictionary, mem_dict));
  EXPECT_FALSE(is_squashable("x", dictionary, mem_dict));
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
