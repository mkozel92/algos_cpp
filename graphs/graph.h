#ifndef ALGOS_GRAPHS_GRAPH_H_
#define ALGOS_GRAPHS_GRAPH_H_

#include<memory>
#include<unordered_set>
#include"edge.h"

/**
* @brief interface for graph implementations
*/
class Graph{
  public:
    const int graph_size;
    Graph(int size) : graph_size(size) {};
    virtual std::unordered_set<int> adjacent(int) const = 0;
    virtual void add_edge(int, int) = 0;
};


/**
* @brief interface for Digraph implementations
*/
class Digraph{
  public:
    const int graph_size;
    Digraph(int size) : graph_size(size) {};
    virtual std::unordered_set<int> adjacent(int) const = 0;
    virtual void add_edge(int, int) = 0;
    virtual Digraph *reverse() = 0;
};


/**
* @brief interface for Digraph implementations
*/
class WeightedGraph{
  public:
    const int graph_size;
    WeightedGraph(int size) : graph_size(size) {};
    virtual std::unordered_set<std::shared_ptr<Edge>> adjacent(int) const = 0;
    virtual std::unordered_set<std::shared_ptr<Edge>> get_edges() const = 0;
    virtual void add_edge(int, int, float) = 0;
};


#endif // ALGOS_GRAPHS_GRAPH_H_
