#include"strong_components.h"
#include<stack>

/**
* @brief computes strong components 
* complexity O(N)
*/
void StrongComponents::Compute() {
  std::stack<int> a_stack;
  Digraph *reversed = a_graph_->Reverse();
  for (int i = 0; i < visited_.size(); i++) {
    if (!visited_[i]) {
      Dfs(reversed, i, 0, &a_stack);
    }
  }

  for (int j = 0; j < visited_.size(); j++) {
    visited_[j] = false;
  }

  int current_group = 0;
  int i;
  std::stack<int> tmp;
  while (!a_stack.empty()) {
    i = a_stack.top();
    a_stack.pop();
    if (!visited_[i]) {
      Dfs(a_graph_, i, current_group, &tmp);
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
void StrongComponents::Dfs(Digraph *a_graph, int p, \
                           int group, std::stack<int> *a_stack) {
  if (visited_[p]) {
    return;
  }
  visited_[p] = true;
  vertex_group_[p] = group;
  for (auto v: a_graph->Adjacent(p)) {
    Dfs(a_graph, v, group, a_stack);
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
bool StrongComponents::IsConnected(int p, int q) {
  return vertex_group_[p] == vertex_group_[q];
}

