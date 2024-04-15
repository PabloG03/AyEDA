// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#include "utilidad.h"

// Función usage para comprobar si se han pasado todos los archivos

void Usage(int argc, char* argv[]) {
  std::string cadena = "--help";
  if (argc > 1) {
    std::string ayuda = argv[1];
    if (ayuda == cadena) {
      std::cout << "A parte de los ejecutable se tiene que poner la cantidad "
                   "de celulas, el tipo de bordes y el fichero de entrada "
                << std::endl;
      std::exit(1);
    }
  }
  if (argc > 4 && argc < 3) {
    std::cout << "El programa necesita 4 argumentos. El ejecutable, la "
                 "cantidad de celulas, tipo de bordes y el fichero de entrada"
                 " escriba --help para más información"
              << std::endl;
    std::exit(1);
  }
}

/*
 * @brief función que devuelve la cantidad de células
 * @param[in] string con toda la información de entrada
 * @return tamaño del array
 */

int ConvertirCelula(std::string entrada_cell) {
  size_t posInicio = entrada_cell.find('<');
  size_t posFin = entrada_cell.find('>');
  int numero;

  // Verificar si se encontraron ambos caracteres
  if (posInicio != std::string::npos && posFin != std::string::npos &&
      posInicio < posFin) {
    std::string resultado =
        entrada_cell.substr(posInicio + 1, posFin - posInicio - 1);
    // std::cout << "Resultado: " << resultado << std::endl;
    int numero = stoi(resultado);
    return numero;
  } else {
    std::cout << "No se encontró ningún número." << std::endl;
  }
  return 0;
}

/*
 * @brief función que devuelve el tipo de frontera
 * @param[in] string con toda la información de entrada
 * @return tipo de frontera
 */

std::string ConvertirFrontera(std::string informacion) {
  size_t posInicio = informacion.find('=');
  size_t posFin = informacion.find('[');

  // Verificar si se encontraron ambos caracteres
  if (posInicio != std::string::npos && posFin != std::string::npos &&
      posInicio < posFin) {
    std::string frontera =
        informacion.substr(posInicio + 1, posFin - posInicio - 1);
    // std::cout << "Resultado: " << frontera << std::endl;
    return frontera;
  } else {
    std::cout << "No se encontró ningún número." << std::endl;
    return "";  // Devolver una cadena vacía en caso de error
  }
}

/*
 * @brief función que devuelve si es fría o caliente
 * @param[in] string con toda la información de entrada
 * @return fría o caliente
 */

int ConvertirFC(std::string informacion) {
  size_t posInicio = informacion.find('[');
  size_t posFin = informacion.find(']');
  int cifra;

  // Verificar si se encontraron ambos caracteres
  if (posInicio != std::string::npos && posFin != std::string::npos &&
      posInicio < posFin) {
    std::string resultado =
        informacion.substr(posInicio + 1, posFin - posInicio - 1);
    // std::cout << "Resultado: " << resultado << std::endl;
    int cifra = stoi(resultado);
  } else {
    std::cout << "No se encontró ningún número." << std::endl;
  }
  return cifra;
}

/*
 * @brief función que devuelve el nombre del archivo
 * @param[in] string con toda la información de entrada
 * @return nombre del archivo
 */

std::string ConvertirEntrada(std::string informacion) {
  size_t posInicio = informacion.find_last_of('<');
  size_t posFin = informacion.find_last_of('>');
  std::string entrada;

  // Verificar si se encontraron ambos caracteres
  if (posInicio != std::string::npos && posFin != std::string::npos &&
      posInicio < posFin) {
    std::string entrada =
        informacion.substr(posInicio + 1, posFin - posInicio - 1);
    //  std::cout << "Resultado: " << entrada << std::endl;
    return entrada;
  } else {
    std::cout << "No se encontró ningún número." << std::endl;
    return entrada;  // Devolver una cadena vacía en caso de error
  }
}

/*
 * @brief función que calcula toda la información en caso de tener archivo
 * @param[in] string con toda la información de entrada
 */

void ConFichero(char* argv[]) {
  std::string info = argv[1];
  std::string info_forntera = argv[2];
  std::string info_FC = argv[2];
  std::string info_entrada = argv[3];

  int numero_cell_final = ConvertirCelula(info);
  std::string tipo_frontera = ConvertirFrontera(info_forntera);
  int tipoFC = ConvertirFC(info_FC);
  std::string entrada = ConvertirEntrada(info_entrada);
}

/*
 * @brief función que calcula toda la información en caso de no tener archivo
 * @param[in] string con toda la información de entrada
 */
void SinFichero(char* argv[]) {
  std::string info = argv[1];
  std::string info_forntera = argv[2];
  std::string info_FC = argv[2];

  int numero_cell_final = ConvertirCelula(info);
  std::string tipo_frontera = ConvertirFrontera(info_forntera);
  int tipoFC = ConvertirFC(info_FC);
}


/*
 * @brief función que devuelve toda la información por fichero
 * @param[in] string nombre del fichero
 * @return string con toda la información del fichero
 */
std::string LeerArchivo(const std::string& nombre_archivo) {
  std::ifstream archivo(nombre_archivo);
  std::string contenido;
  std::string linea;

  if (archivo.is_open()) {
    while (std::getline(archivo, linea)) {
      contenido += linea;
      contenido += '\n';  // Agregar el carácter de nueva línea para mantener el
                          // formato del archivo
    }
    archivo.close();
  } else {
    std::cerr << "Error: No se pudo abrir el archivo " << nombre_archivo
              << std::endl;
  }

  return contenido;
}

/*
 * @brief función que rellena el lattice con los valores 
 * @param[in] const int tamano
 * @param[in] State estado
 * @param[in] Lattice& red
 */

void ConstruirLattice(Lattice& red, const int tamano, State estado) {
  for (Position i = 0; i < tamano; i++) {
    if (i == tamano / 2) {
      estado = 1;
    } else {
      estado = 0;
    }
    red.GetCell0(i).SetState(estado);
    red.GetCell0(i).SetPosicion(i);
  }
}

// void ConstruirLattice(Lattice& lattice, const int size,
//                       const std::string& datos, State estado) {
//   for (Position i = 0; i < size; i++) {
//     estado = datos[i] - '0';
//     lattice.GetCell0(i).SetState(estado);
//     lattice.GetCell0(i).SetPosicion(i);
//   }
// }


/*
 * @brief función que hace el algoritmo de la práctica
 * @param[in] string con el tipo de la frontera
 * @param[in] int tamaño celula
 * @param[in] Lattice ya construido
 */

void Algoritmo(int numero_cell_final, std::string tipo_frontera, Lattice& principal) {
  char opcion;
  while (true) {
    for (int i = 0; i < numero_cell_final; i++) {
      std::cout << principal.GetCell(i) << ' ';
    }
    std::cout << std::endl;
    std::cout << "Quieres ver la siguiente generación (y/n)";
    std::cin >> opcion;
    switch (opcion) {
      case 'y':
        std::cout << "Calculando siguiente generación: " << std::endl;
        principal.NextGeneration();
        break;
      case 'n':
        std::cout << "Saliendo del programa" << std::endl;
        return; // Aquí se sale de la función Algoritmo y, por ende, del programa.
      default:
        std::cout << "Esa opción no está disponible" << std::endl;
        break;
    }
  }
}
