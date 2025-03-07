/**
 * @file Register.hpp
 * @author
 * @date 07/03/2025
 *
 * @brief
 *
 */

#ifndef RECORDS_HPP_
#define RECORDS_HPP_

#include <iostream>
#include <fstream>

class Register {
  public:
    Register();
    Register(const long long int& data);
    ~Register();

    friend std::ostream& operator<<(std::ostream& os, const Register& reg);
    friend std::ofstream& operator<<(std::ofstream& of, const Register& reg);
  
    long long int* data_;
};

#endif