#include<gtest/gtest.h>
#include"../../dynamic_connectivity/quick_find.h"
#include"../../dynamic_connectivity/quick_union.h"
#include"../../dynamic_connectivity/weighted_quick_union.h"


TEST(dynamic_connectivity, test_connected_quick_find){
  QuickFind qf(20);
  qf.union_(1, 2);
  qf.union_(2, 5);
  qf.union_(5, 15);
  EXPECT_TRUE(qf.connected(1, 15));
  EXPECT_TRUE(qf.connected(2, 5));
  EXPECT_TRUE(qf.connected(5, 15));
  EXPECT_FALSE(qf.connected(1, 10));
  EXPECT_FALSE(qf.connected(10, 8));
  EXPECT_FALSE(qf.connected(5, 3));
}

TEST(dynamic_connectivity, test_self_connection_quick_find){
  QuickFind qf(20);
  EXPECT_TRUE(qf.connected(1, 1));
  EXPECT_TRUE(qf.connected(2, 2));
  EXPECT_TRUE(qf.connected(18, 18));
}

TEST(dynamic_connectivity, test_connected_quick_union){
  QuickUnion qu(20);
  qu.union_(1, 2);
  qu.union_(2, 5);
  qu.union_(5, 15);
  EXPECT_TRUE(qu.connected(1, 15));
  EXPECT_TRUE(qu.connected(2, 5));
  EXPECT_TRUE(qu.connected(5, 15));
  EXPECT_FALSE(qu.connected(1, 10));
  EXPECT_FALSE(qu.connected(10, 8));
  EXPECT_FALSE(qu.connected(5, 3));
}

TEST(dynamic_connectivity, test_self_connection_quick_union){
  QuickUnion qu(20);
  EXPECT_TRUE(qu.connected(1, 1));
  EXPECT_TRUE(qu.connected(2, 2));
  EXPECT_TRUE(qu.connected(18, 18));
}

TEST(dynamic_connectivity, test_connected_w_quick_union){
  WeightedQuickUnion wqu(20);
  wqu.union_(1, 2);
  wqu.union_(2, 5);
  wqu.union_(5, 15);
  EXPECT_TRUE(wqu.connected(1, 15));
  EXPECT_TRUE(wqu.connected(2, 5));
  EXPECT_TRUE(wqu.connected(5, 15));
  EXPECT_FALSE(wqu.connected(1, 10));
  EXPECT_FALSE(wqu.connected(10, 8));
  EXPECT_FALSE(wqu.connected(5, 3));
}

TEST(dynamic_connectivity, test_self_connection_w_quick_union){
  WeightedQuickUnion wqu(20);
  EXPECT_TRUE(wqu.connected(1, 1));
  EXPECT_TRUE(wqu.connected(2, 2));
  EXPECT_TRUE(wqu.connected(18, 18));
}
