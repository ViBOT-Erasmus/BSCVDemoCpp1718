// Copyright 2018 BSc ViBOT

#include <gtest/gtest.h>
#include <string>

#include <common/watch.hpp>

// Create our own test to check the different function of our class
// This function will take two arguments:
// * The test case name
// * The test name
TEST(WatchTest, ConstructorAffect) {

    std::string name_brand = "Rolex";
    int serial_number = 52177;

    Watch any_watch(name_brand, serial_number);

    ASSERT_STREQ(any_watch.brand.c_str(), name_brand.c_str());
    GTEST_ASSERT_EQ(any_watch.serial_number, serial_number);
}
