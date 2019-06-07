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


/**
* @brief get all vertices adjacent to given vertex
* complexity O(1)
*
* @param v a vertex
*
* @return unordered_set of adjacent vertices
*/
std::unordered_set<int> ALGraph::adjacent(int v) const {
  assert(v < graph_size);
  return graph[v];  
}

/**
* @brief add new edge to the graph between given vertices
* comlexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
*/
void ALGraph::add_edge(int v_1, int v_2){

  assert(v_1 < graph_size);
  assert(v_2 < graph_size);

  graph[v_1].insert(v_2);  
  graph[v_2].insert(v_1);  
}
 
