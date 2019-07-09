//
// Created by michal on 09/07/19.
//

#ifndef ALGOS_BINARY_TREES_IS_BST_H_
#define ALGOS_BINARY_TREES_IS_BST_H_

#include"binary_tree.h"

namespace binary_tree {
/**
 * checks if given tree is bst by checking subtree ranges
 * complexity O(N)
 * @tparam K type of keys
 * @tparam V type of values
 * @param root root of current subtree
 * @param from range
 * @param to range
 * @return true if given tree is bst
 */
template<class K, class V>
bool IsBst(const NodePtr<K, V> &root, K from, K to) {
  if (root == nullptr)
    return true;
  if (root->key_ < to && root->key_ > from)
    return IsBst(root->left_, from, root->key_) && IsBst(root->right_, root->key_, to);
  return false;
}

}

#endif //ALGOS_BINARY_TREES_IS_BST_H_
