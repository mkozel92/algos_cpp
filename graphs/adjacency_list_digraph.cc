#include"adjacency_list_digraph.h"

/**
* @brief get all vertices adjacent to given vertex
* complexity O(1)
*
* @param v a vertex
*
* @return unordered_set of adjacent vertices
*/
std::unordered_set<int> ALDigraph::adjacent(int v) const {
  assert(v < graph_size && v >= 0);
  return graph[v];  
}

/**
* @brief add new edge to the graph between given vertices
* comlexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
*/
void ALDigraph::add_edge(int v_1, int v_2){

  assert(v_1 < graph_size && v_1 >= 0);
  assert(v_2 < graph_size && v_2 >= 0);

  graph[v_1].insert(v_2);  
}

/**
* @brief returns pointer to a new graph with reversed edges
*
* @return new graph with reversed edges
*/
ALDigraph* ALDigraph::reverse(){
  ALDigraph* reversed_graph = new ALDigraph(graph_size);
  for(int i = 0; i < graph_size; i++){
    for(int j : this->adjacent(i)){
      reversed_graph->add_edge(j, i);
    }  
  }
  return reversed_graph;
}

