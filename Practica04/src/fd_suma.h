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
class fdSum : public DispersionFunction<Key> {
 public:
  fdSum(const unsigned numero) : tableSize(numero) {}

  /*
  * @brief Devuelve la suma de los dígitos de la clave
  * @param llave Clave a dispersar
  * @return Suma de los dígitos de la clave
  */
  unsigned operator()(const Key& llave) const {
    Key llave1 = 0;
    Key llave2 = llave;
    while (llave2 > 0) {
      Key llave3 = llave2 % 10;
      llave1 += llave3;
      llave2 /= 10;
    }
    return (llave1 % tableSize);
  }

 private:
  unsigned tableSize; // Tamaño de la tabla
};