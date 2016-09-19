cmake_minimum_required(VERSION 3.6)
project(RestBuilder)


include_directories(/usr/share/JLexx)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES RestMain.cpp)
add_executable(RestBuilder ${SOURCE_FILES})