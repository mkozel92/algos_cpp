#include"adjacency_list_weighted_graph.h"
#include<memory>

/**
* @brief get all vertices Adjacent to given vertex
* complexity O(1)
*
* @param v a vertex
*
* @return unordered_set of Adjacent vertices
*/
std::unordered_set<std::shared_ptr<Edge>> ALWGraph::Adjacent(int v) const {
  assert(v < Size());
  return graph_[v];
}

/**
* @brief add new edge to the graph between given vertices
* comlexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
* @param weight weight of the edge
*/
void ALWGraph::AddEdge(int v_1, int v_2, float weight) {

  assert(v_1 < Size());
  assert(v_2 < Size());

  std::shared_ptr<Edge> new_edge = std::make_shared<Edge>(v_1, v_2, weight);
  graph_[v_1].insert(new_edge);
  graph_[v_2].insert(new_edge);
  edges_.insert(new_edge);
}

std::unordered_set<std::shared_ptr<Edge>> ALWGraph::GetEdges() const {
  return edges_;
}


