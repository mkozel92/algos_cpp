#include<gtest/gtest.h>
#include<string>
#include<memory>
#include"../../data_structures/ternary_search_trie.h"

TEST(ternary_search_tries, test_ternary_search_tries){
  std::vector<std::string> a_vector = {"this", "is", "some", "sample", "data"};
  TernarySearchTrie<int> tst;
  for (int i = 0; i < a_vector.size(); i++){
      tst.Put(a_vector[i], i);
  }
  
  int* a_int;;
  for (int i = 0; i < a_vector.size(); i++){
    a_int = tst.Get(a_vector[i]);
    EXPECT_EQ(*a_int, i);
  }
  
  a_int = tst.Get("not_there");
  EXPECT_EQ(nullptr, a_int);
}

