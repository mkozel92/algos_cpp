#include<gtest/gtest.h>
#include"../../binary_trees/binary_tree.h"
#include"../../binary_trees/elements_from_range.h"


TEST(binary_trees, elements_from_range){
  
  binary_tree::BinaryTree<int, int> bt;
  LinkedListQueue<int> lq;
  std::vector<int> a_vector{1, 6, 9, 7, 5, 3, 2, 0, 4, 8};
  for(auto i : a_vector){
    bt.Put(i , 2*i);
  }
  
  binary_tree::GetElementsFromRange(bt.root_, &lq, 3, 7 );
  
  int j = 3;
  for(LLIterator<int> it = lq.begin(); it != lq.end(); it++){
    EXPECT_EQ(*it, j);
    j++;
  }
  
}
