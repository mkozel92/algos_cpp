#ifndef ALGOS_BINARY_TREES_ELEMENTS_FROM_RANGE_H_
#define ALGOS_BINARY_TREES_ELEMENTS_FROM_RANGE_H_


#include<vector>
#include"../data_structures/linked_list_queue.h"
#include"binary_tree.h"


namespace binary_tree {
/**
* @brief enqueues elements from a range inorder from a binary tree
* complexity (M + log N)
*
* @param a_node root of the tree
* @param q queue to store elemtns
* @param low lower bound for the range
* @param hi upper bound for the range
*/
template<class K, class V>
void get_elements_from_range(node_ptr<K, V> a_node, LinkedListQueue<K> *q, K low, K hi) {
  if (a_node == nullptr) {
    return;
  }
  if (a_node->key > hi) {
    get_elements_from_range(a_node->left, q, low, hi);
  } else if (a_node->key < low) {
    get_elements_from_range(a_node->right, q, low, hi);
  } else {
    get_elements_from_range(a_node->left, q, low, hi);
    q->enqueue(a_node->key);
    get_elements_from_range(a_node->right, q, low, hi);
  }
}


} // binary_tree

#endif // ALGOS_BINARY_TREES_ELEMENTS_FROM_RANGE_H_
