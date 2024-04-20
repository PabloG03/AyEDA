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
#include <cstring>
#include <cstdlib>

#include "main_functions.h" 

int main (int argc, char *argv[]) {
  int size_secuencia{0};
  int codigo_ordenacion;
  std::string datos_secuencia; // Forma de introducir los datos de la secuencia
  bool mostrar_traza{0}; 
  std::string fichero_entrada;

  ComprobarArgumentos(argc, argv);
  
  size_secuencia = std::stoi(argv[2]);
  codigo_ordenacion = std::stoi(argv[4]);
  datos_secuencia = argv[6];

  char *lastArg = argv[argc - 1];
  int argLength = strlen(lastArg);
  char lastChar = lastArg[argLength - 1];
  if (lastChar == 'y'){
    mostrar_traza = true;
  } else {
    mostrar_traza = false;
  }

  if (argc == 10) {
    fichero_entrada = argv[7];
  }

  std::vector<Key> vector_data;
  
  if (datos_secuencia == "manual") {
    std::cout << "Introduce " << size_secuencia << " valores, intercalados por espacios\n";
    for (int i = 0; i < size_secuencia; i++) {
      int valor;
      std::cin >> valor;
      vector_data.push_back(valor);
    }

    std::cout << "Elementos introducidos: ";
    for (int i = 0; i < size_secuencia; i++) {
      std::cout << vector_data[i] << " ";
    }
    std::cout << std::endl;
  } 
  for (int i = 0; i < 10; i++) {
  if (datos_secuencia == "random") { // Si los datos se generan de forma aleatoria
    std::cout << "Elementos seleccionados aleatoriamente\n";
    for (int i = 0; i < size_secuencia; ++i) {
      vector_data.push_back(rand() % 100);
    } 

    // Mostramos los datos generados
    std::cout << "Elementos generados: ";
    for (int i = 0; i < size_secuencia; i++) {
      std::cout << vector_data[i] << " ";
    }
    std::cout << std::endl;
  }
  else if (datos_secuencia == "file") { // Si los datos se introducen mediante un fichero
    std::cout << "Elementos seleccionados desde: " << fichero_entrada << std::endl;

    std::ifstream fichero(fichero_entrada); // Abrimos el fichero
    if (!fichero) { // Si no se puede abrir el fichero
      std::cerr << "No se puede abrir el fichero " << fichero_entrada << std::endl;
      return 0;
    } 

    int valor;

    while (fichero >> valor) { // Mientras haya datos en el fichero
      vector_data.push_back(valor); // Almacenamos los datos en el vector
    }

    // Mostramos los datos almacenados
    std::cout << "Elementos almacenados: ";
    for (int i = 0; i < vector_data.size(); i++) {
      std::cout << vector_data[i] << " ";
    }
    std::cout << std::endl;

    fichero.close(); // Cerramos el fichero
  }

  staticSequence<Key> data(vector_data); // Creamos un objeto de la clase staticSequence
  SortMethod<Key>* ordenacion; // Creamos un puntero a la clase SortMethod
  int metodo_elegido {0};

  // Elegir el método de ordenación
  switch (codigo_ordenacion) {
    case 1: // Si se elige el método de ordenación por selección
      std::cout << "Seleccionado método de ordenación por selección" << std::endl;
      ordenacion = new Seleccion<Key>(data, mostrar_traza);
      break;
    case 2: // Si se elige el método de ordenación QuickSort
      std::cout << "Seleccionado método de ordenación QuickSort" << std::endl;
      ordenacion = new QuickSort<Key>(data, mostrar_traza);
      break;
    case 3: // Si se elige el método de ordenación ShellSort
      std::cout << "Seleccionado método de ordenación ShellSort" << std::endl;
      float alfa;
      std::cout << "Introduzca el valor de alfa (valor entre 0 y 1): ";
      std::cin >> alfa;
      ordenacion = new ShellSort<Key>(data, alfa, mostrar_traza);
      break;
    case 4: // Si se elige el método de ordenación HeapSort
      std::cout << "Seleccionado método de ordenación HeapSort" << std::endl;
      ordenacion = new HeapSort<Key>(data, mostrar_traza);
      break;
    case 5: // Si se elige el método de ordenación MergeSort
      std::cout << "Seleccionado método de ordenación RadixSort" << std::endl;
      ordenacion= new RadixSort<Key>(data, mostrar_traza);
      break;
    default:
      std::cout << "Opcion no valida" << std::endl;
      return 0;
  }

  // Ordenar el vector
  std::cout << "Ordenando..." << std::endl;
  ordenacion->Sort();
  }

  return 0;
}