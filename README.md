# algos_cpp

Implementation of commong data structures and algorithms in C++

#### Contents
* [Binary tree algos](#binary-tree-algos)
  * _binary_tree_
  * _bst_sequences_
  * _common_ancestor_
  * _connect_same_level_
  * _elements_from_range_
  * _is_bst_
* [Bit manipulation](#bit-manipulation)
  * _conversion_
  * _float_to_bin_
  * _insert_
  * _longest_sequence_
* [Compression](#compression)
  * _run_lenght_compression_
  * _huffman_compression_
* [Data structures](#data-structures)
  * _binary_heap_
  * _bit_array_
  * _bit_stream_
  * _bst_symbol_table_
  * _dynamic_array_stack_
  * _linked_list_queue_
  * _linked_list_stack_
  * _r_way_trie_
  * _red_black_tree_
  * _chained_hash_table_
  * _ternary_search_trie_
* [Dynamic connectivity](#dynamic-connectivity)
  * _quick_find_
  * _quick_union_
  * _weighted_quick_union_
* [Dynamic programming](#dynamic-programming)
  * _coins_  
  * _longest_common_subsequence_  
  * _max_independent_set_  
  * _triple_step_
* [Graphs](#graphs)
  * [Shortest path](#shortest_path)
    * _Bellmann_Ford_
    * _Dijkstra_
    * _top_sort_search_
  * _adjacency_list_digraph_
  * _adjacency_list_graph_
  * _adjacency_list_weighted_digraph_
  * _adjacency_list_weighted_graph_
  * _breadth_first_search_
  * _connected_components_
  * _depth_first_search_
  * _graph_classification_algos_
    * _is_bipartite_
    * _has_cycle_ 
    * _has_euler_tour_
  * _kruskal_algorithm_
  * _prim_algorithm_
  * _strong_components_
  * _topological_sort_
* [Linear programming](#linear-programming)
  * _simplex_
  
  
#### Binary tree algos

- _binary_tree_  
  simple implementation of binary tree. \
 O(log N) insertion and O(log N search)

- _bst_sequences_  
  Return all possible sequences that could have been used to construct given binary tree \
  Complexity O(N!)

- _common_ancestor_  
  Find first common ancestor of two nodes in binary tree \
  complexity O(N)

- _connect_same_level_  
  Algo to connect tree nodes that are on the same level in the tree. \
Uses DFS and has O(N) complexity

- _elements_from_range_  
enqueues elements that fall in specified range with O(M + log N) complexity

- _is_bst_
  checks if given tree is BST \
  complexity O(N)

#### bit manipulation

- _conversion_  
  compute number of bits that needs to be flipped to convert integer 'a' into given integer 'b'

- _float_to_bin_  
  Get binary encoding of a decimal part of float number

- _insert_  
  insert binary representation of given integer between given bits of different integer

- _longest_sequence_  
  return length of longest sequence of 1s in bit representation of and integer \
  that can be created by flipping exactly one bit in this integer

#### compression

- _run_length_compression_  
  compress data by encoding alternating sequences of same bits as a lengths of those sequences

- _huffman_compression_  
  compression based on Huffman encoding

#### data structures

- _binary_heap_  
  implementation of binary heap using an array of fixed size. \
  O(log N) insertion, deletion and search

- _bit_array_  
  implementation of efficient bit storage. \
  User can set and get bit values from given indices

- _bit_stream_  
  implementation of simple bit stream for bit manipulation algos

- _bst_symbol_table_  
  symbol table (holds key, value pairs) implemented using binary tree. \
  O(N) deletion, search and insertion as balance is not ensured. \
  O(log N) deletion, search and insertion if the tree is balanced \
  but Hibbard deletion is not symmetric and messes up the balance

- _dynamic_array_stack_  
  stack implemented using resizing array.
  O(N) operations but amortized time is constant

- _chained_hash_table_  
  hash table implementation using separate chaining. \
  O(N/M) insertion, deletion and search. \
  N/M is num_of_elements/size_of_array = average list length

- _linked_list_queue_  
  simple implementation of a queue using a linked list. \
  O(1) enqueue, dequeue and peek

- _linked_list_stack_  
  simple implementation of a stack using a linked list. \
  O(1) push, pop, peek

- _red_black_tree_  
  red black binary tree. Inserting of new elements keeps the tree balanced. \
  O (log N) search, insert

- _r_way_trie_  
  implementation of r way trie \
  with get and insert operation running in O(k) \
  where k is length of a key

- _ternary_search_trie_  
  trie structure with same performance guarantees as r_way_trie \
  but more memory efficient as it does not store tons of null pointers

#### dynamic connectivity

keeps track of connected components \
Union(p, q) - connects two elements \
connected(p, q) - checks if elements are connected \

- _quick_find_  
  O(N) union\
  O(1) connected

- _quick_union_  
  O(N) union\
  O(N) connected

- _weighted_quick_union_
  O(log N) union\
  O(log N) connected\
  But those are basically constant because average case complexity \
  grows proportionally to inverse Ackermann function = does not grow at all 

#### dynamic programming

- _coins_  
  count all the different ways to get given change using given coins \
  complexity O(MN) ..num_coins * change to get
  
- _longest_common_subsequence_  
  return length of longest common subsequence \
  complexity O(MN)
  
- _max_independent_set_  
  get sum of elements of max independent set. \
  Independent set is subset of a list such that no elements in this set \
  where consecutive in the original list \
  complexity O(N)
  
- _triple_step_  
  count ways to go up the stair using 1,2, or 3 steps at time \
  complexity O(MN)...choices of steps * num of steps to climb

#### graphs

- shortest path

  - _Bellamn_Ford_  
    Bellman Ford shortest path algo. \
    relaxes every edge V times. \
    Works with cyclic graphs with negative edges and can detect negative cycles. \
    complexity O(EV)

  - _Dijkstra_  
    Dijkstra shortest path algo. \
    works for cyclic graphs with no negative edges. \
    complexity O(E log V)
  
  - _top_sort_search_  
    relaxes verices in topological order. \
    only works for acyclic graphs that have topological order. \
    complexity O(E)
- _adjacency_list_digraph_  
  Directed graph represented by adjacency list. \
  O(1) add_edge \
  O(1) return adjacent vertices for given vertex\
  space complexity E + V

- _adjacency_list_graph_  
  graph represented by adjacency list. \
  O(1) add_edge \
  O(1) return adjacent vertices for given vertex\
  space complexity E + V

- _adjacency_list_weighted_digraph_  
  Directed weighted graph represented by adjacency list. \
  O(1) add_edge \
  O(1) return adjacent vertices for given vertex\
  space complexity E + V

- _adjacency_list_weighted_graph_  
  weighted graph represented by adjacency list. \
  O(1) add_edge \
  O(1) return adjacent vertices for given vertex\
  space complexity E + V

- _adjacency_matrix_graph_  
  graph represented by adjacency matrix. \
  O(1) add_edge \
  O(N) return adjacent vertices for given vertex\
  space complexity V^2

- _breadth_first_search_  
  just BFS, O(E + V)

- _connected_components_  
  get connected components of given undirected graph. \
  complexity O(N)

- _depth_first_search_  
  recursive and iterative implementations of  DFS, \
  O(E + V)

- _graph_classification_algos_  
  - _is_bipartite_  
    check if graph is bipartite using DFS \
    Complexity O(E + V)
  - _has_cycle_  
    Check if given graph has a cycle using DFS \
    Complexity O(E + V)
  - _has_euler_tour_  
    check if graph has an euler tour \
    Complecity O(V)

- _kruskal_  
  Build MST of given graph. \
  Try to add edges from shortest to longest to mst \ 
  but only add those that would not create cycle 
  ... this can be checked in constant time using quick union DS. 
  complexity (E log E) ..dominated by sorting edges
  
- _prim_  
  Build MST of given graph. \
  iteratively add shortest edge that connects current mst with a \
  vertex outside of mst.
  Vertices outside of MST are kept in min heap. \
  complexity O(E log E).
  
- _strong_components_  
  get strong components of a directed graph. \
  Complexity O(E + V)
  
- _topological_sort_  
  topologically sort given acyclic graph. \
  Complexity O(E + V)

#### linear programming

- _simplex_  
  Simplex algo to solve linear programming problems

#### recursion

##### 1, permutations

get every permutation of given string in O(N!)

##### 2. squashable_words

Checks if a word can be recursively reduced to an empty string in such a way\
that after removing a letter from current word the new word is still in a \
dictionary of valid words \
O(N!)


#### search

##### 1. binary_search

both recursive and iterative implementations of binary search\
O(log N)

##### 2. kth_largest

find kth largest element in a given list\
implemented using quick sort partitioning\
O(N) but random shuffling ensures O(N log N) and in practise runs in linear time

#### sort

##### 1. heap_sort

inplace, unstable, O(N log N)

##### 2. insertion_sort

inplace, stable, O(N^2)

##### 3. knuth_shuffle

ensures uniformly random inplace shuffle in O(N)

##### 4. merge_sort

both recursive and iterative implementations\
not-inplace, stable, O(N log N)

##### 5. quick_sort

inplace, unstable\
O(N^2) but random shuffling ensures O(N log N) \

three way partitioning ensures O(N log N) even for duplicate keys

##### 5. selection_sort

inplace, unstable, O(N^2)

##### 6. shell_sort

inplace, unstable, O(nobody really knows)
