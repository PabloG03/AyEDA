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

#include <iostream>

#include "bloque.h"
#include "funcion_exploracion.h"
#include "funcion_dispersion.h"
#include "lista.h"
#include "secuencia.h"

template <class Key>
class HashTable {
 public:

  /*
  * @brief Constructor de la tabla hash
  * @param table_size Tamaño de la tabla
  * @param fd Función de dispersión
  * @param fe Función de exploración
  * @param block_size Tamaño de bloque
  */
  HashTable(size_t table_size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, size_t block_size) : tableSize(table_size), funcionDispersion_(fd), funcionExploracion_(fe), block_size_(block_size) {
    table_ = new Sequence<Key>*[table_size]; // creamos una secuencia (de List o Block) de tamaño table_size
    if (funcionExploracion_ == nullptr) { // si la tabla es abierta
      for (size_t i = 0; i < table_size; ++i) { // en cada espacio de la secuencia insertamos un objeto
        table_[i] = new List<Key>(); // para cada elemento creamos un objeto List
      }
    } else { // si es cerrada
      for (size_t i = 0; i < table_size; ++i) { // en cada espacio de la secuencia insertamos un objeto
        table_[i] = new Block<Key>(block_size_); // para cada elemento creamos un objeto Block
      }
    }
  };

  ~HashTable() {
    for (size_t i = 0; i < tableSize; ++i) {
      delete table_[i];
    }
    delete table_;
  }

  /*
  * @brief Busca una clave en la tabla
  * @param llave Clave a buscar
  * @return True si la clave está en la tabla, false si no
  */
  bool Search(const Key& llave) const {
    unsigned table_pos = (*funcionDispersion_)(llave); // adivina el movimiento
    if (funcionExploracion_ != nullptr) { // si es cerrada
      for (size_t i = 0; i < tableSize; ++i) { // exploramos toda la tabla
        unsigned exploration_value = (*funcionExploracion_)(llave, i); // se averigua el valor
        if (table_[(table_pos + exploration_value) % tableSize]->Search(llave)) return true; // el valor existe en la tabla, true
        if (!table_[table_pos]->IsFull()) return false; // si no esta llena y no lo encontro, false
      }
    }
    if (table_[table_pos]->Search(llave)) return true; // si es cerrada simplemente deberia encontrarlo
    return false; // sino lo encontró, false
  }

  /*
  * @brief Inserta una clave en la tabla
  * @param llave Clave a insertar
  * @return True si la clave se ha insertado correctamente, false en caso contrario
  */
  bool Insert(const Key& llave) {
    contador = 0;
    unsigned table_pos = (*funcionDispersion_)(llave); // = funcion de distribucion (k) esto nos da su posicion en la tabla
    if (funcionExploracion_ != nullptr) { // si es cerrada
      for (size_t i = 0; i < tableSize; ++i) { // exploramos toda la tabla
        unsigned exploration_value = (*funcionExploracion_)(llave, i); // = funcion de exploracion (k, i) esto nos da el patron de exploracion
        if (!table_[(table_pos + exploration_value) % tableSize]->Search(llave) && !table_[(table_pos + exploration_value) % tableSize]->IsFull()) {// sino la clave no ha sido introducida y no esta llena
          table_[(table_pos + exploration_value) % tableSize]->Insert(llave); // entonces, se inserta
          return true;
        }
        if (table_[(table_pos + exploration_value) % tableSize]->Search(llave)) return false; // si ya se habia introducido dicho elemento
      }
      return false;
    }
    if (table_[table_pos]->Search(llave)) return false; // si ya se habia introducido dicho elemento
    table_[table_pos]->Insert(llave); // al ser abierta sencillamente lo coloca y ya
    return true;
  }

  /*
  * @brief Imprime la tabla
  */
  void PrintTable() {
    std::cout << "-------------------------" << std::endl;
    for (size_t i = 0; i < tableSize; i++) { // en cada espacio de la secuencia insertamos un objeto
      std::cout << "Bloque " << i << std::endl; // para cada Bloque decimos el numero
      table_[i]->Print(); // e imprimimos el elemento que se encuentra en ese bloque
      std::cout << std::endl << std::endl; // finalizamos la linea
    }
    std::cout << "-------------------------" << std::endl;
  }
 private:
  size_t tableSize; // Tamaño de la tabla
  DispersionFunction<Key>* funcionDispersion_; // Función de dispersión
  ExplorationFunction<Key>* funcionExploracion_ = nullptr;  // Función de exploración
  size_t block_size_ = 0; // Tamaño de bloque
  Sequence<Key>** table_; // Contenedor de la tabla hash
};