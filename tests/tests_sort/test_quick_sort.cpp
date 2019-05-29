#include<gtest/gtest.h>
#include<vector>
#include"../../sort/quick_sort.h"

using namespace std;

TEST(quick_sort, integer_test_basic){
  vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  quick_sort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(quick_sort, integer_test_three_way){
  vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  quick_sort(&a_vector, "three_way");
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(quick_sort, string_test_basic){
  vector<string> a_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  vector<string> sorted_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  sort(sorted_vector.begin(), sorted_vector.end());
  quick_sort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(merge_sort, string_test_three_way){
  vector<string> a_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  vector<string> sorted_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  sort(sorted_vector.begin(), sorted_vector.end());
  quick_sort(&a_vector, "three_way");
  EXPECT_EQ(a_vector, sorted_vector);
}
