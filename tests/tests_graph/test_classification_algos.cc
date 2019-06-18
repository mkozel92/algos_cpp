#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_graph.h"
#include"../../graphs/adjacency_list_digraph.h"
#include"../../graphs/graph_classification_algos.h"



TEST(graph, classification_algos){
  ALGraph g(5);
  g.AddEdge(0, 2);
  g.AddEdge(0, 3);
  g.AddEdge(0, 4);
  g.AddEdge(1, 3);
  g.AddEdge(1, 4);
  EXPECT_TRUE(IsBipartite(g));
  
  g.AddEdge(2, 4);
  EXPECT_FALSE(IsBipartite(g));
  
  ALDigraph dg(5);
  dg.AddEdge(0, 2);
  dg.AddEdge(0, 3);
  dg.AddEdge(0, 4);
  dg.AddEdge(1, 3);
  dg.AddEdge(1, 4);
  dg.AddEdge(2, 4);
  EXPECT_FALSE(HasCycle(dg));

  dg.AddEdge(4, 0);
  EXPECT_TRUE(HasCycle(dg));

}
