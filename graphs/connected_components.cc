#include"connected_components.h"

/**
* @brief computes connected components 
* complexity O(N)
*/
void ConnectedComponents::compute() {
  int current_group = 0;
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      dfs(i, current_group);
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
void ConnectedComponents::dfs(int p, int group) {
  if (visited[p]) {
    return;
  }
  visited[p] = true;
  vertex_group[p] = group;
  for (auto v: g->adjacent(p)) {
    dfs(v, group);
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
bool ConnectedComponents::is_connected(int p, int q) {
  return vertex_group[p] == vertex_group[q];
}


