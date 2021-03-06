#include<vector>
#include<unordered_set>
#include<memory>
#include<algorithm>
#include"edge.h"
#include"graph.h"
#include"../dynamic_connectivity/weighted_quick_union.h"
#include"kruskal.h"


/**
* @brief comparator for pointers to edges
*
* @param edge_1 pointer to first edge
* @param edge_2 pointer to second edge
*
* @return true if the second is bigger
*/
bool CompareEdgePointers(const std::shared_ptr<Edge>& edge_1, \
                       const std::shared_ptr<Edge>& edge_2) {
  return *edge_1 < *edge_2;
}

/**
* @brief Kruskal algo to find mst
* complexity O(E log E)
*
* @param a_graph grap to compute mst for
*
* @return set of edges that are in mst
*/
std::unordered_set<std::shared_ptr<Edge>> Kruskal(const WeightedGraph &a_graph) {
  std::vector<std::shared_ptr<Edge>> edges;
  WeightedQuickUnion wqu(a_graph.Size());
  std::unordered_set<std::shared_ptr<Edge>> mst;
  for (const auto& e: a_graph.GetEdges()) {
    edges.push_back(e);
  }
  sort(edges.begin(), edges.end(), CompareEdgePointers);

  for (const auto& e : edges) {
    int v_1 = e->Either();
    int v_2 = e->Other(v_1);
    if (!wqu.Connected(v_1, v_2)) {
      wqu.Union(v_1, v_2);
      mst.insert(e);
    }
  }
  return mst;
}

