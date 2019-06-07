#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_graph.cpp"
#include"../../graphs/connected_components.cpp"


TEST(graph_test, connected_componentss_test){
  ALGraph g(10);
  g.add_edge(0,1);
  g.add_edge(1,2);
  g.add_edge(1,3);
  g.add_edge(5,6);
  g.add_edge(5,7);
  g.add_edge(8,9);
  ConnectedComponents cc(&g);
  cc.compute();

  EXPECT_TRUE(cc.is_connected(0, 1));
  EXPECT_TRUE(cc.is_connected(0, 2));
  EXPECT_TRUE(cc.is_connected(1, 3));
  EXPECT_TRUE(cc.is_connected(5, 7));
  EXPECT_TRUE(cc.is_connected(8, 9));

  EXPECT_FALSE(cc.is_connected(1, 9));
  EXPECT_FALSE(cc.is_connected(0, 5));
  EXPECT_FALSE(cc.is_connected(0, 7));
  EXPECT_FALSE(cc.is_connected(7, 9));
  EXPECT_FALSE(cc.is_connected(3, 9));
  EXPECT_FALSE(cc.is_connected(0, 6));
}
