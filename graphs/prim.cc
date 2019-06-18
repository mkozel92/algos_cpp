#include<unordered_set>
#include<memory>
#include"edge.h"
#include"graph.h"
#include"prim.h"


/**
* @brief visit a vertex -> add all adjacent edges to the min heap
*
* @param v vertex to visit
* @param a_graph graph to process
* @param visited vector of visited vertices
* @param bh min heap that keeps sorted edges
*/
void visit(int v, const WeightedGraph &a_graph, \
           std::vector<bool> *visited, BinaryHeap<edge_ptr> *bh) {
  (*visited)[v] = true;
  for (const auto &e: a_graph.adjacent(v)) {
    int v_1 = e->either();
    int v_2 = e->other(v_1);
    if (!(*visited)[v_1] || !(*visited)[v_2]) {
      bh->Insert(e);
    }
  }
}


/**
* @brief prim algo to compute MSt
* iteratively add shortest edge that connectes current mst
* with a vertex outside of mst
* complexity O((E + V) log V) ..every edge E inserts a vertex to a mh log V +
* every vertex V is removed from the mh log V E log V + V log V
*
* @param a_graph a graph to process
*
* @return set of edges that are in MST
*/
std::unordered_set<edge_ptr> prim(const WeightedGraph &a_graph) {
  std::vector<bool> visited(a_graph.graph_size, false);
  BinaryHeap<edge_ptr> bh([](edge_ptr e_1, \
                             edge_ptr e_2)\
 -> bool { return *e_1 < *e_2; });
  std::unordered_set<edge_ptr> mst;

  visit(0, a_graph, &visited, &bh);

  while (!bh.IsEmpty()) {
    edge_ptr e = bh.Remove();
    int v_1 = e->either();
    int v_2 = e->other(v_1);
    if (!visited[v_1] || !visited[v_2]) {
      if (!visited[v_1])
        visit(v_1, a_graph, &visited, &bh);
      else
        visit(v_2, a_graph, &visited, &bh);
      mst.insert(e);
    }
  }
  return mst;
}


