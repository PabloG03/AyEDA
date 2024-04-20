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

#include "funcion_dispersion.h"

template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  fdModule(const unsigned numero) : tableSize(numero) {}

  /*
  * @brief Devuelve el resto de la división de la clave entre el tamaño de la tabla
  * @param llave Clave a dispersar
  * @return Resto de la división de la clave entre el tamaño de la tabla
  */
  unsigned operator()(const Key& llave) const { 
    return llave % tableSize; 
  }
 private:
  unsigned tableSize; // Tamaño de la tabla
};