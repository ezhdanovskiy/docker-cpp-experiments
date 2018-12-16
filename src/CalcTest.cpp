#include "Calc.h"

#include <sstream>

#include <gtest/gtest.h>

TEST(HelloWorld, Test) {
    Calc calc;
    ASSERT_EQ(9 + 4, calc.sum(9, 4));
    ASSERT_EQ(9 - 4, calc.minus(9, 4));
}

// Точка входа в тестовое приложение
int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}