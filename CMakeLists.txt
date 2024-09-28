cmake_minimum_required(VERSION 3.15)

project(bad-term)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VIDEO_FILE "assets/bad_apple.mp4")

find_package(OpenCV REQUIRED)
find_package(Curses REQUIRED)

file(GLOB_RECURSE SOURCES "src/*.cpp")
file(COPY ${VIDEO_FILE} DESTINATION ${CMAKE_BINARY_DIR})

add_executable(bad-term ${SOURCES})

target_include_directories(bad-term PRIVATE ${OpenCV_INCLUDE_DIRS}
                                            ${CURSES_INCLUDE_DIR})
target_link_libraries(bad-term PRIVATE ${OpenCV_LIBS} ${CURSES_LIBRARIES}
                                       pthread)

include(GNUInstallDirs)

install(TARGETS bad-term DESTINATION ${CMAKE_INSTALL_LIBDIR}/bad-term)
install(FILES ${VIDEO_FILE} DESTINATION ${CMAKE_INSTALL_LIBDIR}/bad-term)

set(LAUNCHER_SCRIPT "${CMAKE_BINARY_DIR}/launcher/bad-term")
file(WRITE ${LAUNCHER_SCRIPT}
     "#!/bin/sh\n"
     "exec ${CMAKE_INSTALL_FULL_LIBDIR}/bad-term/bad-term \"$@\"\n")

file(
  COPY ${LAUNCHER_SCRIPT}
  DESTINATION ${CMAKE_BINARY_DIR}/launcher
  FILE_PERMISSIONS
    OWNER_READ
    OWNER_WRITE
    OWNER_EXECUTE
    GROUP_READ
    GROUP_WRITE
    GROUP_EXECUTE
    WORLD_READ
    WORLD_EXECUTE)

install(PROGRAMS ${LAUNCHER_SCRIPT} DESTINATION ${CMAKE_INSTALL_BINDIR})
