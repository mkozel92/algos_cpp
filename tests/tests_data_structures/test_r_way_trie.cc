#include<gtest/gtest.h>
#include<string>
#include<memory>
#include"../../data_structures/r_way_trie.h"

TEST(r_way_tries, test_r_way_tries){
  std::vector<std::string> a_vector = {"this", "is", "some", "sample", "data"};
  trie::RWayTrie<int> rwt(256);
  for (int i = 0; i < a_vector.size(); i++){
      rwt.Put(a_vector[i], i);
  }
  
  int* a_int = new int;
  for (int i = 0; i < a_vector.size(); i++){
    a_int = rwt.Get(a_vector[i]);
    EXPECT_EQ(*a_int, i);
  }
  
  a_int = rwt.Get("not_there");
  EXPECT_EQ(nullptr, a_int);
  delete a_int;
}

