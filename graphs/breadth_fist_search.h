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
void iterative_dfs(const Graph &g, std::vector<bool> *visited,\
                   std::vector<int> *visited_from, int v){
    std::queue<int> s;
    (*visited)[v] = true;
    s.push_back(v);

    while(!s.empty()){
      int front = s.front();
      s.pop_front();
      for (auto vertex : g.adjacent(front)){
        if(!(*visited)[vertex]){
          (*visited)[vertex] = true;  
          (*visited_from)[vertex] = front;
          s.push_back(vertex);
        } 
      }
    }
}


#endif //  ALGOS_GRAPHS_BREADTH_FIRST_SEARCH_H_
