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

#include "sortMethods.h"
#include "algoritmos.h"

template<class Key> 
class HeapSort : public SortMethod<Key> {
 public:
  /*
  * @brief Constructor de la clase HeapSort
  * @param sequence Secuencia de elementos
  * @param traza Muestra la traza
  * return void
  */
  HeapSort(staticSequence<Key> sequence, bool traza) : SortMethod<Key>(sequence, traza) {}

  /*
  * @brief Método de ordenación
  * @return void
  */
  void Sort() {
    Heap_sort(this->sequence_, this->sequence_.getSize(), this->getTraza());
  }
};

