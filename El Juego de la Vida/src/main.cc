// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#include <assert.h>

#include <fstream>
#include <iostream>

#include "cell.h"
#include "lattice.h"
#include "utilidad.h"

int main(int argc, char* argv[]) {
  usage(argc, argv);
  Lattice lattice;
  int filas;
  int columnas;
  bool init = false;

  for (int i = 0; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-size") {
      assert(i + 2 < argc);
      filas = std::stoi(argv[i + 1]);
      columnas = std::stoi(argv[i + 2]);
      lattice = Lattice(filas, columnas);
    }
    if (arg == "-init") {
      assert(i + 1 < argc);
      char* file = argv[i + 1];
      lattice = Lattice(file);
      init = true;
    }
    if (arg == "-border") {
      assert(i + 1 < argc);
      std::string border = argv[i + 1];
      ComprobarFrontera(border);
      lattice.setFrontera(border);
    }
  }
  State estado;
  char opcion;
  if (init == false) {
    while (true) {
      std::cout
          << " Quiere introducir el estado de las células manualmente? (s/n): ";
      std::cin >> opcion;
      if (opcion == 's') {
        int i, j;
        std::cout
            << "Introduzca las coordenadas de la célula que quiere cambiar: ";
        std::cin >> i >> j;
        std::cout << "Introduzca el estado de la célula (0/1): ";
        std::cin >> estado;
        lattice[Position(i, j)].SetState(estado);
      } else if (opcion == 'n') {
        break;
      } else {
        std::cout << "Opción no válida" << std::endl;
        continue;
      }
    }
  }

  std::cout << std::endl;
  lattice.PrintLattice();
  std::cout << std::endl;
  bool comprobar = false;

  while (true) {
    std::cout << "Seleccione una opción: " << std::endl;
    std::cout << "l: Imprimir lattice" << std::endl;
    std::cout << "p: Imprimir población" << std::endl;
    std::cout << "x: Salir" << std::endl;
    std::cout << "n: Siguiente generación" << std::endl;
    std::cout << "L: Siguientes 5 generaciones" << std::endl;
    std::cout << "s: Guarda el lattice" << std::endl;
    std::cout << "c: Solo mostrar los vivos" << std::endl;
    std::cout << "Opción: ";
    std::cin >> opcion;
    std::cout << std::endl;
    std::ofstream archivo("salida.txt");
    switch (opcion) {
      case 'l':
        lattice.PrintLattice();
        break;
      case 'p':
        lattice.Population();
        std::cout << std::endl;
        break;
      case 'x':
        return 0;
      case 'n':
        if (comprobar == false) {
          lattice.NextGeneration();
          lattice.PrintLattice();
        } else {
          lattice.NextGeneration();
          lattice.Population();
        }

        break;
      case 'L':
        if (comprobar == false) {
          for (int i = 0; i < 5; i++) {
            lattice.NextGeneration();
            lattice.PrintLattice();
            std::cout << std::endl;
          }
        } else {
          for (int i = 0; i < 5; i++) {
            lattice.NextGeneration();
            lattice.Population();
          }
        }
      case 's':
        for (int i = 0; i < lattice.GetFilas(); i++) {
          for (int j = 0; j < lattice.GetColumnas(); j++) {
            archivo << lattice[Position(i, j)].GetState() << " ";
          }
          archivo << std::endl;
        }
        archivo.close();

        break;

      case 'c':
      comprobar = true;
      break;

      default:
        std::cout << "Opción no válida" << std::endl;
        continue;
    }
  }
  return 0;
}