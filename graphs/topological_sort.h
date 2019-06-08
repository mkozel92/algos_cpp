#ifndef ALGOS_GRAPHS_TOPOLOGICAL_SORT_H_
#define ALGOS_GRAPHS_TOPOLOGICAL_SORT_H_

#include"graph.h"
#include<vector>
#include<stack>


void recursive_topological_sort(const Digraph&, int,\
                                std::stack<int>*,\
                                std::vector<bool>*);

void topological_sort(const Digraph&, std::stack<int>*);


#endif // ALGOS_GRAPHS_TOPOLOGICAL_SORT_H_
