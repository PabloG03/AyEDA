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

#include <cstdlib>

#include "funcion_dispersion.h"

template <class Key>
class fdPseudoRandom : public DispersionFunction<Key> {
 public:
  fdPseudoRandom(const unsigned numero) : tableSize(numero) {}

  /*
  * @brief Devuelve un número pseudoaleatorio entre 0 y el tamaño de la tabla
  * @param llave Clave a dispersar
  * @return Número pseudoaleatorio entre 0 y el tamaño de la tabla
  */
  unsigned operator()(const Key& llave) const {
    srand(llave.getMACint_());
    return rand() % tableSize;
  }
 private:
  unsigned tableSize; // Tamaño de la tabla
};