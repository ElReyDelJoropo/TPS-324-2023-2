cmake_minimum_required(VERSION 3.10)

project(arbol)

add_library(${PROJECT_NAME} src/arbol.cpp)
add_library(lib::arbol ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
