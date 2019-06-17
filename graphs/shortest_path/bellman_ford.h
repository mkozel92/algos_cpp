//
// Created by michal on 17/06/19.
//

#ifndef ALGOS_GRAPHS_SHORTEST_PATH_BELLMAN_FORD_H_
#define ALGOS_GRAPHS_SHORTEST_PATH_BELLMAN_FORD_H_

#include "../adjacency_list_weighted_digraph.h"
#include "../graph.h"
#include <vector>
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
           std::unordered_set<int> *updated);

/**
 * find shortest paths using Bellman Ford Algo
 * complexity O((V+E)^2)
 * @param a_graph a graph to process
 * @param distance_to current shortest distances to vertices
 * @param visited_from current shorest paths to vertices
 */
void BellmanFord(const WeightedDigraph &a_graph, std::vector<float> *distance_to, \
                  std::vector<int> *visited_from);
} // top_sort search


#endif //ALGOS_GRAPHS_SHORTEST_PATH_BELLMAN_FORD_H_
