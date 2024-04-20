/* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Algoritmos y Estructuras de Datos Avanzadas
* Curso: 2º
* Práctica 3
* Autor: Pablo García Pérez
* Correo: alu0101496139@ull.edu.es
* Fecha: 07/03/2024
* source Autómata celular general
*/

#include <fstream>
#include <iostream>
#include "tabla_hash.h"
#include "fd_modulo.h"
#include "fd_pseudoaleatorio.h"
#include "fd_suma.h"
#include "fe_lineal.h"
#include "fe_cuadratica.h"
#include "fe_doble_dispersion.h"
#include "fe_redispersion.h"
#include "tarjeta.h"
#include "string"

typedef TarjetaDeRed key;

void ussage1(int argc, char* argv[]) {
  if (argc < 7) {
    std::cout << "Los argumentos que se le tienen que pasar al programa son: " << std::endl;
    std::cout << "./TablaHash -ts <tamaño> -fd <número_funcion_dispersion> -hash <abierta|cerrada> -bs <tamaño_bloque> -fe <funcion_exploracion"  << std::endl;
    std::cout << "Funciones de dispersión: 1.(Módulo) 2.(Pseudoaleatoria) 3.(Basada en la suma)" << std::endl << std::endl;
    exit(1);
  }
}

void ussage2(int argc, char* argv[]) {
  if (argc != 11) {
    std::cout << "Los argumentos que se le tienen que pasar al programa son: " << std::endl;
    std::cout << "./TablaHash -ts <tamaño> -fd <número_funcion_dispersion> -hash <open|close> -bs <tamaño_bloque> -fe <funcion_exploracion"  << std::endl;
    std::cout << "Funciones de dispersión: 1.(Módulo) 2.(Pseudoaleatoria) 3.(Basada en la suma)" << std::endl << std::endl;
    exit(1);
  }
}

void CambiarANumeroPrimo(size_t& tabla_size) { // esta funcion calcula el siguiente numero primo, para el tamaño de la tabla
  if (tabla_size == 0 || tabla_size == 1) {
    CambiarANumeroPrimo(++tabla_size);
  }
  for (int i = 2; i <= tabla_size/2; ++i) {
    if (tabla_size % i == 0) {
      CambiarANumeroPrimo(++tabla_size);
      break;
    }
  }
}

int main(int argc, char* argv[]) {
  system("clear"); // Limpiar la pantalla para que el programa se vea mejor
  ussage1(argc, argv);
  size_t tamano_de_tabla = std::atoi(argv[2]);
  CambiarANumeroPrimo(tamano_de_tabla);

  DispersionFunction<key>* fd; // se crea un objeto de la clase DispersionFunction, como es una clase abstracta, se crea un puntero
  char funcion_dispersion = *argv[4];
  switch (funcion_dispersion) { // dependiendo de la opcion elegida, escogemos la funcion
    case '1':
      fd = new fdModule<key>(tamano_de_tabla); // usamos la promocion de tipos
      break;
    case '2':
      fd = new fdPseudoRandom<key>(tamano_de_tabla);
      break;
    case '3':
      fd = new fdSum<key>(tamano_de_tabla);
      break;
    default:
      std::cerr << "La función de dispersión seleccionada no es valida" << std::endl;
      return 1;
      break;
  }

  std::string opcion_dispersion, funcion_exploracion;
  size_t tamano_bloque = 0;
  ExplorationFunction<key>* fe = nullptr; // se crea un objeto de la clase ExplorationFunction, como es una clase abstracta, se crea un puntero
  opcion_dispersion = argv[6];
  if (opcion_dispersion != "abierta" && opcion_dispersion != "cerrada") {
    std::cerr << "La opción de dispersión seleccionada no es valida" << std::endl;
    return 1;
  }
  if(opcion_dispersion == "cerrada") { // Si se selecciona dispersion cerrada debera elegir la funcion de exploracion y el tamaño del bloque
    ussage2(argc, argv);
    tamano_bloque = std::atoi(argv[8]);
    funcion_exploracion = argv[10];
    std::cout << "funcion exploración: " << funcion_exploracion << std::endl;
    if (funcion_exploracion == "lineal") {fe = new feLineal<key>;}
    else if (funcion_exploracion == "cuadratica") {fe = new feQuadratic<key>;}
    else if (funcion_exploracion == "dobledispersion") {fe = new feDoubleDispersion<key>(*fd);}
    else if (funcion_exploracion == "redispersion") {fe = new feRedispersion<key>;}
    else {
      std::cerr << "La función de exploración no es valida" << std::endl;
      return 1;
    }
  }
  HashTable<key> table(tamano_de_tabla, fd, fe, tamano_bloque);
  std::cout << std::endl;

  while (true) {
    std::cout << "Seleccione la operacion que desea utilizar" << std::endl;
    std::cout << "1. Buscar" << std::endl;
    std::cout << "2. Insertar" << std::endl;
    std::cout << "3. Salir" << std::endl << std::endl;
    std::cout << "Opción: ";
    int opcion;
    std::cin >> opcion;
    system("clear"); // Limpiar la pantalla para que el programa se vea mejor
    key clave;
    switch (opcion) {
      case 1:
        std::cout << "Introduzca la clave a ser buscada: ";
        std::cin >> clave;
        if (table.Search(clave)) {
          std::cout << "La clave ha podido ser encontrada con éxito" << std::endl;
        } else {
          std::cout << "La clave no ha podido ser encontrada con éxito" << std::endl;
        }
        break;
      case 2:
        std::cout << "Introduzca la clave a ser insertada: ";
        std::cin >> clave;
        if (table.Insert(clave)) {
          std::cout << "La clave ha podido ser insertada con éxito" << std::endl;
        } else {
          std::cout << "La clave no ha podido ser insertada con éxito" << std::endl;
        }
        break;
      case 3:
        std::cout << "El programa ha finalizado" << std::endl << std::endl;
        table.PrintTable();
        std::cout << std::endl;
        return 0;
        break;
      default:
        std::cout << "La opción seleccionada no es válida" << std::endl;
        break;
    }
    std::cout << "Numero de comparaciones: " << contador << std::endl << std::endl;
  }
  return 0;
}
