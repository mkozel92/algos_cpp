#include<gtest/gtest.h>
#include"../../dynamic_connectivity/quick_find.h"
#include"../../dynamic_connectivity/quick_union.h"
#include"../../dynamic_connectivity/weighted_quick_union.h"


TEST(dynamic_connectivity, test_Connected_quick_find){
  QuickFind qf(20);
  qf.Union(1, 2);
  qf.Union(2, 5);
  qf.Union(5, 15);
  EXPECT_TRUE(qf.Connected(1, 15));
  EXPECT_TRUE(qf.Connected(2, 5));
  EXPECT_TRUE(qf.Connected(5, 15));
  EXPECT_FALSE(qf.Connected(1, 10));
  EXPECT_FALSE(qf.Connected(10, 8));
  EXPECT_FALSE(qf.Connected(5, 3));
}

TEST(dynamic_connectivity, test_self_connection_quick_find){
  QuickFind qf(20);
  EXPECT_TRUE(qf.Connected(1, 1));
  EXPECT_TRUE(qf.Connected(2, 2));
  EXPECT_TRUE(qf.Connected(18, 18));
}

TEST(dynamic_connectivity, test_Connected_quick_union){
  QuickUnion qu(20);
  qu.Union(1, 2);
  qu.Union(2, 5);
  qu.Union(5, 15);
  EXPECT_TRUE(qu.Connected(1, 15));
  EXPECT_TRUE(qu.Connected(2, 5));
  EXPECT_TRUE(qu.Connected(5, 15));
  EXPECT_FALSE(qu.Connected(1, 10));
  EXPECT_FALSE(qu.Connected(10, 8));
  EXPECT_FALSE(qu.Connected(5, 3));
}

TEST(dynamic_connectivity, test_self_connection_quick_union){
  QuickUnion qu(20);
  EXPECT_TRUE(qu.Connected(1, 1));
  EXPECT_TRUE(qu.Connected(2, 2));
  EXPECT_TRUE(qu.Connected(18, 18));
}

TEST(dynamic_connectivity, test_Connected_w_quick_union){
  WeightedQuickUnion wqu(20);
  wqu.Union(1, 2);
  wqu.Union(2, 5);
  wqu.Union(5, 15);
  EXPECT_TRUE(wqu.Connected(1, 15));
  EXPECT_TRUE(wqu.Connected(2, 5));
  EXPECT_TRUE(wqu.Connected(5, 15));
  EXPECT_FALSE(wqu.Connected(1, 10));
  EXPECT_FALSE(wqu.Connected(10, 8));
  EXPECT_FALSE(wqu.Connected(5, 3));
}

TEST(dynamic_connectivity, test_self_connection_w_quick_union){
  WeightedQuickUnion wqu(20);
  EXPECT_TRUE(wqu.Connected(1, 1));
  EXPECT_TRUE(wqu.Connected(2, 2));
  EXPECT_TRUE(wqu.Connected(18, 18));
}
