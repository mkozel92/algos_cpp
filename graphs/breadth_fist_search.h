#ifndef ALGOS_GRAPHS_BREADTH_FIRST_SEARCH_H_
#define ALGOS_GRAPHS_BREADTH_FIRST_SEARCH_H_


#include"graph.h"
#include<vector>
#include<queue>


/**
* @brief iterative implementation of bfs
* complexity O(E + V)
*
* @param g graph to search
* @param visited vector of visited vertices
* @param visited_from keeps track of paths to the veritces
* @param v initial vertex
*/
void IterativeBfs(const Graph &g, std::vector<bool> *visited, \
                   std::vector<int> *visited_from, int v) {
  std::queue<int> s;
  (*visited)[v] = true;
  s.push(v);

  while (!s.empty()) {
    int front = s.front();
    s.pop();
    for (auto vertex : g.Adjacent(front)) {
      if (!(*visited)[vertex]) {
        (*visited)[vertex] = true;
        (*visited_from)[vertex] = front;
        s.push(vertex);
      }
    }
  }
}


#endif //  ALGOS_GRAPHS_BREADTH_FIRST_SEARCH_H_
