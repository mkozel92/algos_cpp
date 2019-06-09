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
    std::vector<std::unordered_set<int>> graph;
    ALDigraph(int size) : Digraph(size), graph(size) {}
    std::unordered_set<int> adjacent(int) const;
    void add_edge(int, int);
    ALDigraph* reverse();
};
 
#endif // ALGOS_GRAPHS_ADJACENCY_LIST_DIGRAPH_H_
