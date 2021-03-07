cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "-Wconversion -Wall -Werror -Wextra -pedantic")

project(atm)

include_directories(include)
 
file(GLOB SOURCES src/*.cpp)
 
add_executable(atm atm.cpp ${SOURCES})
