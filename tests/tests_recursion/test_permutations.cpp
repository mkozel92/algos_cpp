#include"../../recursion/permutations.h"
#include<string>
#include<unordered_set>
#include<gtest/gtest.h>


TEST(permutation, test_counts){
    std::unordered_set<std::string> a_set;
    a_set = get_permutations("hello");
    EXPECT_EQ(a_set.size(), 60);
    a_set = get_permutations("something");
    EXPECT_EQ(a_set.size(), 362880);
}
