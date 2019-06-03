#include<vector>


/**
* @brief class that maintains a list for connected componentes.
* Each index of the id_list represents one object and the value on this index
* specifies to which connected component this object belongs
*/
class QuickFind{
  private:
    std::vector<int> id_list;
  public:
    /**
    * @brief initialization assigns each object to its own connected component
    * complexity O(N) 
    *
    * @param N number of objects that we can hold
    */
    QuickFind(int N): id_list(N) {
      for(int i = 0; i < id_list.size(); i++){
        id_list[i] = i;    
      }
    };
    bool connected(int, int);
    void union_(int, int);    
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
bool QuickFind::connected(int p, int q){
  return id_list[p] == id_list[q];
}

/**
* @brief Connects objects p and q into one connected component
* complexity O(N) ... has to move all component from q group to p group
*
* @param p id of the first object
* @param q if of the second object
*/
void QuickFind::union_(int p, int q){
  int p_id = id_list[p];
  int q_id = id_list[q];
  if(p_id != q_id){
    for(int i = 0; i < id_list.size(); i++){
      if(id_list[i] == q_id){
        id_list[i] = p_id;
      }
    }
  }
}

