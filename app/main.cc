#include "Register/register.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv) {
  float a = 2.5;
  std::ofstream file_out ("out");
  
  Register reg;
  //reg.append("el perro cosa", priority::Low);
  //reg.append("el gato no", priority::Medium);
  reg.append("El perro 2.3", priority::High);
  reg.append("La gata loca 100", priority::Medium);
  reg.write(file_out);

  return 0;
}