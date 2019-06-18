#include"adjacency_list_graph.h"

/**
* @brief get all vertices Adjacent to given vertex
* complexity O(1)
*
* @param v a vertex
*
* @return unordered_set of Adjacent vertices
*/
std::unordered_set<int> ALGraph::Adjacent(int v) const {
  assert(v < Size());
  return graph_[v];
}

/**
* @brief add new edge to the graph between given vertices
* comlexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
*/
void ALGraph::AddEdge(int v_1, int v_2) {

  assert(v_1 < Size());
  assert(v_2 < Size());

  graph_[v_1].insert(v_2);
  graph_[v_2].insert(v_1);
}
