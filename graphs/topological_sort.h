#ifndef ALGOS_GRAPHS_TOPOLOGICAL_SORT_H_
#define ALGOS_GRAPHS_TOPOLOGICAL_SORT_H_

#include"graph.h"
#include<vector>
#include<stack>


void RecursiveTopologicalSort(const Digraph &, int, \
                                std::stack<int> *, \
                                std::vector<bool> *);

void TopologicalSort(const Digraph &, std::stack<int> *);


#endif // ALGOS_GRAPHS_TOPOLOGICAL_SORT_H_
