// Copyright 2018 BSc ViBOT

#include "phone.hpp"

phone::phone() {
    year = 0;
    value = 0;
}

void phone::set_value(int val) {
    value = val;
}

int phone::get_value() {
    return value;
}

void phone::set_year(int val) {
    year = val;
}

int phone::get_year() {
    return year;
}
