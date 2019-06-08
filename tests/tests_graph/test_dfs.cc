#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_graph.h"
#include"../../graphs/depth_first_search.h"
#include<vector>

TEST(dfs, test_dfs){
  ALGraph g(10);  
  g.add_edge(0, 1);
  g.add_edge(0, 5);
  g.add_edge(0, 7);
  g.add_edge(8, 2);
  g.add_edge(3, 5);
  
  std::vector<int> visited_from(10, -1);
  std::vector<bool> visited(10, false);
  recursive_dfs(g, &visited, &visited_from, 0 , -1);
  
  std::vector<int> visited_from_2(10, -1);
  std::vector<bool> visited_2(10, false);
  iterative_dfs(g, &visited_2, &visited_from_2, 0);
  
  EXPECT_EQ(visited_from, visited_from_2);
  EXPECT_EQ(visited, visited_2);
}
