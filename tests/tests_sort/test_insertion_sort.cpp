#include<gtest/gtest.h>
#include<vector>
#include"../../sort/insertion_sort.h"

using namespace std;

TEST(insertion_sort, integer_test){
  vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  insertion_sort(&a_vector, 1);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(insertion_sort, string_test){
  vector<string> a_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  vector<string> sorted_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  sort(sorted_vector.begin(), sorted_vector.end());
  insertion_sort(&a_vector, 1);
  EXPECT_EQ(a_vector, sorted_vector);
}
