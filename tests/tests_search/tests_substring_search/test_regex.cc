#include<gtest/gtest.h>
#include"../../../search/substring_search/regex.h"
#include<string>

TEST(substring_search, regex){
  std::string regex_1 = "(abab|c*)*";
  std::string regex_2 = "(a*b*)";
  std::string regex_3 = "(a.b)*";
  
  ALWDigraph nfa = BuildNFA(regex_1);
  EXPECT_TRUE(SimulateNFA(nfa, regex_1, "abab"));
  EXPECT_TRUE(SimulateNFA(nfa, regex_1, "cababccc"));
  EXPECT_TRUE(SimulateNFA(nfa, regex_1, "ccccc"));
  EXPECT_FALSE(SimulateNFA(nfa, regex_1, "aabab"));
  EXPECT_FALSE(SimulateNFA(nfa, regex_1, "ababab"));
  EXPECT_FALSE(SimulateNFA(nfa, regex_1, "aaa"));

  ALWDigraph nfa_1 = BuildNFA(regex_2);
  EXPECT_TRUE(SimulateNFA(nfa_1, regex_2, "abb"));
  EXPECT_TRUE(SimulateNFA(nfa_1, regex_2, "aaaa"));
  EXPECT_TRUE(SimulateNFA(nfa_1, regex_2, "bbbbb"));
  EXPECT_FALSE(SimulateNFA(nfa_1, regex_2, "aabba"));
  EXPECT_FALSE(SimulateNFA(nfa_1, regex_2, "ccc"));
  EXPECT_FALSE(SimulateNFA(nfa_1, regex_2, "abc"));

  ALWDigraph nfa_2 = BuildNFA(regex_3);
  EXPECT_TRUE(SimulateNFA(nfa_2, regex_3, "abb"));
  EXPECT_TRUE(SimulateNFA(nfa_2, regex_3, "acb"));
  EXPECT_TRUE(SimulateNFA(nfa_2, regex_3, "aDb"));
  EXPECT_FALSE(SimulateNFA(nfa_2, regex_3, "abbb"));
  EXPECT_FALSE(SimulateNFA(nfa_2, regex_3, "bbb"));
  EXPECT_FALSE(SimulateNFA(nfa_2, regex_3, "aba"));


}
