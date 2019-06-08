#ifndef GRAPH_INTERFACE
#define GRAPH_INTERFACE

#include<unordered_set>

/**
* @brief interface for graph implementations
*/
class Graph{
  public:
    int graph_size;
    Graph(int size) : graph_size(size) {};
    virtual std::unordered_set<int> adjacent(int) const = 0;
    virtual void add_edge(int, int) = 0;
};


/**
* @brief interface for Digraph implementations
*/
class Digraph{
  public:
    int graph_size;
    Digraph(int size) : graph_size(size) {};
    virtual std::unordered_set<int> adjacent(int) const = 0;
    virtual void add_edge(int, int) = 0;
    virtual Digraph *reverse() = 0;
};


#endif
