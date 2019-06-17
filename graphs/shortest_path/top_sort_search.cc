//
// Created by michal on 17/06/19.
//

#include "top_sort_search.h"
#include "../adjacency_list_weighted_digraph.h"
#include "../graph.h"
#include <vector>
#include <stack>
#include <iostream>


namespace top_sort_search {
/**
 * topologically sort given graph
 * @param vertex starting vertex
 * @param a_graph graph to sort
 * @param top_sorted stack holding topologically sorted vertices
 * @param visited vector of visited vertices
 */
void TopSort(int vertex, const WeightedDigraph &a_graph, std::stack<int> *top_sorted, \
             std::vector<bool> *visited) {
  if ((*visited)[vertex])
    return;

  for (auto v : a_graph.adjacent(vertex)) {
    TopSort(v->to(), a_graph, top_sorted, visited);
  }
  top_sorted->push(vertex);
}

/**
 * relax a vertex
 * @param vertex vertex to relax
 * @param a_graph graph to process
 * @param distance_to current shortest distances to vertices
 * @param visited_from current shoretes paths to vertices
 */
void Relax(int vertex, const WeightedDigraph &a_graph, \
           std::vector<float> *distance_to, \
           std::vector<int> *visited_from) {

  for (auto edge : a_graph.adjacent(vertex)) {
    if ((*distance_to)[vertex] + edge->get_weight() < (*distance_to)[edge->to()]) {
      (*distance_to)[edge->to()] = (*distance_to)[vertex] + edge->get_weight();
      (*visited_from)[edge->to()] = vertex;
    }
  }
}

/**
 * find shortest paths in acyclic graph by relaxing vertices in their topological order
 * top sort complexity O(V)
 * complexity O(V + E)
 * @param a_graph
 * @param distance_to
 * @param visited_from
 */
void ShortestPath(const WeightedDigraph &a_graph, std::vector<float> *distance_to, \
                  std::vector<int> *visited_from) {

  const int size = a_graph.graph_size;
  std::vector<bool> visited(size, false);

  std::stack<int> top_sorted;
  TopSort(0, a_graph, &top_sorted, &visited);

  while (!top_sorted.empty()) {
    int top = top_sorted.top();
    top_sorted.pop();
    Relax(top, a_graph, distance_to, visited_from);
  }
}
} // top_sort search
