#ifndef ALGOS_DYNAMIC_CONNECTIVITY_QUICK_UNION_H_
#define ALGOS_DYNAMIC_CONNECTIVITY_QUICK_UNION_H_

#include<vector>

/**
* @brief Object that maintains a list for connected components.
* Each index od the id_list represents one object and the value on this index
* points to another object from the same group. If the value on the index points to itself
* it means that this object is the root of the group.
* Each group is therefore represented as a tree
*/
class QuickUnion {
private:
  std::vector<int> id_list_;
public:
  /**
  * @brief initialization assigns each object to its own connected component
  * complexity O(N)
  *
  * @param N number of objects
  */
  explicit QuickUnion(int N) : id_list_(N) {
    for (int i = 0; i < id_list_.size(); i++) {
      id_list_[i] = i;
    }
  };

  int Root(int);

  bool Connected(int, int);

  void Union(int, int);
};

/**
* @brief finds the root for given object 
* (root of the group that the object belongs to)
* complexity O(N)
*
* @param p id of the object we want to find the root for
*
* @return root of the object
*/
int QuickUnion::Root(int p) {
  while (p != id_list_[p]) {
    p = id_list_[p];
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
bool QuickUnion::Connected(int p, int q) {
  return Root(p) == Root(q);

}

/**
* @brief connect objects p and q into same connected component
* complexity O(N)
*
* @param p id of the first object
* @param q id of the second object
*/
void QuickUnion::Union(int p, int q) {
  int root_p = Root(p);
  int root_q = Root(q);
  id_list_[root_q] = id_list_[root_p];
}

#endif // ALGOS_DYNAMIC_CONNECTIVITY_QUICK_UNION_H_
