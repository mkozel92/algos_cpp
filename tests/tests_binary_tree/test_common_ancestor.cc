#include<gtest/gtest.h>
#include"../../binary_trees/binary_tree.h"
#include"../../binary_trees/common_ancestor.h"


TEST(binary_trees, common_ancestor){

  binary_tree::BinaryTree<int, int> bt;
  std::vector<int> a_vector{1, 6, 9, 7, 5, 3, 2, 0, 4, 8};

  for(auto i : a_vector){
    bt.Put(i , 2*i);
  }

  EXPECT_EQ(1, binary_tree::CommonAncestor(bt.root_, 8, 0).node->key_);
  EXPECT_EQ(3, binary_tree::CommonAncestor(bt.root_, 2, 4).node->key_);
  EXPECT_EQ(3, binary_tree::CommonAncestor(bt.root_, 3, 4).node->key_);

}

