/**
 * @file register.cc
 * @author
 * @date 07/03/2025
 *
 * @brief 
 *
 */

#include "Register/register.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <exception>

Register::Register() {
  data_ = nullptr;
}

Register::Register(const long long int& data) {
  try {
    data_ = new long long int(data);
  }
  catch(std::bad_alloc& e) {
    std::cerr << e.what() << std::endl;
    data_ = nullptr;
  }
}

Register::~Register() {
  delete data_;
}

std::ostream& operator<<(std::ostream& os, const Register& reg) {
  os << std::left << std::setw(20) << *reg.data_ << reg.data_;
  os << std::resetiosflags(std::ios::adjustfield) << std::setw(0);
  return os;
}

std::ofstream& operator<<(std::ofstream& of, const Register& reg) {
  of.write(reinterpret_cast<const char*>(reg.data_), sizeof(reg.data_));
  return of;
}