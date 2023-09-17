cmake_minimum_required(VERSION 3.10)

project(listas)

add_library(${PROJECT_NAME} src/listas.cpp)
add_library(lib::listas ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
