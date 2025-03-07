cmake_minimum_required(VERSION 3.20)

project(
  Registers
  VERSION 0.1
  DESCRIPTION "practicando control de flujos"      
  LANGUAGES CXX  
)
include_directories(include)

add_subdirectory(src)
add_subdirectory(app)

