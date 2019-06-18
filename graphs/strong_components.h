#ifndef ALGOS_GRAPHS_STRONG_COMPONENTS_H_
#define ALGOS_GRAPHS_STRONG_COMPONENTS_H_

#include"graph.h"
#include<vector>
#include<stack>

/**
* @brief class that keep track of strong components of a given graph
*/
class StrongComponents {
private:
  Digraph *a_graph_;
  std::vector<int> vertex_group_;
  std::vector<bool> visited_;
public:
  explicit StrongComponents(Digraph *g) : a_graph_(g), vertex_group_(g->Size(), 0), \
                                     visited_(g->Size(), false) {};

  void Compute();

  void Dfs(Digraph *, int, int, std::stack<int> *);

  bool IsConnected(int, int);
};

#endif // ALGOS_GRAPHS_STRONG_COMPONENTS_H_
