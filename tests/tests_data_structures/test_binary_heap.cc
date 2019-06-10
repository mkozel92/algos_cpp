#include<gtest/gtest.h>
#include"../../data_structures/binary_heap.h"


//bool compare(int a, int b){
//  return a < b;  
//}

TEST(Test_binary_heap, test_min_heap){
 
 BinaryHeap<int> min_heap([](int a, int b)->bool{return a < b;});  
  min_heap.insert(0);
  min_heap.insert(2);
  min_heap.insert(1);
  min_heap.insert(3);
  min_heap.insert(5);
  min_heap.insert(4);
  for (int i = 0; i < 6; i++){
    int data = min_heap.remove();
    EXPECT_EQ(data, i);
  }
}

TEST(Test_binary_heap, test_max_heap){
  BinaryHeap<int> max_heap;  
  max_heap.insert(0);
  max_heap.insert(2);
  max_heap.insert(1);
  max_heap.insert(3);
  max_heap.insert(5);
  max_heap.insert(4);
  for (int i = 5; i >= 0; i--){
    int data = max_heap.remove();
    EXPECT_EQ(data, i);
  }
}
