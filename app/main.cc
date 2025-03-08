#include "Register/register.hpp"
#include <iostream>

int main(int argc, char** argv) {
  Register reg;
  
  reg.append("perro el gato", priority::Medium);
  reg.append("el gato a", priority::High);
  reg.append("a", priority::Medium);
  reg.append("sjsjsjs", priority::Low);
  std::cout << reg;
  return 0;
}