cmake_minimum_required(VERSION 3.14)
project(RandomMathApp LANGUAGES CXX)


add_subdirectory(external/linear-library)

add_executable(random_math_app main.cpp)

target_link_libraries(random_math_app PRIVATE LinearAlgebra::LinearAlgebra)
target_compile_features(random_math_app PRIVATE cxx_std_17)