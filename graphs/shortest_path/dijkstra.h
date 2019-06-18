#include"../graph.h"
#include<vector>
#include"../../data_structures/binary_heap.h"
#include<utility>

/**
* @brief relax edges Adjacent to given vertex
*
* @param a_graph a graph to process
* @param v vertex to relax
* @param visited vector of visited vertices
* @param edge_to vector of paths to vertices
* @param distance shortest distances to vertices
* @param bh min heap with next closest vertices
*/
void Relax(const WeightedDigraph &a_graph, int v, std::vector<bool> *visited, \
              std::vector<int> *edge_to, std::vector<float> *distance, \
              BinaryHeap<std::pair<float, int>> *bh);

/**
* @brief Dijkstra algo to find shortest path
* iteratively relax all edges Adjacent to a currently closest unvisited vertex
* complexity O((E + V) log V) ..V times remove a vertex from a min heap
* and E times push new vertex to the heap
*
* @param a_graph
* @param visited
* @param edge_to
* @param distance
*/
void Dijkstra(const WeightedDigraph &a_graph, std::vector<bool> *visited, \
              std::vector<int> *edge_to, std::vector<float> *distance); 
  
