#ifndef ALGOS_GRAPHS_CONNECTED_COMPONENTS_H_
#define ALGOS_GRAPHS_CONNECTED_COMPONENTS_H_

#include"graph.h"
#include<vector>


/**
* @brief class that keep track of connected components of a given graph
*/
class ConnectedComponents {
private:
  Graph *a_graph_;
  std::vector<int> vertex_group_;
  std::vector<bool> visited_;
public:
  explicit ConnectedComponents(Graph *g) : a_graph_(g), vertex_group_(g->Size(), 0), \
                                     visited_(g->Size(), false) {};

  void Compute();

  void Dfs(int, int);

  bool IsConnected(int, int);
};

#endif // ALGOS_GRAPHS_CONNECTED_COMPONENTS_H_
