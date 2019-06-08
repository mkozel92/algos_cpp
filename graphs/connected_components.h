#ifndef ALGOS_GRAPHS_CONNECTED_COMPONENTS_H_
#define ALGOS_GRAPHS_CONNECTED_COMPONENTS_H_

#include"graph.h"
#include<vector>


/**
* @brief class that keep track of connected components of a given graph
*/
class ConnectedComponents{
  private:
    Graph* g;
    std::vector<int> vertex_group;
    std::vector<bool> visited;
  public:
    ConnectedComponents(Graph* g) : g(g), vertex_group(g->graph_size, 0),\
                                     visited(g->graph_size, false) {};
    void compute();
    void dfs(int, int);
    bool is_connected(int, int);
};

#endif // ALGOS_GRAPHS_CONNECTED_COMPONENTS_H_
