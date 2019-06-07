#ifndef AL_GRAPH
#define AL_GRAPH

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
 
#endif
