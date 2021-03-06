#include<stack>
#include<vector>
#include"graph.h"
#include"topological_sort.h"


/**
* @brief performs dfs and places processed vertices on a stack
* this topologically sorts and acyclic graph
*
* @param a_graph graph to sort
* @param vertex initial vertex
* @param a_stack stack to store sorted graph
* @param visited vector that keeps track of visited vertices
*/
void RecursiveTopologicalSort(const Digraph &a_graph, int vertex, \
                                std::stack<int> *a_stack, \
                                std::vector<bool> *visited) {
  if ((*visited)[vertex]) {
    return;
  }
  (*visited)[vertex] = true;
  for (int v : a_graph.Adjacent(vertex)) {
    RecursiveTopologicalSort(a_graph, v, a_stack, visited);
  }
  a_stack->push(vertex);
}


/**
* @brief topologically sort given graph
* complexity o(E + V)
*
* @param a_graph graph to sort
* @param a_stack stack to keep sorted graph
*/
void TopologicalSort(const Digraph &a_graph, std::stack<int> *a_stack) {
  std::vector<bool> visited(a_graph.Size(), false);
  for (int i = 0; i < visited.size(); i++) {
    if (!visited[i]) {
      RecursiveTopologicalSort(a_graph, i, a_stack, &visited);
    }
  }
}

