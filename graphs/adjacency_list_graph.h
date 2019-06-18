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
  std::vector<std::unordered_set<int>> graph_;

  explicit ALGraph(int size) : Graph(size), graph_(size) {}

  std::unordered_set<int> Adjacent(int) const override;

  void AddEdge(int, int) override;
};

#endif //ALGOS_GRAPHS_ADJACENCY_LIST_GRAPH_H_
