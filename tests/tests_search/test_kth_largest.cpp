#include<gtest/gtest.h>
#include<vector>
#include"../../search/kth_largest.h"
#include<iostream>

TEST(test_kth_largest, test_all){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  for(int k = 0; k < 100; k++){
    EXPECT_EQ(k, quick_find(&v, k));  
  }
}

TEST(test_kth_largest_three, test_all){
  std::vector<int> v(100);
  for(int i = 0; i < v.size(); i++){
    v[i] = i;
  }
  for(int k = 0; k < 100; k++){
    std::cout<< quick_find_three(&v, k)<< " "<< k<<std::endl;
    EXPECT_EQ(k, quick_find_three(&v, k));  
  }
}
