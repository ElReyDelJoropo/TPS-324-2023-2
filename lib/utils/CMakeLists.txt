cmake_minimum_required(VERSION 3.10)

project(utils)

add_library(${PROJECT_NAME} src/menu.cpp)
add_library(lib::utils ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
