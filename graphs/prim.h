#include<unordered_set>
#include<memory>
#include"edge.h"
#include"graph.h"
#include"../data_structures/binary_heap.h"
#include<iostream>

typedef std::shared_ptr<Edge> EdgePtr;

/**
* @brief visit a vertex -> add all Adjacent edges to the min heap
*
* @param int vertex to visit
* @param WeightedGraph graph to process
* @param std::vector visited vertices
* @param BinaryHeap heap to keep edges ordered by weight
*/
void Visit(int, const WeightedGraph &, \
           std::vector<bool> *, BinaryHeap<EdgePtr> *);

/**
* @brief prim algo to compute mst
*
* @param WeightedGraph graph to process
*
* @return set of edges that are in mst
*/
std::unordered_set<EdgePtr> Prim(const WeightedGraph &);

