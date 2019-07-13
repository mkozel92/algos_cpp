#include <gtest/gtest.h>
#include "../../search/search_duplicates.h"


TEST(search, search_duplicate){
  std::array<int, 10> an_array = {0, 1, 1, 2, 2, 2, 3, 4, 6, 4};
  auto duplicates = SearchDuplicates<10>(an_array);
  EXPECT_TRUE(duplicates.find(1) != duplicates.end());
  EXPECT_TRUE(duplicates.find(2) != duplicates.end());
  EXPECT_TRUE(duplicates.find(4) != duplicates.end());
  EXPECT_TRUE(duplicates.find(6) == duplicates.end());
  EXPECT_TRUE(duplicates.find(3) == duplicates.end());
}
