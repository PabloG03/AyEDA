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

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Nif.h"
#include "ABB.h"
#include "ABE.h"

typedef Nif Key;

/**
 * @brief Función que muestra el uso del programa
 * @param argc Número de argumentos
 * @param argv Argumentos
 * @param tipo_arbol Tipo de árbol a utilizar
 * @param opcion_inicializacion Opción de inicialización del árbol
 * @param cantidad_elementos Cantidad de elementos a insertar en el árbol
 * @param fichero Fichero con los elementos a insertar en el árbol
 * @return void
*/
void usage(int argc, char* argv[], char& tipo_arbol, char& opcion_inicializacion, int& cantidad_elementos, std::string& fichero) {
  bool tipo_arbol_set = false;
  if (argc > 7) {
    std::cout << "Error en la línea de órdenes. Uso: " << argv[0] << " <fichero>" << std::endl;
    exit(1);
  }
  for (int i = 1; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-h") {
      std::cout << "Uso: " << argv[0] << " [-ab <abe|abb>] [-init <manual|random|file> <n>] [<fichero>]" << std::endl;
      std::cout << "Descripción: " << std::endl;
      std::cout << "  -ab <abe|abb> : Tipo de árbol a utilizar (por defecto, abe)" << std::endl;
      std::cout << "  -init <manual|random|file> <n> : Inicialización del árbol (por defecto, manual)" << std::endl;
      std::cout << "    manual : Inicialización manual" << std::endl;
      std::cout << "    random : Inicialización aleatoria con n elementos" << std::endl;
      std::cout << "    file : Inicialización a partir de un fichero con n elementos" << std::endl;
      std::cout << "  <fichero> : Fichero con los elementos a insertar en el árbol" << std::endl;
      exit(0);
    }
    if (arg == "-ab" ) {
      tipo_arbol_set = true;
      if (i + 1 >= argc) {
        std::cout << "Error en la línea de órdenes." << std::endl;
        std::cout << "Uso de las opciónes incorrectas" << std::endl;
        std::cout << "Utilice la opción -h para más información" << std::endl << std::endl;
        exit(1);
      }
      arg = argv[i + 1];
      if (arg != "abe" && arg != "abb") {
        std::cout << "Error en la línea de órdenes." << std::endl;
        std::cout << "Para la opción -ab, los posibles parámetros son: <abe|abb>" << std::endl << std::endl;
        exit(1);
      }
      if (argv[i + 1] == "abe") {
        tipo_arbol = 'e';
      } else {
        tipo_arbol = 'b';
      }
    }

    if (arg== "-init" ) {
      if (i + 1 >= argc) {
        std::cout << "Error en la línea de órdenes." << std::endl;
        std::cout << "Uso de las opciónes incorrectas" << std::endl;
        std::cout << "Utilice la opción -h para más información" << std::endl << std::endl;
        exit(1);
      }
      arg = argv[i + 1];
      if (arg != "manual" && arg != "random" && arg != "file") {
        std::cout << "Error en la línea de órdenes." << std::endl;
        std::cout << "Para la opción -init, los posibles parámetros son: <manual|random|file>" << std::endl << std::endl;
        exit(1);
      }
      if (arg == "manual") {
        opcion_inicializacion = 'm';
      } 
      if (arg == "random") {
        opcion_inicializacion = 'r';
        if (i + 2 >= argc) {
          std::cout << "Error en la línea de órdenes." << std::endl;
          std::cout << "Uso de las opciónes incorrectas" << std::endl;
          std::cout << "Utilice la opción -h para más información" << std::endl << std::endl;
          exit(1);
        }
        if (atoi(argv[i + 2]) < 0) {
          std::cout << "Error en la línea de órdenes." << std::endl;
          std::cout << "Para la opción -init random, se tiene que pasar la cantidad de elementos a generar (mayor que 0)" << std::endl << std::endl;
          exit(1);
        }
        cantidad_elementos = atoi(argv[i + 2]);
      }
      arg = argv[i + 1];
      if (arg == "file") {
        opcion_inicializacion = 'f';
        if (i + 3 >= argc) {
          std::cout << "Error en la línea de órdenes." << std::endl;
          std::cout << "Uso de las opciónes incorrectas" << std::endl;
          std::cout << "Utilice la opción -h para más información" << std::endl << std::endl;
          exit(1);
        }
        if (atoi(argv[i + 2]) < 0) {
          std::cout << "Error en la línea de órdenes." << std::endl;
          std::cout << "Para la opción -init file, se tiene que pasar la cantidad de elementos que se pasarán por el archivo (mayor que 0)" << std::endl << std::endl;
          exit(1);
        }
        cantidad_elementos = atoi(argv[i + 2]);
        arg = argv[i + 3];
        fichero = arg;
      }
    }

  }
  if (tipo_arbol_set == false) {
    std::cout << "Error en la línea de órdenes." << std::endl;
    std::cout << "Para la opción -ab, los posibles parámetros son: <abe|abb>" << std::endl << std::endl;
    exit(1);
  }
}

