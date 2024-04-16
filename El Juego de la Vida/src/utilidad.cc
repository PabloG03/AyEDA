// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es


#include "utilidad.h"


/*
* @brief Función que comprueba si se han introducido los parámetros necesarios
* @param int número de argumentos
* @param char* array de argumentos
* @return void
*/
void usage(int argc, char* argv[]) {
  if (argc < 5 || argc > 7 ) {
    std::cout << argv[0] << ": Faltan parámetros" << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " -size <Filas> <Columnas> (-init <archivoDeEntrada>) -border <TipoDeFrontera>" << std::endl << std::endl;
    exit(EXIT_SUCCESS);
  }
  bool border = false;
  for (int i = 0; i < argc; i++) {
    std::string arg = argv[i];
    if (arg == "-border") {
      border = true;
    }
  }
  if (!border) {
    std::cout << argv[0] << ": Faltan parámetros" << std::endl;
    std::cout << "Modo de uso: " << argv[0] << " -size <Filas> <Columnas> (-init <archivoDeEntrada>) -border <TipoDeFrontera>" << std::endl << std::endl;
    exit(EXIT_SUCCESS);
  }
}

/*
* @brief Función que comprueba si el tipo de frontera introducido es válido
* @param std::string tipo de frontera
* @return void
*/
void ComprobarFrontera(std::string& border) {
  bool correcto = false;
  while (!correcto) {
    if (border == "reflective" || border == "noborder") {
      correcto = true;
    } else {
      std::cout << "Tipo de frontera no válido" << std::endl;
      std::cout << "Los tipos de frontera válidos son: reflective, noborder. Introduzca una de las dos opciones: ";
      std::cin >> border;
    }
  }
}