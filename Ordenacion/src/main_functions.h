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

#include<iostream>
#include<vector>
#include<fstream>

#include "sortMethods.h"
#include "nif.h"
#include "sequence.h"
#include "seleccion.h"
#include "quicksort.h"
#include "shellsort.h"
#include "heapsort.h"
#include "radixsort.h"

typedef Nif Key;

/*
* @brief Función que muestra la ayuda del programa
* return void
*/
void Usage () {
    std::cout << "Este programa ordena una secuencia de números enteros" << std::endl;
    std::cout << "Los argumentos para la ejecución del programa son:" << std::endl;
    std::cout << "-size <s>, s es el tamaño de la secuencia." << std::endl;
    std::cout << "-ord <m>, m es el código que identifica un método de ordenación." << std::endl;
    std::cout << "-init <i> [f], indica la forma de introducir los datos de la secuencia" << std::endl;
    std::cout << "i=manual" << std::endl;
    std::cout << "i=random" << std::endl;
    std::cout << "i=file f=nombre del fichero de entrada" << std::endl;
    std::cout << "-trace <y|n>, indica si se muestra o no la traza durante la ejecución." << std::endl;
    exit(1);
}

/*
* @brief Función que comprueba que los argumentos introducidos son correctos
* @param argc número de argumentos
* @param argv argumentos
* return void
*/
void ComprobarArgumentos(int argc, char *argv[]) {

  if (std::string(argv[1]) == "--help") {
    Usage();
  }
  
  if (argc < 9 || argc > 10) {
    std::cerr << "Error en la introducción de los argumentos. Pruebe: " << argv[0] << "--help\n";
    exit(1);
  }

  if (argc == 9) {
    if (std::string(argv[1]) != "-size" || std::string(argv[3]) != "-ord" || std::string(argv[5]) != "-init" || std::string(argv[7]) != "-trace") {
      std::cerr << "Error en la introducción de los argumentos. Pruebe: " << argv[0] << "--help\n";
        exit(1);
    }
  } 
  else if (argc == 10) {
    if (std::string(argv[1]) != "-size" || std::string(argv[3]) != "-ord" || std::string(argv[5]) != "-init" || std::string(argv[8]) != "-trace") {
      std::cerr << "Error en la introducción de los argumentos. Pruebe: " << argv[0] << "--help\n";
        exit(1);
    }
  }

  if (atoi(argv[2]) <= 0) {
    std::cout << atoi(argv[2]) << std::endl;
    std::cerr << "Error en el tamaño de la secuencia" << std::endl;
    exit(1);
  }

  if (std::string(argv[6]) != "random" && std::string(argv[6]) != "manual" && std::string(argv[6]) != "file") {
    std::cerr << "Error en la forma de introducir los datos de la secuencia" << std::endl;
    exit(1);
  }

  if (std::stoi(argv[4]) != 1 && std::stoi(argv[4]) != 2 && std::stoi(argv[4]) != 3 && std::stoi(argv[4]) != 4 && std::stoi(argv[4]) != 5) {
    std::cerr << "Error en el código de ordenación" << std::endl;
    exit(1);
  }

  if (argv[6] == "file" && argv[7] == "") {
    std::cerr << "Error. No se especifica el fichero de entrada de la secuencia" << std::endl;
    exit(1);
  }

  if (argc == 10) {
    char *lastArg = argv[argc - 1];
    int argLength = strlen(lastArg);
    char lastChar = lastArg[argLength - 1];

    if (lastChar != 'y' && lastChar != 'n') {
      std::cerr << "Error en la selección de mostrar o no la traza" << std::endl;
      exit(1);
    }
  }
}

