#ifndef ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_GRAPH_H_
#define ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_GRAPH_H_

#include"graph.h"
#include"edge.h"
#include<vector>
#include<cassert>
#include<memory>

/**
* @brief Graph implemented using adjacency list
*/
class ALWGraph : public WeightedGraph {
public:
  explicit ALWGraph(int size) : WeightedGraph(size), graph(size) {}

  std::vector<std::unordered_set<std::shared_ptr<Edge>>> graph;
  std::unordered_set<std::shared_ptr<Edge>> edges;

  std::unordered_set<std::shared_ptr<Edge>> adjacent(int) const override;

  std::unordered_set<std::shared_ptr<Edge>> get_edges() const override;

  void add_edge(int, int, float) override;
};

#endif //ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_GRAPH_H_
