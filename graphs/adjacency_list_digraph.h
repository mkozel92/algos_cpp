#ifndef ALGOS_GRAPHS_ADJACENCY_LIST_DIGRAPH_H_
#define ALGOS_GRAPHS_ADJACENCY_LIST_DIGRAPH_H_

#include"graph.h"
#include<vector>
#include<cassert>
#include<memory>

/**
* @brief Graph implemented using adjacency list
*/
class ALDigraph : public Digraph {
public:
  std::vector<std::unordered_set<int>> graph_;

  explicit ALDigraph(int size) : Digraph(size), graph_(size) {}

  std::unordered_set<int> Adjacent(int) const override;

  void AddEdge(int, int) override;

  ALDigraph *Reverse() override;
};

#endif // ALGOS_GRAPHS_ADJACENCY_LIST_DIGRAPH_H_
