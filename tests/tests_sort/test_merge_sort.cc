#include<gtest/gtest.h>
#include<vector>
#include"../../sort/merge_sort.h"


TEST(MergeSort, integer_test_recursive){
  std::vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  std::vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  MergeSort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(MergeSort, integer_test_iterative){
  std::vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  std::vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  MergeSort(&a_vector, "iterative");
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(MergeSort, string_test_recursive){
  std::vector<std::string> a_vector{"this", "is", "some", "sample",\
                                    "data", "for", "sorting", "test"};  
  std::vector<std::string> sorted_vector{"this", "is", "some", "sample",\
                                         "data", "for", "sorting", "test"};  
  std::sort(sorted_vector.begin(), sorted_vector.end());
  MergeSort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(MergeSort, string_test_iterative){
  std::vector<std::string> a_vector{"this", "is", "some", "sample",\
                                    "data", "for", "sorting", "test"};  
  std::vector<std::string> sorted_vector{"this", "is", "some", "sample",\
                                         "data", "for", "sorting", "test"};  
  std::sort(sorted_vector.begin(), sorted_vector.end());
  MergeSort(&a_vector, "iterative");
  EXPECT_EQ(a_vector, sorted_vector);
}
