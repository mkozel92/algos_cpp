#include<gtest/gtest.h>
#include"../../../graphs/adjacency_list_weighted_digraph.h"
#include<vector>
#include"../../../graphs/shortest_path/dijkstra.h"
#include<iostream>

TEST(shortest_path, dijkstra){
  ALWDigraph g(10);
  g.AddEdge(0, 1, 10);
  g.AddEdge(1, 2, 10);
  g.AddEdge(0, 3, 10);
  g.AddEdge(0, 4, 1);
  g.AddEdge(4, 2, 1);
  g.AddEdge(0, 6, 5);
  g.AddEdge(2, 3, 1);
  g.AddEdge(3, 0, 5);
  g.AddEdge(6, 8, 2);
  g.AddEdge(0, 8, 10);
  std::vector<float> distances(10, 999);
  distances[0] = 0;
  std::vector<bool> visited(10, false);
  std::vector<int> edge_to(10, -1);
  Dijkstra(g, &visited, &edge_to, &distances);
  std::vector<float> correct_distances = {0, 10, 2, 3, 1, 999, 5, 999, 7, 999 };
  EXPECT_EQ(correct_distances, distances);
}
  
