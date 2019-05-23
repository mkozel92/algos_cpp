test_file="test_file"

g++ -std=c++11 -isystem ${GTEST_DIR}/include -pthread ./test_is_squashable.cpp ${GTEST_DIR}/libgtest.a \
	-o $test_file

./$test_file
