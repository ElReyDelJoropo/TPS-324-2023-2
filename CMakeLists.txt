cmake_minimum_required(VERSION 3.10)

project(TPS_UNA_2023_2 LANGUAGES CXX DESCRIPTION "Ejercicio 1" VERSION 1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(lib)

add_executable(${PROJECT_NAME} 
                src/main.cpp 
                src/heladeria_options.cpp 
                src/lista_options.cpp 
                src/arbol_options.cpp 
                src/pila_options.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} lib::heladeria lib::listas lib::pilas lib::utils lib::arbol)
