#include<gtest/gtest.h>
#include"../recursion/squashable_words.h"
#include<unordered_set>
#include<string>

TEST(test_is_squashable, true_tests){
  unordered_set<string> dictionary({"hello", "hell", "hel", "el", "l", "b"});
  EXPECT_TRUE(is_squashable("hello", dictionary));
  EXPECT_TRUE(is_squashable("hel", dictionary));
  EXPECT_TRUE(is_squashable("b", dictionary));
}

TEST(test_is_squashable, false_tests){
  unordered_set<string> dictionary({"hello", "hell", "hel", "el", "l", "b"});
  EXPECT_FALSE(is_squashable("helalo", dictionary));
  EXPECT_FALSE(is_squashable("heh", dictionary));
  EXPECT_FALSE(is_squashable("x", dictionary));
}

int main(int argc, char** argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
