cmake_minimum_required(VERSION 3.22.0)
set(CMAKE_CXX_SANDART 20)
set(CMAKE_CXX_SANDART_REQUIRED True)

project(RacingSimulator)

set(lib_dll Air.cpp Air.h Boots.cpp Boots.h Broomstick.cpp Broomstick.h Camal.cpp Camal.h Camal_Fast.cpp Camal_Fast.h Centour.cpp Centour.h Eagle.cpp Eagle.h Ground.cpp Ground.h Сarpet.cpp Сarpet.h)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library (leaver_dll SHARED ${lib_dll})
add_executable(RacingSimulator RacingSimulator.cpp)
target_link_libraries (RacingSimulator leaver_dll)

