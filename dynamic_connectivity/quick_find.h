#ifndef ALGOS_DYNAMIC_CONNECTIVITY_QUICK_FIND_H_
#define ALGOS_DYNAMIC_CONNECTIVITY_QUICK_FIND_H_


#include<vector>

/**
* @brief class that maintains a list for connected componentes.
* Each index of the id_list represents one object and the value on this index
* specifies to which connected component this object belongs
*/
class QuickFind {
private:
  std::vector<int> id_list_;
public:
  /**
  * @brief initialization assigns each object to its own connected component
  * complexity O(N)
  *
  * @param N number of objects that we can hold
  */
  explicit QuickFind(int N) : id_list_(N) {
    for (int i = 0; i < id_list_.size(); i++) {
      id_list_[i] = i;
    }
  };

  bool Connected(int, int);

  void Union(int, int);
};

/**
* @brief checks if two objects are in the same connected component
* complexity O(1)
*
* @param p id of the first object
* @param q id of the second object
*
* @return True if the objects are in the same connected component
*/
bool QuickFind::Connected(int p, int q) {
  return id_list_[p] == id_list_[q];
}

/**
* @brief Connects objects p and q into one connected component
* complexity O(N) ... has to move all component from q group to p group
*
* @param p id of the first object
* @param q if of the second object
*/
void QuickFind::Union(int p, int q) {
  int p_id = id_list_[p];
  int q_id = id_list_[q];
  if (p_id != q_id) {
    for (int i = 0; i < id_list_.size(); i++) {
      if (id_list_[i] == q_id) {
        id_list_[i] = p_id;
      }
    }
  }
}

#endif // ALGOS_DYNAMIC_CONNECTIVITY_QUICK_FIND_H_
