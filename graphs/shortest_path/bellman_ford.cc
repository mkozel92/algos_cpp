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

  for (auto edge : a_graph.Adjacent(vertex)) {
    if ((*distance_to)[vertex] + edge->GetWeight() < (*distance_to)[edge->To()]) {
      (*distance_to)[edge->To()] = (*distance_to)[vertex] + edge->GetWeight();
      (*visited_from)[edge->To()] = vertex;
      updated->insert(edge->To());
    }
  }
}

/**
 * find shortest paths using Bellman Ford Algo
 * complexity O((V+E)^2)
 * @param a_graph a graph to process
 * @param distance_to current shortest distances to vertices
 * @param visited_from current shortest paths to vertices
 */
void BellmanFord(const WeightedDigraph &a_graph, std::vector<float> *distance_to, \
                  std::vector<int> *visited_from) {

  std::unordered_set<int> to_relax;
  std::unordered_set<int> updated;
  to_relax.insert(0);
  for (int i = 0; i < a_graph.Size(); i++) {
    for (auto v : to_relax) {
      Relax(v, a_graph, distance_to, visited_from, &updated);
    }
    to_relax = updated;
    updated.clear();
  }

}
} // bellman fortd


