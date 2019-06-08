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
    ALGraph(int size) : Graph(size), graph(size) {}
    std::unordered_set<int> adjacent(int) const;
    void add_edge(int, int);
};
 
#endif //ALGOS_GRAPHS_ADJACENCY_LIST_GRAPH_H_
