//
// Created by michal on 17/06/19.
//

#ifndef ALGOS_GRAPHS_SHORTEST_PATH_TOP_SORT_SEARCH_H_
#define ALGOS_GRAPHS_SHORTEST_PATH_TOP_SORT_SEARCH_H_

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
             std::vector<bool> *visited);

/**
 * relax a vertex
 * @param vertex vertex to relax
 * @param a_graph graph to process
 * @param distance_to current shortest distances to vertices
 * @param visited_from current shoretes paths to vertices
 */
void Relax(int vertex, const WeightedDigraph &a_graph, \
           std::vector<float> *distance_to, \
           std::vector<int> *visited_from);

/**
 * find shortest paths in acyclic graph by relaxing vertices in their topological order
 * top sort complexity O(V)
 * complexity O(V + E)
 * @param a_graph
 * @param distance_to
 * @param visited_from
 */
void ShortestPath(const WeightedDigraph &a_graph, std::vector<float> *distance_to, \
                  std::vector<int> *visited_from);
} // top_sort search


#endif //ALGOS_GRAPHS_SHORTEST_PATH_TOP_SORT_SEARCH_H_
