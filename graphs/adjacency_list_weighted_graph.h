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
  explicit ALWGraph(int size) : WeightedGraph(size), graph_(size) {}

  std::vector<std::unordered_set<std::shared_ptr<Edge>>> graph_;
  std::unordered_set<std::shared_ptr<Edge>> edges_;

  std::unordered_set<std::shared_ptr<Edge>> Adjacent(int) const override;

  std::unordered_set<std::shared_ptr<Edge>> GetEdges() const override;

  void AddEdge(int, int, float) override;
};

#endif //ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_GRAPH_H_
