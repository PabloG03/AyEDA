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
class Block : public Sequence<Key> {
 public:
  Block() {};
  Block(const int& block_size) : blockSize(block_size) {
    datos_.reserve(block_size);
  }

  /*
  * @brief Busca una clave en el vector
  * @param llave Clave a buscar
  * @return true si la clave se encuentra en el vector, false en caso contrario
  */
  bool Search(const Key& llave) const {
    for (size_t i = 0; i < datos_.size(); ++i) {
      ++contador;
      if (datos_[i] == llave) return true;
    }
    return false;
  }

  /*
  * @brief Inserta una clave en el vector
  * @param llave Clave a insertar
  * @return true si la clave se ha insertado correctamente, false en caso contrario
  */
  bool Insert(const Key& llave) {
    if (!Search(llave) && !IsFull()) {
      datos_.push_back(llave);
      return true;
    }
    return false;
  }

  /*
  * @brief Devuelve si la
  * @param llave Clave a eliminar
  * @return true si la clave se ha eliminado correctamente, false en caso contrario
  */
  bool IsFull() const { return datos_.size() >= blockSize; }
  void Print() {
    for(auto const& llave : datos_) std::cout << llave << ' ';
  }

 private:
  std::vector<Key> datos_; // Vector de claves
  size_t blockSize; // Tamaño del vector
};