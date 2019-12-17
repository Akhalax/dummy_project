#include "calculator.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

class CalculatorTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  Calculator calc;
};

TEST_F(CalculatorTest, SimpleExpressions) {
  EXPECT_FLOAT_EQ(0, stof(calc.calculate("5 5 -")));
  EXPECT_FLOAT_EQ(3, stof(calc.calculate("5 2 -")));
  EXPECT_FLOAT_EQ(-10, stof(calc.calculate("5 15 -")));
  EXPECT_FLOAT_EQ(10, stof(calc.calculate("5 5 +")));
  EXPECT_FLOAT_EQ(0, stof(calc.calculate("0 0 -")));
  EXPECT_FLOAT_EQ(45, stof(calc.calculate("9 5 *")));
  EXPECT_FLOAT_EQ(1, stof(calc.calculate("5 5 /")));
  EXPECT_FLOAT_EQ(5, stof(calc.calculate("25 5 /")));
}

//TODO: Make more tests with not allowed expressions
TEST_F(CalculatorTest, NotAllowedExpressions) {
    EXPECT_STREQ("", calc.calculate("5 0 /").c_str());
}

//TODO: Make tests with invalid expressions
TEST_F(CalculatorTest, InvalidExpressions) {
    EXPECT_STREQ("", calc.calculate("4 4 4 9 jk sdf").c_str());
    EXPECT_STREQ("", calc.calculate("    7 7").c_str());
    EXPECT_STREQ("", calc.calculate("3 /").c_str());
    EXPECT_STREQ("", calc.calculate("3 1 / *").c_str());
}

//TODO: Make complex tests (e.g. more operands and operators)

//TODO: Make tests for overflow
TEST_F(CalculatorTest, Overflow) {
    EXPECT_STREQ("inf", calc.calculate("3.402823e+38 3.402823e+38 *").c_str());
}



}  // namespace testing
}  // namespace dev
