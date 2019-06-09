#include"adjacency_list_weighted_graph.h"
#include<memory>

/**
* @brief get all vertices adjacent to given vertex
* complexity O(1)
*
* @param v a vertex
*
* @return unordered_set of adjacent vertices
*/
std::unordered_set<std::shared_ptr<Edge>> ALWGraph::adjacent(int v) const {
  assert(v < graph_size);
  return graph[v];  
}

/**
* @brief add new edge to the graph between given vertices
* comlexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
* @param weight weight of the edge
*/
void ALWGraph::add_edge(int v_1, int v_2, float weight){

  assert(v_1 < graph_size);
  assert(v_2 < graph_size);
  
  std::shared_ptr<Edge> new_edge = std::make_shared<Edge>(v_1, v_2, weight);
  graph[v_1].insert(new_edge);  
  graph[v_2].insert(new_edge);
  edges.insert(new_edge);
}

std::unordered_set<std::shared_ptr<Edge>> ALWGraph::get_edges() const {
  return edges;  
}

