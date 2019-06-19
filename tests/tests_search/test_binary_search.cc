#include<gtest/gtest.h>
#include<vector>
#include"../../search/binary_search.h"


TEST(test_binary_search, test_empty_list){
  std::vector<int> v;
  EXPECT_EQ(BinarySearch(v, 10), -1);  
}

TEST(test_binary_search, test_present_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(BinarySearch(v, 10), 10);
  EXPECT_EQ(BinarySearch(v, 0), 0);
  EXPECT_EQ(BinarySearch(v, 99), 99);
}


TEST(test_binary_search, test_missing_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(BinarySearch(v, -1), -1);
  EXPECT_EQ(BinarySearch(v, 100), -1);
  EXPECT_EQ(BinarySearch(v, 150), -1);
}

TEST(test_binary_search_recursive, test_empty_list){
  std::vector<int> v;
  EXPECT_EQ(RecursiveBinarySearch(v, 10, 0, v.size() - 1), -1);  
}

TEST(test_binary_search_recursive, test_present_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(RecursiveBinarySearch(v, 10, 0, v.size() - 1), 10);
  EXPECT_EQ(RecursiveBinarySearch(v, 0, 0, v.size() - 1), 0);
  EXPECT_EQ(RecursiveBinarySearch(v, 99, 0, v.size() - 1), 99);
}


TEST(test_binary_search_recursive, test_missing_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(RecursiveBinarySearch(v, -1, 0, v.size() - 1), -1);
  EXPECT_EQ(RecursiveBinarySearch(v, 100, 0, v.size() - 1), -1);
  EXPECT_EQ(RecursiveBinarySearch(v, 150, 0, v.size() - 1), -1);
}
