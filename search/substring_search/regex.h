//
// Created by michal on 17/06/19.
//

#ifndef ALGOS_SEARCH_SUBSTRING_SEARCH_REGEX_H_
#define ALGOS_SEARCH_SUBSTRING_SEARCH_REGEX_H_


#include <string>
#include "../../graphs/adjacency_list_weighted_digraph.h"
#include <stack>
#include <unordered_set>

/**
 * Build non-deterministic finite state automaton from given regex
 * Automaton is represented by directed weighted graph.
 * First we create a vertex in graph for every character in given regex + 1 end state
 * Then we iterate over regex adding epsilon edges to the graph
 * 1. We add forward epsilon edge to next state for every (, ) and *
 * 2. We also add backward epsilon edge for every * that points to previous left bracket
 * and an edge from this bracket to current state symbol *
 * this allows to repeat or skip over expressions marked by *
 * 3. We 2 epsilon edges for every |
 * ..first from | to next ) which allows to skip over right part of expression
 * ..second from previous ( to | + 1 which allows to skip over left part of expression
 *
 * we use stack to keep track of positions of brackets
 *
 * Complexity O(L) where L is length of regex
 * @param regex regex to process
 * @return NFA
 */
ALWDigraph BuildNFA(const std::string &regex);

/**
 * Dfs over a graph and mark visited vertices
 * @param a_graph graph to process
 * @param reachable_states set of visited vertices
 * @param vertex starting vertex
 */
void Dfs(const ALWDigraph &a_graph, \
         std::unordered_set<int> *reachable_states, int vertex);

/**
 * Simulate NFA to see if given string matches our regex
 * 1. find all states reachable by epsilon edges using DFS from current reachable states
 * 2. Find all states that are reachable from states found in previous step
 *    by using non-epsilon transition, that is, transitions that match current
 *    character of given string
 * 3. return to step 1 with new set of currently reachable states found in step 2
 *    and repeat this for every character in given string
 * 4. after going over whole given string check if one of the current rechable states
 *    is the end state.
 *
 * @param nfa NFA
 * @param regex regex used to build the NFA
 * @param a_string string to match against the regex
 * @return true if the string if match with the regex
 */
bool SimulateNFA(const ALWDigraph &nfa, const std::string &regex, \
                 const std::string &a_string);

#endif //ALGOS_SEARCH_SUBSTRING_SEARCH_REGEX_H_
