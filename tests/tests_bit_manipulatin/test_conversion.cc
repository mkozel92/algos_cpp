//
// Created by michal on 03/07/19.
//


#include<gtest/gtest.h>
#include"../../bit_manipulation/conversion.h"


TEST(bit_manipulation, conversion) {
EXPECT_EQ(0, Conversion(8, 8));
EXPECT_EQ(4, Conversion(7, 8));
EXPECT_EQ(2, Conversion(8, 16));
}

