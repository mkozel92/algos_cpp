#include<gtest/gtest.h>
#include"../../graphs/adjacency_list_graph.h"
#include"../../graphs/adjacency_list_digraph.h"
#include"../../graphs/graph_classification_algos.h"



TEST(graph, classification_algos){
  ALGraph g(5);
  g.add_edge(0, 2);
  g.add_edge(0, 3);
  g.add_edge(0, 4);
  g.add_edge(1, 3);
  g.add_edge(1, 4);
  EXPECT_TRUE(IsBipartite(g));
  
  g.add_edge(2, 4);
  EXPECT_FALSE(IsBipartite(g));
  
  ALDigraph dg(5);
  dg.add_edge(0, 2);
  dg.add_edge(0, 3);
  dg.add_edge(0, 4);
  dg.add_edge(1, 3);
  dg.add_edge(1, 4);
  dg.add_edge(2, 4);
  EXPECT_FALSE(HasCycle(dg));

  dg.add_edge(4, 0);
  EXPECT_TRUE(HasCycle(dg));

}
