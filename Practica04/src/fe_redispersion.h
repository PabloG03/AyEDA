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

#include <cstdlib> // rand()

#include "funcion_exploracion.h"

template <class Key>
class feRedispersion : public ExplorationFunction<Key> {
 public:
  feRedispersion() {};

  /*
  * @brief Devuelve un número aleatorio
  * @param llave Clave a explorar
  * @param limite Tamaño de la tabla
  * @return Número aleatorio
  */
  unsigned operator()(const Key& llave, unsigned limite) const {
    srand(llave.getMACint_());
    int aleatorio = 0;
    for (unsigned j = 0; j < limite ; ++j) {
      aleatorio = rand();
    }
    return aleatorio;
  }
};