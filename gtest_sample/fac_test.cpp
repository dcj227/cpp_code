/***********************************************************************
 * Author :          dingchangjiang
 * Email :           dcj227@163.com
 * Last modified :   2015-08-18 22:29
 * Filename :        fac_test.cpp
 * Description :     
 * *********************************************************************/

#include <limits>
#include <iostream>

#include <gtest/gtest.h>

#include "func.h"

TEST(Fac_test, input_negative) {
  EXPECT_EQ(-1, fac(-1));
  EXPECT_EQ(-1, fac(-2));
  EXPECT_EQ(-1, fac(-5));
}

TEST(Fac_test, input_zero) {
  EXPECT_EQ(1, fac(0));
}

TEST(Fac_test, input_positive) {
  EXPECT_EQ(1, fac(1));
  EXPECT_EQ(2, fac(2));
  EXPECT_EQ(6, fac(3));
}

int main(int argc, char* argv[]) {
  testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
