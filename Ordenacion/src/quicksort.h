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
class QuickSort : public SortMethod<Key> {
 public:
  /*
  * @brief Constructor de la clase QuickSort
  * @param sequence Secuencia de elementos
  * @param traza Muestra la traza
  * return void
  */
  QuickSort(staticSequence<Key> sequence, bool traza) : SortMethod<Key>(sequence, traza) {}

  /*
  * @brief Método de ordenación
  * @return void
  */
  void Sort() {
    Quick_sort(this->sequence_, 0, this->sequence_.getSize()-1, this->getTraza(), this->comparaciones_, this->intercambios_);
    std::cout << "Comparaciones: " << comparaciones_ << std::endl;
    std::cout << "Intercambios: " << intercambios_ << std::endl;
  }

  int intercambios_ = 0;
  int comparaciones_ = 0;
};

