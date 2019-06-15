#include"strong_components.h"
#include<stack>

/**
* @brief computes strong components 
* complexity O(N)
*/
void StrongComponents::compute() {
  std::stack<int> a_stack;
  Digraph *reversed = g->reverse();
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      dfs(reversed, i, 0, &a_stack);
    }
  }

  for (int j = 0; j < visited.size(); j++) {
    visited[j] = false;
  }

  int current_group = 0;
  int i;
  std::stack<int> tmp;
  while (!a_stack.empty()) {
    i = a_stack.top();
    a_stack.pop();
    if (!visited[i]) {
      dfs(g, i, current_group, &tmp);
      current_group += 1;
    }
  }
}

/**
* @brief dfs to assign each vertex to a strong component
*
* @param p initial unassigned vertex
* @param group current vertex group
*/
void StrongComponents::dfs(Digraph *a_graph, int p, \
                           int group, std::stack<int> *a_stack) {
  if (visited[p]) {
    return;
  }
  visited[p] = true;
  vertex_group[p] = group;
  for (auto v: a_graph->adjacent(p)) {
    dfs(a_graph, v, group, a_stack);
  }
  a_stack->push(p);
}

/**
* @brief check of two vertices are connected
*
* @param p firt vertex
* @param q second vertex
*
* @return true of there is a pathe between given vertices
*/
bool StrongComponents::is_connected(int p, int q) {
  return vertex_group[p] == vertex_group[q];
}

