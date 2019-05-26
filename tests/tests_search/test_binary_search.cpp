#include<gtest/gtest.h>
#include<vector>
#include"../../search/binary_search.h"

using namespace std;

TEST(test_binary_search, test_empty_list){
  vector<int> v;
  EXPECT_EQ(my_binary_search(v, 10), -1);  
}

TEST(test_binary_search, test_present_elements){
  vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(my_binary_search(v, 10), 10);
  EXPECT_EQ(my_binary_search(v, 0), 0);
  EXPECT_EQ(my_binary_search(v, 99), 99);
}


TEST(test_binary_search, test_missing_elements){
  vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  EXPECT_EQ(my_binary_search(v, -1), -1);
  EXPECT_EQ(my_binary_search(v, 100), -1);
  EXPECT_EQ(my_binary_search(v, 150), -1);
}

