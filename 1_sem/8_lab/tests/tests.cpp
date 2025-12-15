#include "Par.h"
#include "Stack.h"
#include <gtest/gtest.h>
#include <cmath>

// Тесты для Stack
TEST(StackTest, BasicOperations) {
    Stack<int> stack;
    EXPECT_EQ(stack.size(), 0);
    
    stack << 1;
    EXPECT_EQ(stack.size(), 1);
    EXPECT_EQ(stack[0], 1);
    
    stack << 2;
    EXPECT_EQ(stack.size(), 2);
    EXPECT_EQ(stack[0], 2);
    EXPECT_EQ(stack[1], 1);
    
    int val;
    stack >> val;
    EXPECT_EQ(val, 2);
    EXPECT_EQ(stack.size(), 1);
}

// Тесты для Parser
TEST(ParserTest, ParseNumber) {
    Parser parser("42");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 42.0, 1e-10);
}

TEST(ParserTest, ParseAddition) {
    Parser parser("2+3");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 5.0, 1e-10);
}

TEST(ParserTest, ParseMultiplication) {
    Parser parser("6*7");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 42.0, 1e-10);
}

TEST(ParserTest, ParseDivision) {
    Parser parser("8/4");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 2.0, 1e-10);
}

TEST(ParserTest, ParseComplexExpression) {
    Parser parser("2+3*4");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 14.0, 1e-10);
}

TEST(ParserTest, ParseWithParentheses) {
    Parser parser("(2+3)*4");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 20.0, 1e-10);
}

TEST(ParserTest, ParseUnaryMinus) {
    Parser parser("-5");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), -5.0, 1e-10);
}

TEST(ParserTest, ParseSin) {
    Parser parser("sin(0)");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 0.0, 1e-10);
}

TEST(ParserTest, ParseCos) {
    Parser parser("cos(0)");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 1.0, 1e-10);
}

TEST(ParserTest, ParsePower) {
    Parser parser("2**3");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 8.0, 1e-10);
}

TEST(ParserTest, ParseMod) {
    Parser parser("5mod2");
    Expression expr = parser.parse();
    EXPECT_NEAR(eval(expr), 1.0, 1e-10);
}

TEST(ParserTest, InvalidExpressionThrows) {
    Parser parser("2+");
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

TEST(ParserTest, UnmatchedParenthesesThrows) {
    Parser parser("(2+3");
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}