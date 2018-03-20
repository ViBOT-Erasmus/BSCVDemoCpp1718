// Copyright 2018 BSc ViBOT

#include <gtest/gtest.h>
#include <cmath>

#include <common/complex.hpp>

// Create our own test to check the different function of our class
// This function will take two arguments:
// * The test case name
// * The test name
TEST(ComplexBuild, DefaultVal) {
    float x = 2, y = 2;

    complex a;
    complex b(x, y);

    GTEST_ASSERT_EQ(a.get_real(), 0);
    ASSERT_FLOAT_EQ(b.get_mod(), std::sqrt(8));
    ASSERT_FLOAT_EQ(b.get_arg(), std::atan(1));

    b.set_real(-2.0f);
    ASSERT_FLOAT_EQ(b.get_arg(), std::atan(-1) + PI);

    b.clear_real();
    ASSERT_FLOAT_EQ(0, 0);
}

TEST(ComplexMod, DefaultTest) {
    float x = 2, y = 2;
    complex b(x, y);

    ASSERT_FLOAT_EQ(b.get_mod(), std::sqrt(8));
}

TEST(ComplexArg, AnglePos) {
    float x = 2, float y = 2;
    complex b(x, y);

    ASSERT_FLOAT_EQ(b.get_arg(), std::atan(1));
}

TEST(ComplexArg, AngleNeg) {
    float x = -2,  y = 2;
    complex b(x, y);

    ASSERT_FLOAT_EQ(b.get_arg(), std::atan(-1) + PI);
}

TEST(ComplexClear, Default) {
    float x = -2,  y = 2;
    complex b(x, y);

    b.clear_real();
    ASSERT_FLOAT_EQ(b.get_real(), 0.0);
}

TEST(ComplexAddOperator, Default) {
    float x = 2, y = 2;
    complex b(x, y);
    complex a(x, y);
    complex res;

    res = a + b;

    ASSERT_FLOAT_EQ(res.get_real(), 4);
    ASSERT_FLOAT_EQ(res.get_imag(), 4);
}
