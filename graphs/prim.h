#include<unordered_set>
#include<memory>
#include"edge.h"
#include"graph.h"
#include"../data_structures/binary_heap.h"
#include<iostream>

typedef std::shared_ptr<Edge> edge_ptr;

/**
* @brief visit a vertex -> add all adjacent edges to the min heap
*
* @param int vertex to visit
* @param WeightedGraph graph to process
* @param std::vector visited vertices
* @param BinaryHeap heap to keep edges ordered by weight
*/
void visit(int, const WeightedGraph&,\
           std::vector<bool>*, BinaryHeap<edge_ptr>*);

/**
* @brief prim algo to comupute mst
*
* @param WeightedGraph graph to process
*
* @return set of edges that are in mst
*/
std::unordered_set<edge_ptr> prim(const WeightedGraph&);

