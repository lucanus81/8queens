cmake_minimum_required(VERSION 2.6)
project(8quuens)

add_definitions( -std=c++17 )

enable_testing()
add_subdirectory(src)
add_subdirectory(tests)
