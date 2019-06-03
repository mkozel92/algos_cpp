#include<gtest/gtest.h>
#include<vector>
#include"../../sort/shell_sort.h"


TEST(shell_sort, integer_test){
  std::vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  std::vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> h_distances{13, 5, 1};
  shell_sort(&a_vector, h_distances);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(shell_sort, string_test){
  std::vector<std::string> a_vector{"this", "is", "some", "sample",\
                                    "data", "for", "sorting", "test"};  
  std::vector<std::string> sorted_vector{"this", "is", "some", "sample",\
                                         "data", "for", "sorting", "test"};  
  std::vector<int> h_distances{13, 5, 1};
  std::sort(sorted_vector.begin(), sorted_vector.end());
  shell_sort(&a_vector, h_distances);
  EXPECT_EQ(a_vector, sorted_vector);
}
