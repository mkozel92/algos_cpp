#ifndef ALGOS_GRAPHS_EDGE_H_
#define ALGOS_GRAPHS_EDGE_H_

#include<cassert>


class Edge{
  private:
    int v_1;
    int v_2;
    float weight;
  public:
    Edge(int v_1, int v_2, float weight) : v_1(v_1),\
                                           v_2(v_2),\
                                           weight(weight) {};
    int either() {
      return v_1;  
    };
    
    int other(int v){
      assert(v_1 == v || v_2 == v);
      if (v_1 == v){
        return v_2;
      }
      return v_1;
    };

    bool operator> (const Edge& other){ 
      return weight > other.weight;
    };
    bool operator>= (const Edge& other){ 
      return weight >= other.weight;
    };
    bool operator< (const Edge& other){ 
      return weight < other.weight;
    };
    bool operator<= (const Edge& other){ 
      return weight <= other.weight;
    };
    bool operator== (const Edge& other){ 
      return weight == other.weight;
    };
    bool operator!=(const Edge& other){ 
      return weight != other.weight;
    };
};

#endif // ALGOS_GRAPHS_EDGE_H_ 
