#include<vector>

using namespace std;

/**
* @brief Object that maintains a list for connected components.
* Each index od the id_list represents one object and the value on this index
* points to another object from the same group. If the value on the index points to itself
* it means that this object is the root of the group.
* Each group is threfore represented as a tree
*/
class QuickUnion{
  private:
    vector<int> id_list;
  public:
    /**
    * @brief initialization assignins each object to its own connected component
    * complexity O(N)
    *
    * @param N number of objects
    */
    QuickUnion(int N) : id_list(N) {
      for(int i = 0; i < id_list.size(); i++){
        id_list[i] = i;  
      }  
    };
    int root(int);
    bool connected(int, int);
    void union_(int, int);
}; 

/**
* @brief finds the root for given object 
* (root of the group that the object belongs to)
* complexity O(N)
*
* @param p id of the object we want to find the root for
*
* @return 
*/
int QuickUnion::root(int p){
  while(p != id_list[p]){
    p = id_list[p];
  }
  return p;
}

/**
* @brief checks if two objects are in the same connected component
* complexity O(N)
*
* @param p id of the first object
* @param q id of the second object
*
* @return True if the object are in the same connected component
*/
bool QuickUnion::connected(int p, int q){
  return root(p) == root(q);  
  
}

/**
* @brief connect objects p and q into same connected component
* complexity O(N)
*
* @param p id of the first object
* @param q id of the second object
*/
void QuickUnion::union_(int p, int q){
  int root_p = root(p);
  int root_q = root(q);
  id_list[root_q] = id_list[root_p];
}

