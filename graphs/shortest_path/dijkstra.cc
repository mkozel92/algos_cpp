#include"../graph.h"
#include<vector>
#include"../../data_structures/binary_heap.h"
#include"dijkstra.h"
#include<utility>

/**
* @brief relax edges adjacent to given vertex
*
* @param a_graph a graph to process
* @param v vertex to relax
* @param visited vector of visited vertices
* @param edge_to vector of paths to vertices
* @param distance shortest distances to vertices
* @param bh min heap with next closest vertices
*/
void relax(const WeightedDigraph &a_graph, int v, std::vector<bool> *visited, \
              std::vector<int> *edge_to, std::vector<float> *distance, \
              BinaryHeap<std::pair<float, int>> *bh) {
  (*visited)[v] = true;
  for (const auto& e: a_graph.adjacent(v)) {
    int to = e->to();
    if (!(*visited)[to]) {
      if (e->get_weight() + (*distance)[v] < (*distance)[to]) {
        (*distance)[to] = e->get_weight() + (*distance)[v];
        (*edge_to)[to] = v;
      }
      bh->insert(std::make_pair((*distance)[to], to));
    }
  }
}


/**
* @brief Dijkstra algo to find shortest path
* iteratively relax all edges adjacent to a currently closest unvisited vertex
* complexity O((E + V) log V) ..V times remove a vertex from a min heap
* and E times push new vertex to the heap
*
* @param a_graph
* @param visited
* @param edge_to
* @param distance
*/
void dijkstra(const WeightedDigraph &a_graph, std::vector<bool> *visited, \
              std::vector<int> *edge_to, std::vector<float> *distance) {

  BinaryHeap<std::pair<float, int>> bh([](std::pair<float, int> a, \
                                          std::pair<float, int> b) -> bool \
 { return a.first < b.first; });
  bh.insert(std::make_pair(0.0f, 0));
  while (!bh.is_empty()) {
    std::pair<float, int> a_pair = bh.remove();
    if (!(*visited)[a_pair.second])
      relax(a_graph, a_pair.second, visited, edge_to, distance, &bh);
  }
}





