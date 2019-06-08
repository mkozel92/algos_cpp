#include"graph.h"
#include<vector>
#include<stack>


void recursive_topological_sort(const Digraph&, int,\
                                std::stack<int>*,\
                                std::vector<bool>*);

void topological_sort(const Digraph&, std::stack<int>*);

