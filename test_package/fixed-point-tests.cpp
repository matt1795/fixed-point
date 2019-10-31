#include <fixed-point.hpp>
#include <gtest/gtest.h>

#include <iostream>

TEST(FixedPointTests, Zero) {
    FixedPoint<std::uint16_t, 2> zero{0.124999};
    EXPECT_EQ(zero.value, 0);
    EXPECT_EQ(zero.decimal, 2);
    EXPECT_DOUBLE_EQ(zero.epsilon, 0.25);
}

TEST(FixedPointTests, One) {
    FixedPoint<std::uint16_t, 2> one{0.125};
    EXPECT_EQ(one.value, 1);
    EXPECT_EQ(one.decimal, 2);
    EXPECT_DOUBLE_EQ(one.epsilon, 0.25);
}

TEST(FixedPointTests, Addition) {
    FixedPoint<std::uint16_t, 2> foo{0.25};
    FixedPoint<std::uint16_t, 2> bar{0.25};
    FixedPoint<std::uint16_t, 4> num{0.25};

    auto add = foo + bar;
    EXPECT_EQ(add.value, foo.value + bar.value);
    EXPECT_EQ(add.decimal, 2);

    auto add2 = bar + num;
    EXPECT_EQ(add2.value, 2);
    EXPECT_EQ(add2.decimal, 2);
}
