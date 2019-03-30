cmake_minimum_required(VERSION 3.1...3.14)

if (${CMAKE_VERSION} VERSION_LESS 3.14)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(birthday-data VERSION 0.0.1 LANGUAGES CXX)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
