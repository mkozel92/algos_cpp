#ifndef ALGOS_DYNAMIC_CONNECTIVITY_WEIGHTED_QUICK_UNION_H_
#define ALGOS_DYNAMIC_CONNECTIVITY_WEIGHTED_QUICK_UNION_H_

#include<vector>


/**
* @brief Object that maintains a list for connected components.
* Each index of the id_list represents one object and value on this index
* points to another object from the same group. If the value on the index points to itself
* it means that this object is the root of the group.
* Each group is therefore represented as a tree.
* Another list, sizes, keeps track of sizes of the trees to ensure the trees are stacked
* in such a way that the max height of tree is limited to log N
*/
class WeightedQuickUnion{
  private:
    std::vector<int> id_list;
    std::vector<int> sizes;
  public:
    /**
    * @brief initialization that assigns each object so its own connected component
    * complexity O(N)
    *
    * @param N number of objects
    */
    WeightedQuickUnion(int N) : id_list(N), sizes(N, 1) {
      for(int i = 0; i < id_list.size(); i++){
        id_list[i] = i;
      }  
    };
    int root(int);
    bool connected(int, int);
    void union_(int, int);
};

#endif // ALGOS_DYNAMIC_CONNECTIVITY_WEIGHTED_QUICK_UNION_H_
