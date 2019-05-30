#include<gtest/gtest.h>
#include<vector>
#include"../../sort/heap_sort.h"

using namespace std;

TEST(heap_sort, integer_test){
  vector<int> a_vector{1, 5, 7, 6, 8, 9, 0, 3, 2, 4};
  vector<int> sorted_vector{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  heap_sort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}

TEST(heap_sort, string_test){
  vector<string> a_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  vector<string> sorted_vector{"this", "is", "some", "sample", "data", "for", "sorting", "test"};  
  sort(sorted_vector.begin(), sorted_vector.end());
  heap_sort(&a_vector);
  EXPECT_EQ(a_vector, sorted_vector);
}
