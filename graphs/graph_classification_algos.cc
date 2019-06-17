//
// Created by michal on 17/06/19.
//

#include "graph_classification_algos.h"
#include <vector>
#include "graph.h"
#include "adjacency_list_graph.h"
#include <iostream>
#include <unordered_set>
#include "adjacency_list_digraph.h"

/**
 * check if given graph is bipartite by
 * @param a_graph graph to process
 * @param groups group for every vertex (0 , 1)
 * @param vertex current vertex
 * @param group correct group of current vertex
 * @return True if all vertices belong to correct group
 */
bool BipartiteDfs(const Graph &a_graph, std::vector<int> *groups, \
                  int vertex, int group) {
  if ((*groups)[vertex] != -1) {
    return (*groups)[vertex] == group;
  }
  (*groups)[vertex] = group;
  for (auto v : a_graph.adjacent(vertex)) {
    if (!BipartiteDfs(a_graph, groups, v, (group + 1) % 2))
      return false;
  }
  return true;
}

/**
 * check if given digraph has cycle
 * @param a_graph digraph to process
 * @param vertex currently processed vertex
 * @param visited list of visited vertices
 * @param currently_processed set of currently processed vertices
 * @return True if DFS tries to visit one of currently processed vertices
 */
bool HasCycleDfs(const Digraph &a_graph, int vertex, std::vector<bool> *visited, \
                 std::unordered_set<int> *currently_processed) {
  if ((*visited)[vertex]) {
    return currently_processed->find(vertex) != currently_processed->end();
  }

  (*visited)[vertex] = true;
  currently_processed->insert(vertex);
  for (auto v : a_graph.adjacent(vertex)) {
    if (HasCycleDfs(a_graph, v, visited, currently_processed))
      return true;
  }
  currently_processed->erase(vertex);
  return false;
}


/**
 * check if graph id Bipartite using DFS
 * @param a_graph graph to check
 * @return true if given graph is bipartite
 */
bool IsBipartite(const Graph &a_graph) {
  std::vector<int> groups(a_graph.graph_size, -1);
  return BipartiteDfs(a_graph, &groups, 0, 0);
}

/**
 * check if graph has cycle using DFS
 * @param a_graph graph to check
 * @return true if there is a cycle in given graph
 */
bool HasCycle(const Digraph &a_graph) {
  std::unordered_set<int> currently_processed;
  std::vector<bool> visited(a_graph.graph_size, false);
  return HasCycleDfs(a_graph, 0, &visited, &currently_processed);
}

/**
 * check if graph has Euler Tour by checking the degrees of all vertices
 * @param a_graph graph to check
 * @return true if there is Euler tour
 */
bool HasEulerTour(const Graph &a_graph) {
  for (int i = 0; i < a_graph.graph_size; i++) {
    if (a_graph.adjacent(i).size() % 2 != 0)
      return false;
  }
  return true;
}
