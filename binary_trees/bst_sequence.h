//
// Created by michal on 09/07/19.
//

#ifndef ALGOS_BINARY_TREES_BST_SEQUENCE_H_
#define ALGOS_BINARY_TREES_BST_SEQUENCE_H_

#include"binary_tree.h"
#include<queue>
#include<utility>

namespace binary_tree {

/**
 * compute all possible ways given binary tree could have been created
 * @tparam K node key type
 * @tparam V node value type
 * @param possible_next vector of all nodes that could possobly be added to current tree
 * @return vector of all possible seqences
 */
template <class K, class V>
std::vector<std::vector<int>> BSTSequence(std::vector<NodePtr<K, V>> possible_next){


  std::vector<std::vector<int>> sequences;
  for (int i = 0; i < possible_next.size(); i++){
    std::vector<NodePtr<K, V>> new_possible_next(possible_next);
    new_possible_next.erase(new_possible_next.begin() + i);

    NodePtr<K, V> current_node = possible_next[i];

    if(current_node->left_ != nullptr)
      new_possible_next.push_back(current_node->left_);

    if(current_node->right_ != nullptr)
      new_possible_next.push_back(current_node->right_);

    for (auto res: BSTSequence(new_possible_next)){
      res.insert(res.begin(), (V)current_node->key_);
      sequences.push_back(res);
    }

  }
  if(sequences.size() == 0) {
    std::vector<int> empty;
    sequences.push_back(empty);
  }
  return sequences;
}

}

#endif //ALGOS_BINARY_TREES_BST_SEQUENCE_H_
