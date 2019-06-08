#ifndef AL_GRAPH
#define AL_GRAPH

#include"graph.h"
#include<vector>
#include<cassert>

/**
* @brief Graph implemented using adjacency list
*/
class ALDigraph : public Digraph {
  public:
    std::vector<std::unordered_set<int>> graph;
    ALDigraph(int size) : Digraph(size), graph(size) {}
    std::unordered_set<int> adjacent(int) const;
    void add_edge(int, int);
    ALDigraph *reverse();
};
 
#endif
