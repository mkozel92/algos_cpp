#include"adjacency_list_digraph.h"

/**
* @brief get all vertices Adjacent to given vertex
* complexity O(1)
*
* @param v a vertex
*
* @return unordered_set of Adjacent vertices
*/
std::unordered_set<int> ALDigraph::Adjacent(int v) const {
  assert(v < Size() && v >= 0);
  return graph_[v];
}

/**
* @brief add new edge to the graph between given vertices
* comlexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
*/
void ALDigraph::AddEdge (int v_1, int v_2) {

  assert(v_1 < Size() && v_1 >= 0);
  assert(v_2 < Size() && v_2 >= 0);

  graph_[v_1].insert(v_2);
}

/**
* @brief returns pointer to a new graph with reversed edges
*
* @return new graph with reversed edges
*/
ALDigraph *ALDigraph::Reverse() {
  auto reversed_graph = new ALDigraph(Size());
  for (int i = 0; i < Size(); i++) {
    for (int j : this->Adjacent(i)) {
      reversed_graph->AddEdge(j, i);
    }
  }
  return reversed_graph;
}

