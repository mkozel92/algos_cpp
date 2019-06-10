#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_weighted_graph.h"
#include"../../graphs/prim.h"
#include<vector>

TEST(prim, test_prim){
  ALWGraph g(10);
  g.add_edge(0, 1, 100);
  g.add_edge(1, 2, 6);
  g.add_edge(2, 3, 7);
  g.add_edge(3, 4, 8);
  g.add_edge(4, 1, 9);
  g.add_edge(3, 2, 10);
  g.add_edge(0, 4, 11);
  g.add_edge(0, 2, 12);
  auto mst = prim(g);
  std::vector<int> correct = {0, 1, 2, 2, 3, 3, 4, 4};
  std::vector<int> computed;
  for(auto e: mst){
    int v_1 = e->either();
    int v_2 = e->other(v_1);
    computed.push_back(v_1);
    computed.push_back(v_2);
  }
  std::sort(computed.begin(), computed.end());
  EXPECT_EQ(correct, computed);
}
