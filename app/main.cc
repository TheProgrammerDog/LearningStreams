#include "Register/register.hpp"
#include <iostream>

int main(int argc, char** argv) {
  long long int a = 10000000000000000;
  Register aux(a);
  std::cout << aux << std::endl;

  std::ofstream of("out.txt");
  of << aux;

  return 0;
}