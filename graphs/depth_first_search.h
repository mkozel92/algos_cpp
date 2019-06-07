#include"graph.h"
#include<vector>
#include<stack>

/**
* @brief recursive implementation of dfs
* complexity O(E + V)
*
* @param g graph to search
* @param visited vector of visited vertices
* @param visited_from keeps track of path to the vertices
* @param v initial vertex
* @param from_ from which vertex the recursive call is comming
*/
void recursive_dfs(const Graph& g, std::vector<bool> *visited,\
                   std::vector<int> *visited_from, int v, int from_ ){
  if ((*visited)[v]){
    return;  
  }
  (*visited)[v] = true;
  (*visited_from)[v] = from_;
  for(auto vertex: g.adjacent(v)){
    recursive_dfs(g, visited, visited_from, vertex, v);  
  }
}


/**
* @brief iterative implementation of dfs
* complexity O(E + V)
*
* @param g graph to search
* @param visited vector of visited vertices
* @param visited_from keeps track of paths to the veritces
* @param v initial vertex
*/
void iterative_dfs(const Graph &g, std::vector<bool> *visited,\
                   std::vector<int> *visited_from, int v){
    std::stack<int> s;
    (*visited)[v] = true;
    s.push(v);

    while(!s.empty()){
      int top = s.top();
      s.pop();
      for (auto vertex : g.adjacent(top)){
        if(!(*visited)[vertex]){
          (*visited)[vertex] = true;  
          (*visited_from)[vertex] = top;
          s.push(vertex);
        } 
      }
    }
}


