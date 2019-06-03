#include<gtest/gtest.h>
#include<vector>
#include"../../sort/quick_sort.h"


TEST(quick_sort, integer_test_basic){
  std::vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  std::vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  quick_sort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(quick_sort, integer_test_three_way){
  std::vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  std::vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  quick_sort(&a_vector, "three_way");
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(quick_sort, string_test_basic){
  std::vector<std::string> a_vector{"this", "is", "some", "sample",\
                                    "data", "for", "sorting", "test"};  
  std::vector<std::string> sorted_vector{"this", "is", "some", "sample",\
                                         "data", "for", "sorting", "test"};  
  std::sort(sorted_vector.begin(), sorted_vector.end());
  quick_sort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(merge_sort, string_test_three_way){
  std::vector<std::string> a_vector{"this", "is", "some", "sample",\
                                    "data", "for", "sorting", "test"};  
  std::vector<std::string> sorted_vector{"this", "is", "some", "sample",\
                                         "data", "for", "sorting", "test"};  
  std::sort(sorted_vector.begin(), sorted_vector.end());
  quick_sort(&a_vector, "three_way");
  EXPECT_EQ(a_vector, sorted_vector);
}
