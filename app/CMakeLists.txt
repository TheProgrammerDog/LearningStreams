add_executable(program main.cc)
target_compile_features(program PRIVATE cxx_std_20)

target_link_libraries(program register)
