#ifndef ALGOS_GRAPHS_GRAPH_H_
#define ALGOS_GRAPHS_GRAPH_H_

#include<memory>
#include<unordered_set>
#include"edge.h"
#include"directed_edge.h"

class GraphBase {
private:
  const int number_of_vertices_;
public:
  explicit GraphBase(int size) : number_of_vertices_(size) {};

  int Size() const { return number_of_vertices_; }

};


/**
* @brief interface for graph implementations
*/
class Graph : public GraphBase {
public:
  explicit Graph(int size) : GraphBase(size) {};

  virtual std::unordered_set<int> Adjacent(int) const = 0;

  virtual void AddEdge(int, int) = 0;
};


/**
* @brief interface for Digraph implementations
*/
class Digraph : public GraphBase {
public:
  explicit Digraph(int size) : GraphBase(size) {};

  virtual std::unordered_set<int> Adjacent(int) const = 0;

  virtual void AddEdge(int, int) = 0;

  virtual Digraph *Reverse() = 0;
};


/**
* @brief interface for Digraph implementations
*/
class WeightedGraph : public GraphBase {
public:
  explicit WeightedGraph(int size) : GraphBase(size) {};

  virtual std::unordered_set<std::shared_ptr<Edge>> Adjacent(int) const = 0;

  virtual std::unordered_set<std::shared_ptr<Edge>> GetEdges() const = 0;

  virtual void AddEdge(int, int, float) = 0;
};


/**
* @brief interface for Weighted Digraph implementations
*/
class WeightedDigraph : public GraphBase {
public:
  explicit WeightedDigraph(int size) : GraphBase(size) {};

  virtual std::unordered_set<std::shared_ptr<DirectedEdge>> Adjacent(int) const = 0;

  virtual std::unordered_set<std::shared_ptr<DirectedEdge>> GetEdges() const = 0;

  virtual void AddEdge(int, int, float) = 0;
};


#endif // ALGOS_GRAPHS_GRAPH_H_
