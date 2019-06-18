#ifndef ALGOS_GRAPHS_DIRECTED_EDGE_H_
#define ALGOS_GRAPHS_DIRECTED_EDGE_H_

#include<cassert>


/**
* @brief implementation of undirected edge
*/
class DirectedEdge {
private:
  const int from_;
  const int to_;
  const float weight_;
public:
  DirectedEdge(int from, int to, float weight) : from_(from), \
                                           to_(to), \
                                           weight_(weight) {};

  /**
  * @brief gets the _from vertex Adjacent to this edge
  *
  * @return a vertex
  */
  int From() {
    return from_;
  };

  /**
  * @brief gets the _to vertex Adjacent to this edge
  *
  * @return a vertex
  */
  int To() {
    return to_;
  }

  /**
  * @brief gets other vertex Adjacent to this edge
  *
  * @param v first vertex
  *
  * @return other Adjacent vertex
  */
  int Other(int v) {
    assert(from_ == v || to_ == v);
    if (to_ == v) {
      return from_;
    }
    return to_;
  };

  /**
  * @return weight of this edge
  */
  float GetWeight() const {
    return weight_;
  }

  bool operator>(const Edge &other) {
    return weight_ > other.GetWeight();
  };

  bool operator>=(const Edge &other) {
    return weight_ >= other.GetWeight();
  };

  bool operator<(const Edge &other) {
    return weight_ < other.GetWeight();
  };

  bool operator<=(const Edge &other) {
    return weight_ <= other.GetWeight();
  };

  bool operator==(const Edge &other) {
    return weight_ == other.GetWeight();
  };

  bool operator!=(const Edge &other) {
    return weight_ != other.GetWeight();
  };
};

#endif // ALGOS_GRAPHS_DIRECTED_EDGE_H_ 
