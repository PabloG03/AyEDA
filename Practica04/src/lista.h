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

#include <vector>

#include "secuencia.h"


template <class Key>
class List : public Sequence<Key> {
 public:
  List() {};

  /*
  * @brief Busca una clave en la lista
  * @param k Clave a buscar
  * @return True si la encuentra, false si no
  */
  bool Search(const Key& k) const{
    for (size_t i = 0; i < data_.size(); ++i) {
      ++contador;
      if (data_[i] == k) return true;
    }
    return false;
  }

  /*
  * @brief Inserta una clave en la lista
  * @param k Clave a insertar
  * @return True si la clave se ha insertado correctamente, false en caso contrario
  */
  bool Insert(const Key& k) {
    if (!Search(k)) {
      data_.push_back(k);
      return true;
    }
    return false;
  }

  /*
  * @brief Devuelve si la lista está llena
  * @return True si la lista está llena, false en caso contrario
  */
  bool IsFull() const { return false; }

  /*
  * @brief Imprime la lista
  */
  void Print() {
    for(auto const& llave : data_) std::cout << llave << ' ';
  }
 private:
  std::vector<Key> data_; // Vector de claves
};