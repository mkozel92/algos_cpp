#include<gtest/gtest.h>
#include"../../sort/msd_radix_sort.h"
#include"../../sort/lsd_radix_sort.h"
#include"../../sort/three_way_radix.h"
#include<vector>
#include<string>

TEST(radix_sorts, test_lsd_radix){
  std::vector<std::string> a_vector = {"aaa", "bbb", "dec", "ced", "aed", "bed"};
  std::vector<std::string> a_vector_sorted = {"aaa", "bbb", "dec", "ced", "aed", "bed"};
  std::sort(a_vector_sorted.begin(), a_vector_sorted.end());
  LSDRadixSort(&a_vector, 256);
  EXPECT_EQ(a_vector, a_vector_sorted);
  
}

TEST(radix_sorts, test_msd_radix){
  std::vector<std::string> a_vector = {"this", "is", "just", "some",\
                                       "sample", "data", "to", "sort"};
  std::vector<std::string> a_vector_sorted = {"this", "is", "just", "some",\
                                              "sample", "data", "to", "sort"};
  std::sort(a_vector_sorted.begin(), a_vector_sorted.end());
  MSDRadixSort(&a_vector, 256);
  EXPECT_EQ(a_vector, a_vector_sorted);
  
}

TEST(radix_sorts, test_three_way_radix){
  std::vector<std::string> a_vector = {"this", "is", "just", "some",\
                                       "sample", "data", "to", "sort"};
  std::vector<std::string> a_vector_sorted = {"this", "is", "just", "some",\
                                              "sample", "data", "to", "sort"};
  std::sort(a_vector_sorted.begin(), a_vector_sorted.end());
  RadixQuickSort(&a_vector);
  EXPECT_EQ(a_vector, a_vector_sorted);
  
}

