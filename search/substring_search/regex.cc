//
// Created by michal on 17/06/19.
//

#include "regex.h"

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
ALWDigraph BuildNFA(const std::string &regex) {
  int len = regex.length();
  ALWDigraph nfa(len + 1);
  std::stack<int> a_stack;

  for (int i = 0; i < len; i++) {
    int lp = i;
    auto c = regex[i];

    if (c == '(' || c == '|')
      a_stack.push(i);
    else if (c == ')') {
      int or_operator = a_stack.top();
      a_stack.pop();
      if (regex[or_operator] == '|') {
        lp = a_stack.top();
        a_stack.pop();
        nfa.add_edge(lp, or_operator + 1, 0);
        nfa.add_edge(or_operator, i, 0);
      } else
        lp = or_operator;
    }

    if (i < len - 1 && regex[i + 1] == '*') {
      nfa.add_edge(lp, i + 1, 0);
      nfa.add_edge(i + 1, lp, 0);
    }

    if (c == '(' || c == ')' || c == '*')
      nfa.add_edge(i, i + 1, 0);
  }
  return nfa;
}

/**
 * Dfs over a graph and mark visited vertices
 * @param a_graph graph to process
 * @param reachable_states set of visited vertices
 * @param vertex starting vertex
 */
void Dfs(const ALWDigraph &a_graph, \
         std::unordered_set<int> *reachable_states, int vertex) {
  if (reachable_states->find(vertex) != reachable_states->end())
    return;

  reachable_states->insert(vertex);
  for (auto edge : a_graph.adjacent(vertex))
    Dfs(a_graph, reachable_states, edge->to());
}

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
                 const std::string &a_string) {
  std::unordered_set<int> reachable_states;
  Dfs(nfa, &reachable_states, 0);

  for (int i = 0; i < a_string.length(); i++) {
    std::unordered_set<int> match;
    for (auto state : reachable_states) {
      if (regex[state] == a_string[i] || regex[state] == '.')
        match.insert(state + 1);
    }

    reachable_states.clear();
    for (auto state: match)
      Dfs(nfa, &reachable_states, state);
  }

  for (auto state: reachable_states) {
    if (state == regex.length())
      return true;
  }
  return false;
}
