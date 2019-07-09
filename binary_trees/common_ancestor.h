//
// Created by michal on 09/07/19.
//

#ifndef ALGOS_BINARY_TREES_COMMON_ANCESTOR_H_
#define ALGOS_BINARY_TREES_COMMON_ANCESTOR_H_


#include"binary_tree.h"

namespace binary_tree {

template<class K, class V>
struct AncestorResult {
  bool has_first;
  bool has_second;
  NodePtr<K, V> node;
};
/**
 * find first common ancestor for given nodes
 * complexity O(N)
 * @tparam K type of key
 * @tparam V type of values
 * @param root current root
 * @param first key of first node
 * @param second key of second node
 * @return first common ancestor of first and second node
 */
template<class K, class V>
AncestorResult<K, V> CommonAncestor(const NodePtr<K, V> &root, K first, K second) {
  AncestorResult<K, V> result;

  if (root == nullptr) {
    result.has_first = false;
    result.has_second = false;
    result.node = nullptr;
    return result;
  }

  result.has_first = root->key_ == first;
  result.has_second = root->key_ == second;

  auto result_left = CommonAncestor(root->left_, first, second);
  if (result_left.node != nullptr)
    return result_left;
  auto result_right = CommonAncestor(root->right_, first, second);
  if (result_right.node != nullptr)
    return result_right;

  result.has_first = result.has_first || result_left.has_first || result_right.has_first;
  result.has_second = result.has_second || result_left.has_second || result_right.has_second;

  if (result.has_first && result.has_second)
    result.node = root;

  return result;
}

} //binary_tree


#endif //ALGOS_BINARY_TREES_COMMON_ANCESTOR_H_
