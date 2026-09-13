cmake_minimum_required(VERSION 3.10)
project(Atom-Simulation)

add_executable(bohr-atom scripts/bohr-atom.cpp)

target_include_directories(bohr-atom PRIVATE ${CMAKE_SOURCE_DIR}/external/raylib/include)

target_link_directories(bohr-atom PRIVATE ${CMAKE_SOURCE_DIR}/external/raylib/lib)

target_link_libraries(bohr-atom raylib opengl32 gdi32 winmm)