#include"weighted_quick_union.h"

/**
* @brief finds root of a given object and compresses the path by half.
* The compression is done by making each object point to its grandparent while searching for the root
* complexity O(log N) ...log N is max distance between the object and its root
*
* @param p an object for which we want to find a root
*
* @return root of the group the object p belongs to
*/
int WeightedQuickUnion::Root(int p) {
  while (p != id_list_[p]) {
    id_list_[p] = id_list_[id_list_[p]];
    p = id_list_[p];
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
bool WeightedQuickUnion::Connected(int p, int q) {
  return Root(p) == Root(q);
}

/**
* @brief Connects objects p and q into one connected component
* complexity O(log N) has to find roots       
*
* @param p id of the first object
* @param q id of the second object
*/
void WeightedQuickUnion::Union(int p, int q) {
  int root_p = Root(p);
  int root_q = Root(q);
  if (root_p != root_q) {
    if (sizes_[root_p] > sizes_[root_q]) {
      id_list_[root_q] = root_p;
      sizes_[root_p] += sizes_[root_q];
    } else {
      id_list_[root_p] = root_q;
      sizes_[root_q] += sizes_[root_p];
    }
  }
}
