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

#include "funcion_exploracion.h"

template <class Key>
class feQuadratic : public ExplorationFunction<Key> {
 public:
  feQuadratic() {};

  /*
  * @brief Devuelve el cuadrado de la posición
  * @param llave Clave a explorar
  * @param limite Tamaño de la tabla
  * @return Cuadrado de la posición
  */
  unsigned operator()(const Key& llave, unsigned limite) const { 
    return limite * limite; 
  }
}; 