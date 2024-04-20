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

#pragma once

#include<iostream>

#include "sequence.h"


template<class Key> 
class SortMethod {
 public:
  /*
  * @brief Constructor de la clase SortMethod
  * @param sequence secuencia a ordenar
  * @param traza booleano que indica si se quiere mostrar la traza
  * @return void
  */
  SortMethod(staticSequence<Key> sequence, bool traza) : sequence_{sequence}, traza_(traza) {}

  /*
  * @brief Método que devuelve la secuencia a ordenar
  * @return staticSequence<Key> secuencia a ordenar
  */
  bool getTraza() { return traza_; }
  virtual void Sort() = 0;

 protected:
  staticSequence<Key> sequence_;
  bool traza_;
  int comparaciones_ = 0;
  int intercambios_ = 0;
};