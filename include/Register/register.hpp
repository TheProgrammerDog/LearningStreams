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
#include <vector>
#include <string>

enum class priority {
  High,
  Medium,
  Low
};

std::string priority_to_string(const priority& prior);

class Register {
  public:
    Register() {}
    ~Register() {}

    void append(const std::string& string, const priority& prior);

    friend std::ostream& operator<<(std::ostream& os, const Register& reg);
    friend std::ofstream& operator<<(std::ofstream& ofs, const Register& reg);
    friend std::ifstream& operator>>(std::ifstream& ifs, Register& reg);
  
    private:
      std::multimap<priority, std::vector<std::string>> prior_table_;

      std::ostream& print_High(std::ostream& os) const;
      std::ostream& print_Medium(std::ostream& os) const;
      std::ostream& print_Low(std::ostream& os) const;
};

#endif