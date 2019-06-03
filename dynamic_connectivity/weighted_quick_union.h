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

/**
* @brief finds root of a given object and compresses the path by half.
* The compression is done by making each object point to its grandparent while searching for the root
* complexity O(log N) ...log N is max distance between the object and its root
*
* @param p an object for which we want to find a root
*
* @return root of the group the object p belongs to
*/
int WeightedQuickUnion::root(int p){
  while(p != id_list[p]){
    id_list[p] = id_list[id_list[p]];
    p = id_list[p];
    }  
  return p;
}

/**
* @brief Checks if two objects are in the same connected component by checking their roots
* complexity O(log N)
*
* @param p id of the first object
* @param q if of the second object
*
* @return True if the object are in the same connected component
*/
bool WeightedQuickUnion::connected(int p, int q){
  return root(p) == root(q);  
}

/**
* @brief Connects objects p and q into one connected component
* complexity O(log N) has to find roots       
*
* @param p id of the first object
* @param q id of the second object
*/
void  WeightedQuickUnion::union_(int p, int q){
  int root_p = root(p);
  int root_q = root(q);
  if(root_p != root_q){
    if(sizes[root_p] > sizes[root_q]){
      id_list[root_q] = root_p;
      sizes[root_p] += sizes[root_q];
    }
    else{
       id_list[root_p] = root_q;
       sizes[root_q] += sizes[root_p];
    }
  }
  
}

