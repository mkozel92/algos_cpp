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
  
#### Binary tree algos

1. _binary_tree_  
  simple implementation of binary tree. \
O(log N) insertion and O(log N search)

1. _bst_sequences_  
  Return all possible sequences that could have been used to construct given binary tree
  Complexity O(N!)

1. _common_ancestor_  
  Find first common ancestor of two nodes in binary tree \
  complexity O(N)

1. _connect_same_level_  
  Algo to connect tree nodes that are on the same level in the tree. \
Uses DFS and has O(N) complexity

1. _elements_from_range_  
enqueues elements that fall in specified range with O(M + log N) complexity

1. _is_bst_
  checks if given tree is BST \
  complexity O(N)

#### bit manipulation

1. _conversion_  
  compute number of bits that needs to be flipped to convert integer 'a' into given integer 'b'

1. _float_to_bin_  
  Get binary encoding of a decimal part of float number

1. _insert_  
  insert binary representation of given integer between given bits of different integer

1. _longest_sequence_  
  return length of longest sequence of 1s in bit representation of and integer \
  that can be created by flipping exactly one bit in this integer

#### compression

1. _run_length_compression_  
  compress data by encoding alternating sequences of same bits as a lengths of those sequences

1. _huffman_compression_  
  compression based on Huffman encoding

#### data structures

1. _binary_heap_  
  implementation of binary heap using an array of fixed size. \
  O(log N) insertion, deletion and search

1. _bit_array_  
  implementation of efficient bit storage. \
  User can set and get bit values from given indices

1. _bit_stream_  
  implementation of simple bit stream for bit manipulation algos

1. _bst_symbol_table_  
  symbol table (holds key, value pairs) implemented using binary tree. \
  O(N) deletion, search and insertion as balance is not ensured. \
  O(log N) deletion, search and insertion if the tree is balanced \
  but Hibbard deletion is not symmetric and messes up the balance

1. _dynamic_array_stack_  
  stack implemented using resizing array.
  O(N) operations but amortized time is constant

1. _chained_hash_table_  
  hash table implementation using separate chaining. \
  O(N/M) insertion, deletion and search. \
  N/M is num_of_elements/size_of_array = average list length

1. _linked_list_queue_  
  simple implementation of a queue using a linked list. \
  O(1) enqueue, dequeue and peek

1. _linked_list_stack_  
  simple implementation of a stack using a linked list. \
  O(1) push, pop, peek

1. _red_black_tree_  
  red black binary tree. Inserting of new elements keeps the tree balanced. \
  O (log N) search, insert

1. _r_way_trie_  
  implementation of r way trie \
  with get and insert operation running in O(k) \
  where k is length of a key

1. _ternary_search_trie_  
  trie structure with same performance guarantees as r_way_trie \
  but more memory efficient as it does not store tons of null pointers

#### dynamic connectivity

keeps track of connected components \
Union(p, q) - connects two elements \
connected(p, q) - checks if elements are connected \

1. _quick_find_  
  O(N) union\
  O(1) connected

1. _quick_union_  
  O(N) union\
  O(N) connected

1. _weighted_quick_union_
  O(log N) union\
  O(log N) connected\
  But those are basically constant because average case complexity \
  grows proportionally to inverse Ackermann function = does not grow at all 

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
