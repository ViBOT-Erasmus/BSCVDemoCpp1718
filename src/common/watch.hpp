// Copyright 2018 BSc ViBOT

#ifndef SRC_COMMON_WATCH_HPP_
#define SRC_COMMON_WATCH_HPP_
#include <string>


class Watch {
 public:
  Watch(std::string, int);

  std::string brand;
  int serial_number;
};
#endif  // SRC_COMMON_WATCH_HPP_
