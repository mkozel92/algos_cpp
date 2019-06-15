#ifndef ALGOS_GRAPHS_EDGE_H_
#define ALGOS_GRAPHS_EDGE_H_

#include<cassert>


/**
* @brief implementation of undirected edge
*/
class Edge {
private:
  const int v_1;
  const int v_2;
  const float weight;
public:
  Edge(int v_1, int v_2, float weight) : v_1(v_1), \
                                           v_2(v_2), \
                                           weight(weight) {};

  /**
  * @brief gets one of the vertices adjacent to this edge
  *
  * @return a vertex
  */
  int either() {
    return v_1;
  };

  /**
  * @brief gets other vertex adjacent to this edge
  *
  * @param v first vertex
  *
  * @return other adjacent vertex
  */
  int other(int v) {
    assert(v_1 == v || v_2 == v);
    if (v_1 == v) {
      return v_2;
    }
    return v_1;
  };

  /**
  * @return weight of this edge
  */
  float get_weight() const {
    return weight;
  }

  bool operator>(const Edge &other) {
    return weight > other.get_weight();
  };

  bool operator>=(const Edge &other) {
    return weight >= other.get_weight();
  };

  bool operator<(const Edge &other) {
    return weight < other.get_weight();
  };

  bool operator<=(const Edge &other) {
    return weight <= other.get_weight();
  };

  bool operator==(const Edge &other) {
    return weight == other.get_weight();
  };

  bool operator!=(const Edge &other) {
    return weight != other.get_weight();
  };
};

#endif // ALGOS_GRAPHS_EDGE_H_ 
