# min version 
cmake_minimum_required(VERSION 3.10)
#Project Name
project(Sprout)
#C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#Source files
file(GLOB SOURCES "src/*.cpp")
#Executables
add_executable(sprout ${SOURCES})