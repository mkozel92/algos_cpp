#ifndef ALGOS_GRAPHS_DIRECTED_EDGE_H_
#define ALGOS_GRAPHS_DIRECTED_EDGE_H_

#include<cassert>


/**
* @brief implementation of undirected edge
*/
class DirectedEdge{
  private:
    const int _from;
    const int _to;
    const float weight;
  public:
    DirectedEdge(int _from, int _to, float weight) : _from(_from),\
                                           _to(_to),\
                                           weight(weight) {};
    /**
    * @brief gets the _from vertex adjacent to this edge
    *
    * @return a vertex
    */
    int from() {
      return _from;  
    };
    
    /**
    * @brief gets the _to vertex adjacent to this edge
    *
    * @return a vertex
    */
    int to(){
      return _to;  
    }

    /**
    * @brief gets other vertex adjacent to this edge
    *
    * @param v first vertex 
    *
    * @return other adjacent vertex
    */
    int other(int v){
      assert(_from == v || _to == v);
      if (_to == v){
        return _from;
      }
      return _to;
    };
    
    /**
    * @return weight of this edge 
    */
    float get_weight() const{
      return weight;  
    }

    bool operator> (const Edge& other){ 
      return weight > other.get_weight();
    };
    bool operator>= (const Edge& other){ 
      return weight >= other.get_weight();
    };
    bool operator< (const Edge& other){ 
      return weight < other.get_weight();
    };
    bool operator<= (const Edge& other){ 
      return weight <= other.get_weight();
    };
    bool operator== (const Edge& other){ 
      return weight == other.get_weight();
    };
    bool operator!=(const Edge& other){ 
      return weight != other.get_weight();
    };
};

#endif // ALGOS_GRAPHS_DIRECTED_EDGE_H_ 
