test_file="test_file"
test_scripts=$(find ../ -type f -name "*.cc")


g++ -std=c++11 -isystem \
  ${GTEST_DIR}/include -pthread \
  $test_scripts\
  ${GTEST_DIR}/libgtest.a \
  -o $test_file

./$test_file
rm $test_file
