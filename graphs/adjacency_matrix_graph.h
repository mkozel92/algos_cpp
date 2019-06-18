#ifndef ALGOS_GRAPHS_ADJACENCY_MATRIX_GRAPH_H_
#define ALGOS_GRAPHS_ADJACENCY_MATRIX_GRAPH_H_


#include"graph.h"
#include<vector>
#include<cassert>

/**
* @brief graph implemented using adjacency matrix
*/
class AMGraph : public Graph {
public:
  explicit AMGraph(int size) : Graph(size), graph_(size, std::vector<int>(size, 0)) {}

  std::vector<std::vector<int>> graph_;

  std::unordered_set<int> Adjacent(int) const override;

  void AddEdge(int, int) override;
};


/**
* @brief return set of Adjacent verices to given vertex
* complexity O(V)
*
* @param v a vertex
*
* @return unordered_set of Adjacent vertices
*/
std::unordered_set<int> AMGraph::Adjacent(int v) const {

  assert(v < Size() && v >= 0);

  std::unordered_set<int> Adjacent_vertices;
  for (int i = 0; i < Size(); i++) {
    if (graph_[v][i] == 1) {
      Adjacent_vertices.insert(i);
    }
  }
  return Adjacent_vertices;
}

/**
* @brief add new edge to the graph between given vertices
* complexity O(1)
*
* @param v_1 first vertex to connect
* @param v_2 second vertex to connect
*/
void AMGraph::AddEdge(int v_1, int v_2) {
  assert(v_1 < Size() && v_1 >= 0);
  assert(v_2 < Size() && v_2 >= 0);

  graph_[v_1][v_2] = 1;
  graph_[v_2][v_1] = 1;
}

#endif // ALGOS_GRAPHS_ADJACENCY_MATRIX_GRAPH_H_