int main(int argc, char* argv[]) {
  system("clear");
  AB<Key>* arbol;
  char tipo_arbol;
  char opcion_inicializacion;
  int cantidad_elementos;
  std::string fichero;
  usage(argc, argv, tipo_arbol, opcion_inicializacion, cantidad_elementos, fichero);

  if (tipo_arbol == 'b') {
    arbol = new ABB<Key>();
  } else {
    arbol = new ABE<Key>();
  }

  if (opcion_inicializacion == 'm') {
    std::cout << "Inicialización manual" << std::endl;
    std::cout << "Introduzca los elementos del árbol. Para finalizar introduzca un número negativo" << std::endl;
    Key dato;
    std::cin >> dato;
    while (dato >= 0) {
      arbol->insertar(dato);
      std::cin >> dato;
    }
  } else if (opcion_inicializacion == 'r') {
    std::cout << "Inicialización aleatoria" << std::endl;
    for (int i = 0; i < cantidad_elementos; i++) {
      Nif DNI (rand() % 89999999 + 10000000);
      arbol->insertar(DNI);
    }
  } else if (opcion_inicializacion == 'f'){
    std::cout << "Inicialización por fichero" << std::endl;
    std::ifstream file(fichero);
    if (!file.is_open()) {
      std::cout << "Error al abrir el fichero" << std::endl;
      exit(1);
    }
    Key dato;
    while (file >> dato) {
      arbol->insertar(dato);
    }
  }
  std::cout << std::endl;

  int opcion = 4;
  Key dato;
  while (opcion != 0) {
    std::cout << "=-=-=-=-=-=-=-=-=-= Menú =-=-=-=-=-=-=-=-=-=" << std::endl;
    std::cout << "         [1] Insertar clave" << std::endl;
    std::cout << "         [2] Buscar clave" << std::endl;
    std::cout << "         [3] Mostrar árbol inorden" << std::endl;
    std::cout << "         [4] Imprimir árbol por niveles" << std::endl;
    std::cout << "         [5] Mostrar árbol postorden" << std::endl;
    std::cout << "         [0] Salir" << std::endl;
    std::cout << "Introduzca una opción: ";
    std::cin >> opcion;
    system("clear");
    std::cout << "=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=" << std::endl;
    switch (opcion) {
      case 1:
        std::cout << "Introduzca el DNI a insertar: ";
        std::cin >> dato;
        std::cout << std::endl;
        arbol->insertar(dato);
        arbol->print();
        std::cout << std::endl;
        break;
      case 2:
        std::cout << "Introduzca el DNI a buscar" << std::endl;
        std::cin >> dato;
        unsigned t0, t1;
        t0 = clock();
        if (arbol->buscar(dato)) {
          std::cout << "El DNI está en el árbol" << std::endl;
        } else {
          std::cout << "El DNI no está en el árbol" << std::endl;
        }
        t1 = clock();
        std::cout << "Tiempo de ejecución: " << (double(t1 - t0) / CLOCKS_PER_SEC) << std::endl;
        std::cout << std::endl;
        break;
      case 3:
        arbol->inorden();
        std::cout << std::endl << std::endl;
        break;
      case 4:
        arbol->print();
        std::cout << std::endl << std::endl;
        break;
      case 5:
        arbol->postorden();
        std::cout << std::endl << std::endl;
        break;
      case 0:
        system("clear");
        std::cout << "Saliendo..." << std::endl;
        exit(0);
        break;
      default:
        std::cout << "Opción no válida" << std::endl << std::endl;
        break;
    }
  }

  return 0;
}