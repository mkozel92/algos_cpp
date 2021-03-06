#include<gtest/gtest.h>
#include"../../recursion/squashable_words.h"
#include<unordered_set>
#include<unordered_map>
#include<string>

TEST(test_is_squashable, true_tests){
  std::unordered_set<std::string> dictionary({"hello", "hell", "hel", "el", "l", "b"});
  std::unordered_map<std::string, bool> mem_dict;
  EXPECT_TRUE(IsSquashable("hello", dictionary, &mem_dict));
  EXPECT_TRUE(IsSquashable("hel", dictionary, &mem_dict));
  EXPECT_TRUE(IsSquashable("b", dictionary, &mem_dict));
}

TEST(test_is_squashable, false_tests){
  std::unordered_set<std::string> dictionary({"hello", "hell", "hel", "el", "l", "b"});
  std::unordered_map<std::string, bool> mem_dict;
  EXPECT_FALSE(IsSquashable("helalo", dictionary, &mem_dict));
  EXPECT_FALSE(IsSquashable("heh", dictionary, &mem_dict));
  EXPECT_FALSE(IsSquashable("x", dictionary, &mem_dict));
}

