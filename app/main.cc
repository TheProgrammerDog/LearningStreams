#include "Register/register.hpp"
#include <iostream>
#include <fstream>
#include <string>

const std::string DEFAULT_NAME = "save";

int main(int argc, char** argv) {
  Register reg;
  std::ifstream file_in;
  if (argc == 1) {
    file_in.open(DEFAULT_NAME);
    if (!file_in.is_open()) {
      std::cerr << "fail to open default file: " 
        << DEFAULT_NAME << std::endl;
      return 1;
    }
    reg.read(file_in);
    reg.print(std::cout, 111);
    return 0;
  }


  return 0;
}