#include "Register/register.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  std::ofstream file_out("file_out");
  Register reg1;
  reg1.append("El perro aaa", priority::High);
  reg1.append("El come 14", priority::Medium);
  reg1.append("La casa 3.4", priority::High);
  reg1.write(file_out);



  return 0;
}