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
#include <map>

class Register {
  public:
    Register() : key_n_(0) {}
    ~Register() {}

    void append(const std::string& string);

    friend std::ostream& operator<<(std::ostream& os, const Register& reg);
    friend std::ofstream& operator<<(std::ofstream& ofs, const Register& reg);
    friend std::ifstream& operator>>(std::ifstream& ifs, Register& reg);
  
    private:
      std::map<int, char*> table_;
      unsigned key_n_;
};

#endif