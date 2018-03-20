// Copyright 2018 BSc ViBOT

#ifndef SRC_COMMON_COMPLEX_HPP_
#define SRC_COMMON_COMPLEX_HPP_

#include <cmath>


#define PI 3.14159265

class complex {
 public:
    complex();
    complex(float &, float &);
    void set_real(float);
    void set_imag(float);
    float get_real() const;
    float get_imag() const;
    float get_mod();
    float get_arg();
    void clear_real();

 private:
  // Member variable
  float real;
  float imag;
  float mod;
  float ar;

  // Member functions and methods
  float modulus();
  float arg();
};

complex operator+(const complex &, const complex &);

#endif  // SRC_COMMON_COMPLEX_HPP_
