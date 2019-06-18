#ifndef ALGOS_GRAPHS_KRUSKAL_H_
#define ALGOS_GRAPHS_KRUSKAL_H_

#include<unordered_set>
#include<memory>
#include"edge.h"
#include"graph.h"


/**
* @brief comparater function for pointer to edges
*
* @param std::shared_ptr pointer to first edge
* @param std::shared_ptr pointer to second edge
*
* @return True if first is bigger
*/
bool CompareEdgePointers(const std::shared_ptr<Edge> &, \
                       const std::shared_ptr<Edge> &);

/**
* @brief kruskal algo to compute mst
*
* @param WeightedGraph a weighted graph to compute mst for
*
* @return set of mst edges
*/
std::unordered_set<std::shared_ptr<Edge>> Kruskal(const WeightedGraph &);


#endif // ALGOS_GRAPHS_KRUSKAL_H_
