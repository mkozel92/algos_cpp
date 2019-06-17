//
// Created by michal on 17/06/19.
//

#include "bellman_ford.h"
#include "top_sort_search.h"
#include "../adjacency_list_weighted_digraph.h"
#include "../graph.h"
#include <vector>
#include <iostream>
#include <unordered_set>

namespace bellman_ford {

/**
 * relax a vertex
 * @param vertex vertex to relax
 * @param a_graph graph to process
 * @param distance_to current shortest distances to vertices
 * @param visited_from current shortest paths to vertices
 */
void Relax(int vertex, const WeightedDigraph &a_graph, \
           std::vector<float> *distance_to, \
           std::vector<int> *visited_from,
           std::unordered_set<int> *updated) {

  for (auto edge : a_graph.adjacent(vertex)) {
    if ((*distance_to)[vertex] + edge->get_weight() < (*distance_to)[edge->to()]) {
      (*distance_to)[edge->to()] = (*distance_to)[vertex] + edge->get_weight();
      (*visited_from)[edge->to()] = vertex;
      updated->insert(edge->to());
    }
  }
}

/**
 * find shortest paths using Bellman Ford Algo
 * complexity O((V+E)^2)
 * @param a_graph a graph to process
 * @param distance_to current shortest distances to vertices
 * @param visited_from current shorest paths to vertices
 */
void BellmanFord(const WeightedDigraph &a_graph, std::vector<float> *distance_to, \
                  std::vector<int> *visited_from) {

  const int size = a_graph.graph_size;
  std::unordered_set<int> to_relax;
  std::unordered_set<int> updated;
  to_relax.insert(0);
  for (int i = 0; i < size; i++) {
    for (auto v : to_relax) {
      Relax(v, a_graph, distance_to, visited_from, &updated);
    }
    to_relax = updated;
    updated.clear();
  }

}
} // top_sort search


