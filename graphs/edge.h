#ifndef ALGOS_GRAPHS_EDGE_H_
#define ALGOS_GRAPHS_EDGE_H_

#include<cassert>


/**
* @brief implementation of undirected edge
*/
class Edge {
private:
  const int v_1_;
  const int v_2_;
  const float weight_;
public:
  Edge(int v_1, int v_2, float weight) : v_1_(v_1), \
                                           v_2_(v_2), \
                                           weight_(weight) {};

  /**
  * @brief gets one of the vertices Adjacent to this edge
  *
  * @return a vertex
  */
  int Either() {
    return v_1_;
  };

  /**
  * @brief gets other vertex Adjacent to this edge
  *
  * @param v first vertex
  *
  * @return other Adjacent vertex
  */
  int Other(int v) {
    assert(v_1_ == v || v_2_ == v);
    if (v_1_ == v) {
      return v_2_;
    }
    return v_1_;
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

#endif // ALGOS_GRAPHS_EDGE_H_ 
