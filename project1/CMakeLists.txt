cmake_minimum_required(VERSION 3.23)
project(project1)

set(CMAKE_CXX_STANDARD 23)

add_executable(project1 main.cpp DiningPhilosophers.cpp DiningPhilosophers.h)
