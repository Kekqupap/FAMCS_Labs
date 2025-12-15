#include <gtest/gtest.h>
#include "../src/calculator.hpp"

TEST(CalcTest, Add) {
    EXPECT_DOUBLE_EQ(add(2, 3), 5);
}

TEST(CalcTest, DivideByZero) {
    EXPECT_THROW(divide(1, 0), std::runtime_error);
}