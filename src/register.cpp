/**
 * @file register.cc
 * @author
 * @date 07/03/2025
 *
 * @brief register implementation
 *
 */

#include "Register/register.hpp"
#include <iomanip>
#include <regex>
#include <vector>
#include <array>
#include <sstream>

/**
 * @brief function to return a string of the priority enum
 *
 */
std::string priority_to_string(const priority& prior) {
  switch(prior) {
    case priority::High:
      return "High";
    break;
    case priority::Medium:
      return "Medium";
    break;
    default:
      return "Low";
  }
}

/**
 * @brief insert string in the class
 *
 */
void Register::append(const std::string& string, const priority& prior) {
  std::istringstream stream(string);
  std::string aux;
  std::vector<std::string> vector;
  while (stream >> aux) {
    vector.push_back(aux);
  }
  prior_table_.insert(std::make_pair(prior, vector));
}

/**
 * extraction ostream operator overloading
 */
std::ostream& operator<<(std::ostream& os, const Register& reg) {
  reg.print_High(os);
  reg.print_Medium(os);
  reg.print_Low(os);
  return os;
}

/**
 * @brief print from the table only the High priority
 *
 */
std::ostream& Register::print_High(std::ostream& os) const {
  for (auto iter = prior_table_.lower_bound(priority::High); 
  iter != prior_table_.upper_bound(priority::High); ++iter) {
    os << std::setw(6) << std::left << "High";
    os << std::setw(0) << std::resetiosflags(std::ios::adjustfield);
    os << " -> ";
    for (auto i : iter->second) {
      os << i << ' ';
    }
    os << std::endl;
  }
  return os;
}

/**
 * @brief print from the table only the Medium priority
 *
 */
std::ostream& Register::print_Medium(std::ostream& os) const {
  for (auto iter = prior_table_.lower_bound(priority::Medium); 
  iter != prior_table_.upper_bound(priority::Medium); ++iter) {
    os << std::setw(6) << std::left << "Medium";
    os << std::setw(0) << std::resetiosflags(std::ios::adjustfield);
    os << " -> ";
    for (auto i : iter->second) {
      os << i << ' ';
    }
    os << std::endl;
  }
  return os;
}

/**
 * @brief print from the table only the Low priority
 *
 */
std::ostream& Register::print_Low(std::ostream& os) const {
  for (auto iter = prior_table_.lower_bound(priority::Low); 
  iter != prior_table_.upper_bound(priority::Low); ++iter) {
    os << std::setw(6) << std::left << "Low";
    os << std::setw(0) << std::resetiosflags(std::ios::adjustfield);
    os << " -> ";
    for (auto i : iter->second) {
      os << i << ' ';
    }
    os << std::endl;
  }
  return os;
}