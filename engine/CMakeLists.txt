cmake_minimum_required(VERSION 3.13)
project(CharmEngine)

set(CMAKE_CXX_STANDARD 11)
add_definitions(-std=c++11)
include(base/CMakeLists.txt)
include(particle/CMakeLists.txt)
include(opengl/CMakeLists.txt)
include(render/CMakeLists.txt)

include_directories(.)

set(SRC_ENGINE ${SRC_ENGINE_BASE} ${SRC_ENGINE_PARTICLE} ${SRC_ENGINE_OPENGL} ${SRC_ENGINE_RENDER} EngineContext.cpp)
add_library(CharmEngine STATIC ${SRC_ENGINE})
