#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_graph.h"
#include"../../graphs/depth_first_search.h"
#include<vector>

TEST(dfs, test_dfs){
  ALGraph g(10);  
  g.AddEdge(0, 1);
  g.AddEdge(0, 5);
  g.AddEdge(0, 7);
  g.AddEdge(8, 2);
  g.AddEdge(3, 5);
  
  std::vector<int> visited_from(10, -1);
  std::vector<bool> visited(10, false);
  RecursiveDfs(g, &visited, &visited_from, 0 , -1);
  
  std::vector<int> visited_from_2(10, -1);
  std::vector<bool> visited_2(10, false);
  IterativeDfs(g, &visited_2, &visited_from_2, 0);
  
  EXPECT_EQ(visited_from, visited_from_2);
  EXPECT_EQ(visited, visited_2);
}
