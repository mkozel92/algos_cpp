#ifndef AM_GRAPH
#define AM_GRAPH

#include"graph.h"
#include<vector>
#include<cassert>

/**
* @brief graph implemented using adjacency matrix
*/
class AMGraph : public Graph {
  public:
    std::vector<std::vector<int>> graph;
    AMGraph(int size) : Graph(size), graph(size, std::vector<int>(size, 0)) {}
    std::unordered_set<int> adjacent(int) const;
    void add_edge(int, int);
};


/**
* @brief return set of adjacent verices to given vertex
* complexity O(V)
*
* @param v a vertex
*
* @return unordered_set of adjacent vertices
*/
std::unordered_set<int> AMGraph::adjacent(int v) const {
  
  assert(v < graph_size && v >= 0);
  std::unordered_set<int> adjacent_vertices;
  for(int i = 0; i < graph_size; i++){
    if(graph[v][i] == 1){
      adjacent_vertices.insert(i);  
    }
  }
}

/**
* @brief add new edge to the graph between given vertices
* complexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
*/
void AMGraph::add_edge(int v_1, int v_2){
  assert(v_1 < graph_size && v_1 >= 0);
  assert(v_2 < graph_size && v_2 >= 0);

  graph[v_1][v_2] = 1;  
  graph[v_2][v_1] = 1;  
}
  
#endif
