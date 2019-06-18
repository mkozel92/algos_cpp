#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_graph.h"
#include"../../graphs/connected_components.h"


TEST(graph_test, connected_componentss_test){
  ALGraph g(10);
  g.AddEdge(0,1);
  g.AddEdge(1,2);
  g.AddEdge(1,3);
  g.AddEdge(5,6);
  g.AddEdge(5,7);
  g.AddEdge(8,9);
  ConnectedComponents cc(&g);
  cc.Compute();

  EXPECT_TRUE(cc.IsConnected(0, 1));
  EXPECT_TRUE(cc.IsConnected(0, 2));
  EXPECT_TRUE(cc.IsConnected(1, 3));
  EXPECT_TRUE(cc.IsConnected(5, 7));
  EXPECT_TRUE(cc.IsConnected(8, 9));

  EXPECT_FALSE(cc.IsConnected(1, 9));
  EXPECT_FALSE(cc.IsConnected(0, 5));
  EXPECT_FALSE(cc.IsConnected(0, 7));
  EXPECT_FALSE(cc.IsConnected(7, 9));
  EXPECT_FALSE(cc.IsConnected(3, 9));
  EXPECT_FALSE(cc.IsConnected(0, 6));
}
