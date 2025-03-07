/**
 * @file register.cc
 * @author
 * @date 07/03/2025
 *
 * @brief 
 *
 */

#include "Register/register.hpp"
#include <iomanip>
#include <regex>
#include <exception>
#include <vector>
#include <sstream>
#include <memory>
#include <cstring>

void Register::append(const std::string& string) {
  const std::regex integer("\\-?\\d+");
  const std::regex fractional("\\-?\\d+\\.\\d+");

  std::istringstream sstream(string);
  std::vector<std::unique_ptr<char>> bytes;
  std::string aux;
  while (sstream >> aux) {
    std::smatch match;
    if (std::regex_match(aux, match, integer)) {
      auto num = std::make_unique<int>(std::stoi(aux)); // unique_ptr
      auto byte = std::make_unique<char>(); // unique_ptr
      std::memcpy(byte.get(), num.get(), sizeof(int));
      bytes.push_back(byte);
    }
    else if (std::regex_match(aux, match, fractional)) {
      auto num = std::make_unique<int>(std::stof(aux)); // unique_ptr
      auto byte = std::make_unique<char>(); // unique_ptr
      std::memcpy(byte.get(), num.get(), sizeof(int));
      bytes.push_back(byte);
    }
    else {
      
    }
  }
  // not finished
}