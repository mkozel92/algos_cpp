#ifndef ALGOS_GRAPHS_GRAPH_H_
#define ALGOS_GRAPHS_GRAPH_H_

#include<memory>
#include<unordered_set>
#include"edge.h"
#include"directed_edge.h"

/**
* @brief interface for graph implementations
*/
class Graph {
public:
  explicit Graph(int size) : graph_size(size) {};
  const int graph_size;

  virtual std::unordered_set<int> adjacent(int) const = 0;

  virtual void add_edge(int, int) = 0;
};


/**
* @brief interface for Digraph implementations
*/
class Digraph {
public:
  explicit Digraph(int size) : graph_size(size) {};
  const int graph_size;

  virtual std::unordered_set<int> adjacent(int) const = 0;

  virtual void add_edge(int, int) = 0;

  virtual Digraph *reverse() = 0;
};


/**
* @brief interface for Digraph implementations
*/
class WeightedGraph {
public:
  explicit WeightedGraph(int size) : graph_size(size) {};
  const int graph_size;

  virtual std::unordered_set<std::shared_ptr<Edge>> adjacent(int) const = 0;

  virtual std::unordered_set<std::shared_ptr<Edge>> get_edges() const = 0;

  virtual void add_edge(int, int, float) = 0;
};


/**
* @brief interface for Weighted Digraph implementations
*/
class WeightedDigraph {
public:
  explicit WeightedDigraph(int size) : graph_size(size) {};
  const int graph_size;

  virtual std::unordered_set<std::shared_ptr<DirectedEdge>> adjacent(int) const = 0;

  virtual std::unordered_set<std::shared_ptr<DirectedEdge>> get_edges() const = 0;

  virtual void add_edge(int, int, float) = 0;
};


#endif // ALGOS_GRAPHS_GRAPH_H_
