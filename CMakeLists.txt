cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME bad-term)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

project(${PROJECT_NAME})

file(GLOB_RECURSE SRC_FILES "src/*.cpp")
file(COPY assets/bad_apple.mp4 DESTINATION ${CMAKE_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SRC_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE ${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} ncurses)
