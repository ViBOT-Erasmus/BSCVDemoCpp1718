// Copyright 2018 BSc ViBOT

#include "smartphone.hpp"

Smartphone::Smartphone() {
    os = "";
}

void Smartphone::set_os(std::string val) {
    os = val;
}

std::string Smartphone::get_os() {
    return os;
}

