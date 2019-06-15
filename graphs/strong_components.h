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
  Digraph *g;
  std::vector<int> vertex_group;
  std::vector<bool> visited;
public:
  explicit StrongComponents(Digraph *g) : g(g), vertex_group(g->graph_size, 0), \
                                     visited(g->graph_size, false) {};

  void compute();

  void dfs(Digraph *, int, int, std::stack<int> *);

  bool is_connected(int, int);
};

#endif // ALGOS_GRAPHS_STRONG_COMPONENTS_H_
