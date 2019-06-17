//
// Created by michal on 17/06/19.
//

#ifndef ALGOS_GRAPHS_GRAPH_CLASSIFICATION_ALGOS_H_
#define ALGOS_GRAPHS_GRAPH_CLASSIFICATION_ALGOS_H_

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
                  int vertex, int group);

/**
 * check if given digraph has cycle
 * @param a_graph digraph to process
 * @param vertex currently processed vertex
 * @param visited list of visited vertices
 * @param currently_processed set of currently processed vertices
 * @return True if DFS tries to visit one of currently processed vertices
 */
bool HasCycleDfs(const Digraph &a_graph, int vertex, std::vector<bool> *visited, \
                 std::unordered_set<int> *currently_processed);

/**
 * check if graph id Bipartite using DFS
 * @param a_graph graph to check
 * @return true if given graph is bipartite
 */
bool IsBipartite(const Graph &a_graph);

/**
 * check if graph has cycle using DFS
 * @param a_graph graph to check
 * @return true if there is a cycle in given graph
 */
bool HasCycle(const Digraph &a_graph);

/**
 * check if graph has Euler Tour by checking the degrees of all vertices
 * @param a_graph graph to check
 * @return true if there is Euler tour
 */
bool HasEulerTour(const Graph &a_graph);

#endif //ALGOS_GRAPHS_GRAPH_CLASSIFICATION_ALGOS_H_
