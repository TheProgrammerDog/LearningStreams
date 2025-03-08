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
#include <sstream>

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

std::ostream& Register::print(std::ostream& os, std::bitset<3> flags) const {
  if (flags[0]) print_High(os);
  if (flags[1]) print_Medium(os);
  if (flags[2]) print_Low(os);
  return os;
}

std::ofstream& Register::write(std::ofstream& ofs) const {
  for (auto iter : prior_table_) {
    if (iter.first == priority::High) ofs << HIGH;
    else if (iter.first == priority::Medium) ofs << MEDIUM;
    else ofs << LOW;

    for (auto vec_iter : iter.second) {
      write_byte(ofs, vec_iter);
      if (vec_iter != iter.second.back()) ofs << SEPARATOR;
      
    }
  }
  return ofs;
}

std::ofstream& Register::write_byte(std::ofstream& ofs, const std::string& a) const {
  const std::regex rint("^(\\-?\\d+)$");
  const std::regex rflo("^(\\-?\\d+.\\d+)$");

  std::smatch match;
  if (std::regex_match(a, match, rint)) {
    std::cout << "is a int" << std::endl;
    int num = std::stoi(match[1]);
    ofs << INT;
    ofs.write(reinterpret_cast<char*>(&num), sizeof(num));

  }
  else if (std::regex_match(a, match, rflo)) {
    std::cout << "is a float" << std::endl;
    float num = std::stof(match[1]);
    ofs << FLOAT;
    ofs.write(reinterpret_cast<char*>(&num), sizeof(num));
  }
  else {
    for (auto iter : a) {
      ofs << iter;
    }
  }
  return ofs;
}