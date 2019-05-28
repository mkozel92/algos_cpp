test_file="test_file"

g++ -std=c++11 -isystem \
  ${GTEST_DIR}/include -pthread \
  ./test_main.cpp \
  ./tests_recursion/test_is_squashable.cpp \
  ./tests_dynamic_connectivity/test_dynamic_connectivity.cpp \
  ./tests_search/test_binary_search.cpp \
  ./tests_sort/test_selection_sort.cpp \
  ./tests_sort/test_insertion_sort.cpp \
  ./tests_sort/test_shell_sort.cpp\
  ${GTEST_DIR}/libgtest.a \
  -o $test_file

./$test_file
rm $test_file
