// Copyright 2018 BSc ViBOT

#include <gtest/gtest.h>
#include <common/3Dpoint.hpp>

// Create our own test to check the different function of our class
// This function will take two arguments:
// * The test case name
// * The test name
TEST(first_coordinates_values, second_coordinate_values) {
    float x = 20, y = 45.5, z = 90;

    Geometry coordinates(x, y, z);

    ASSERT_FLOAT_EQ(coordinates.x, x);
    ASSERT_FLOAT_EQ(coordinates.y, y);
    ASSERT_FLOAT_EQ(coordinates.z, z);
}
