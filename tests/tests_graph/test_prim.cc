#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_weighted_graph.h"
#include"../../graphs/prim.h"
#include<vector>

TEST(prim, test_prim){
  ALWGraph g(10);
  g.AddEdge(0, 1, 100);
  g.AddEdge(1, 2, 6);
  g.AddEdge(2, 3, 7);
  g.AddEdge(3, 4, 8);
  g.AddEdge(4, 1, 9);
  g.AddEdge(3, 2, 10);
  g.AddEdge(0, 4, 11);
  g.AddEdge(0, 2, 12);
  auto mst = Prim(g);
  std::vector<int> correct = {0, 1, 2, 2, 3, 3, 4, 4};
  std::vector<int> computed;
  for(auto e: mst){
    int v_1 = e->Either();
    int v_2 = e->Other(v_1);
    computed.push_back(v_1);
    computed.push_back(v_2);
  }
  std::sort(computed.begin(), computed.end());
  EXPECT_EQ(correct, computed);
}
