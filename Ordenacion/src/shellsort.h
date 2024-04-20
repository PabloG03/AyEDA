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
class ShellSort : public SortMethod<Key> {
 public:
  /*
  * @brief Constructor de la clase ShellSort
  * @param sequence Secuencia de elementos
  * @param alfa Factor de reducción
  * @param traza Muestra la traza
  * reurn void
  */
  ShellSort(staticSequence<Key> sequence, float alfa, float traza) : SortMethod<Key>(sequence, traza), alfa_(alfa) {}

  /*
  * @brief Método de ordenación
  * @return void
  */
  void Sort() { 
    Shell_sort(this->sequence_, alfa_, this->sequence_.getSize(), this->getTraza());
  }
  
 private:
  float alfa_; // Factor de reducción
};