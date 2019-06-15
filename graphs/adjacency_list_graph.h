#ifndef ALGOS_GRAPHS_ADJACENCY_LIST_GRAPH_H_
#define ALGOS_GRAPHS_ADJACENCY_LIST_GRAPH_H_

#include"graph.h"
#include<vector>
#include<cassert>

/**
* @brief Graph implemented using adjacency list
*/
class ALGraph : public Graph {
public:
  std::vector<std::unordered_set<int>> graph;

  explicit ALGraph(int size) : Graph(size), graph(size) {}

  std::unordered_set<int> adjacent(int) const override;

  void add_edge(int, int) override;
};

#endif //ALGOS_GRAPHS_ADJACENCY_LIST_GRAPH_H_
