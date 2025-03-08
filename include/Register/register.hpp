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
#include <bitset>

enum class priority {
  High,
  Medium,
  Low
};

const char LOW = 0x01;
const char MEDIUM = 0x02;
const char HIGH = 0x03;
const char INT = 0x04;
const char FLOAT = 0x05;
const char SEPARATOR = 0x06;

class Register {
  public:
    Register() {}
    ~Register() {}

    void append(const std::string& string, const priority& prior);

    std::ostream& print(std::ostream& os, std::bitset<3> flags) const;
    
    std::ofstream& write(std::ofstream& ofs) const;
    std::ifstream& read(std::ifstream& ifs);
  
    private:
      std::multimap<priority, std::vector<std::string>> prior_table_;

      std::ostream& print_High(std::ostream& os) const;
      std::ostream& print_Medium(std::ostream& os) const;
      std::ostream& print_Low(std::ostream& os) const;

      std::ofstream& write_byte(std::ofstream& ofs, const std::string& a) const;
};

#endif