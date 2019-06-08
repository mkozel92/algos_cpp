#include<gtest/gtest.h>
#include<vector>
#include"../../search/binary_search.h"


TEST(test_binary_search, test_empty_list){
  std::vector<int> v;
  EXPECT_EQ(my_binary_search(v, 10), -1);  
}

TEST(test_binary_search, test_present_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(my_binary_search(v, 10), 10);
  EXPECT_EQ(my_binary_search(v, 0), 0);
  EXPECT_EQ(my_binary_search(v, 99), 99);
}


TEST(test_binary_search, test_missing_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(my_binary_search(v, -1), -1);
  EXPECT_EQ(my_binary_search(v, 100), -1);
  EXPECT_EQ(my_binary_search(v, 150), -1);
}

TEST(test_binary_search_recursive, test_empty_list){
  std::vector<int> v;
  EXPECT_EQ(recursive_binary_search(v, 10, 0, v.size() - 1), -1);  
}

TEST(test_binary_search_recursive, test_present_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(recursive_binary_search(v, 10, 0, v.size() - 1), 10);
  EXPECT_EQ(recursive_binary_search(v, 0, 0, v.size() - 1), 0);
  EXPECT_EQ(recursive_binary_search(v, 99, 0, v.size() - 1), 99);
}


TEST(test_binary_search_recursive, test_missing_elements){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(recursive_binary_search(v, -1, 0, v.size() - 1), -1);
  EXPECT_EQ(recursive_binary_search(v, 100, 0, v.size() - 1), -1);
  EXPECT_EQ(recursive_binary_search(v, 150, 0, v.size() - 1), -1);
}
