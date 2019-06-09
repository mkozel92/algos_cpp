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
    std::vector<std::unordered_set<std::shared_ptr<Edge>>> graph;
    std::unordered_set<std::shared_ptr<Edge>> edges;
    ALWGraph(int size) : WeightedGraph(size), graph(size) {}
    std::unordered_set<std::shared_ptr<Edge>> adjacent(int) const;
    std::unordered_set<std::shared_ptr<Edge>> get_edges() const;
    void add_edge(int, int, float);
};
 
#endif //ALGOS_GRAPHS_ADJACENCY_LIST_WEIGHTED_GRAPH_H_
