cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME badapple++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
  src/main.cpp
)
