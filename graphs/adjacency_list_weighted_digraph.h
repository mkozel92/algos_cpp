#ifndef ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_DIGRAPH_H_
#define ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_DIGRAPH_H_

#include"graph.h"
#include"directed_edge.h"
#include<vector>
#include<cassert>
#include<memory>

/**
* @brief Graph implemented using adjacency list
*/
class ALWDigraph : public WeightedDigraph {
public:
  explicit ALWDigraph(int size) : WeightedDigraph(size), graph(size) {};

  std::vector<std::unordered_set<std::shared_ptr<DirectedEdge>>> graph;
  std::unordered_set<std::shared_ptr<DirectedEdge>> edges;

  std::unordered_set<std::shared_ptr<DirectedEdge>> adjacent(int) const override;

  std::unordered_set<std::shared_ptr<DirectedEdge>> get_edges() const override;

  void add_edge(int, int, float) override;
};

#endif //ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_DIGRAPH_H_
