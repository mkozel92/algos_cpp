#include<gtest/gtest.h>
#include"../../data_structures/binary_heap.h"


//bool compare(int a, int b){
//  return a < b;  
//}

TEST(Test_binary_heap, test_min_heap){
 
 BinaryHeap<int> min_heap([](int a, int b)->bool{return a < b;});  
  min_heap.Insert(0);
  min_heap.Insert(2);
  min_heap.Insert(1);
  min_heap.Insert(3);
  min_heap.Insert(5);
  min_heap.Insert(4);
  for (int i = 0; i < 6; i++){
    int data = min_heap.Remove();
    EXPECT_EQ(data, i);
  }
}

TEST(Test_binary_heap, test_max_heap){
  BinaryHeap<int> max_heap;  
  max_heap.Insert(0);
  max_heap.Insert(2);
  max_heap.Insert(1);
  max_heap.Insert(3);
  max_heap.Insert(5);
  max_heap.Insert(4);
  for (int i = 5; i >= 0; i--){
    int data = max_heap.Remove();
    EXPECT_EQ(data, i);
  }
}
