cmake_minimum_required(VERSION 3.10)

project(pilas)

add_library(${PROJECT_NAME} src/pilas.cpp)
add_library(lib::pilas ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
