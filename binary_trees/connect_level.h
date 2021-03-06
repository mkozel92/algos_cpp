#ifndef ALGOS_BINARY_TREES_CONNECT_LEVEL_H_
#define ALGOS_BINARY_TREES_CONNECT_LEVEL_H_


#include"binary_tree.h"
#include<queue>
#include<utility>

namespace binary_tree {

/**
* @brief function to connect node of the tree that are on the same level
* complexity O(N)
*
* @param a_node root of the tree to connect
*/
void ConnectLevels(const NodePtr <int, int> &a_node) {
  std::queue<std::pair<NodePtr <int, int>, int>> q;
  q.push(std::make_pair(a_node, 0));

  std::pair<NodePtr <int, int>, int> a_pair;
  while (!q.empty()) {
    a_pair = q.front();
    q.pop();
    if (!q.empty() && a_pair.second == q.front().second) {
      a_pair.first->next_ = q.front().first;
    }
    if (a_pair.first->left_ != nullptr) {
      q.push(std::make_pair(a_pair.first->left_, a_pair.second + 1));
    }
    if (a_pair.first->right_ != nullptr) {
      q.push(std::make_pair(a_pair.first->right_, a_pair.second + 1));
    }
  }
}

} // binary tree

#endif // ALGOS_BINARY_TREES_CONNECT_LEVEL_H_

