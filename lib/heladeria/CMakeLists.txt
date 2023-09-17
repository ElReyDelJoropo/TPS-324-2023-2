cmake_minimum_required(VERSION 3.10)

project(heladeria)

add_library(${PROJECT_NAME} src/heladeria.cpp)
add_library(lib::heladeria ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
