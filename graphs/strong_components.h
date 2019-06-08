#include"graph.h"
#include<vector>
#include<stack>

/**
* @brief class that keep track of strong components of a given graph
*/
class StrongComponents{
  private:
    Digraph* g;
    std::vector<int> vertex_group;
    std::vector<bool> visited;
  public:
    StrongComponents(Digraph* g) : g(g), vertex_group(g->graph_size, 0),\
                                     visited(g->graph_size, false) {};
    void compute();
    void dfs(Digraph*, int, int, std::stack<int>*);
    bool is_connected(int, int);
};


