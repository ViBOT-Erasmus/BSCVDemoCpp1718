// Copyright 2018 BSc ViBOT

#ifndef SRC_COMMON_SMARTPHONE_HPP_
#define SRC_COMMON_SMARTPHONE_HPP_

#include <string>
#include "phone.hpp"

class Smartphone: public phone {
 public:
  Smartphone();

  void set_os(std::string);
  std::string get_os();

 private:
  std::string os;
};
#endif  // SRC_COMMON_SMARTPHONE_HPP_
