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
#include "funcion_dispersion.h"

template <class Key>
class feDoubleDispersion : public ExplorationFunction<Key> {
 public:
  feDoubleDispersion(DispersionFunction<Key>& fd) : funcionDispersion_(fd) {}

  /*
  * @brief Devuelve el resultado de la función de dispersión multiplicado por el resultado de la función de dispersión
  * @param llave Clave a explorar
  * @param limite Tamaño de la tabla
  * @return Resultado de la función de dispersión multiplicado por el resultado de la función de dispersión
  */
  unsigned operator()(const Key& llave, unsigned limite) const { 
    return limite * funcionDispersion_(llave); 
  }
 private:
  DispersionFunction<Key>& funcionDispersion_; // Función de dispersión
};