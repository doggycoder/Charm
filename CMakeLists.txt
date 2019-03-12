cmake_minimum_required(VERSION 3.13)
project(Charm)

add_definitions(-std=c++11)

set(LIBRARY_OUTPUT_PATH  ${CMAKE_CURRENT_SOURCE_DIR}/output)

add_subdirectory(engine)
add_subdirectory(test)
add_subdirectory(application)

include_directories(engine)
include_directories(test)

link_directories(${LIBRARY_OUTPUT_PATH})

include(window/CMakeLists.txt)

set(SRC_MAIN  main.cpp ${SRC_WINDOW})
add_executable(Charm ${SRC_MAIN})
target_link_libraries(Charm GLEW glut glfw3 GL X11 pthread dl CharmEngine ProjectTest)