cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME bad-term)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

project(${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})