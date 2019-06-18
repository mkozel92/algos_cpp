#include"connected_components.h"

/**
* @brief computes connected components 
* complexity O(N)
*/
void ConnectedComponents::Compute() {
  int current_group = 0;
  for (int i = 0; i < visited_.size(); i++) {
    if (!visited_[i]) {
      Dfs(i, current_group);
      current_group += 1;
    }
  }
}

/**
* @brief dfs to assign each vertex to a connected component
*
* @param p initial unassigned vertex
* @param group current vertex group
*/
void ConnectedComponents::Dfs(int p, int group) {
  if (visited_[p]) {
    return;
  }
  visited_[p] = true;
  vertex_group_[p] = group;
  for (auto v: a_graph_->Adjacent(p)) {
    Dfs(v, group);
  }

}

/**
* @brief check of two vertices are connected
*
* @param p firt vertex
* @param q second vertex
*
* @return true of there is a pathe between given vertices
*/
bool ConnectedComponents::IsConnected(int p, int q) {
  return vertex_group_[p] == vertex_group_[q];
}


