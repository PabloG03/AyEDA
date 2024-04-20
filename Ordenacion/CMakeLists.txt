cmake_minimum_required(VERSION 3.0)

project(Ejercicio4
    VERSION 1.0
    DESCRIPTION "Tabla Hash"
    LANGUAGES CXX
)

# Establecer el compilador C++
set(CMAKE_CXX_COMPILER "g++")

# Establecer las banderas de compilación C++
set(CMAKE_CXX_FLAGS "-w -o -c -Wall -g -Wextra -pedantic -std=c++11")

# Obtener la lista de todos los archivos fuente en el directorio vowels_consonants_files
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc")

# Agregar los archivos fuente al ejecutable
add_executable(MetodosOrdenacion ${SOURCES})