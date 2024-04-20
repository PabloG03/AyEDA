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
#include<vector>

template<class Key> 
class Sequence {
  public:
    virtual Key& operator[](const int&) = 0;
};

template<class Key> 
class staticSequence : public Sequence<Key> {
 public:
  /*
  * @brief Constructor de la clase staticSequence
  * @param data vector de datos
  * @return void
  */
  staticSequence(std::vector<Key> data) : size_(data.size()), data_(data) {}

  /*
  * @brief getter del inicio
  * @return unsigned inicio
  */
  unsigned getStart() {return start_;}

  /*
  * @brief getter del tamaño
  * @return unsigned tamaño
  */
  unsigned getSize() {return size_;}

  /*
  * @brief getter de los datos
  * @return std::vector<Key> datos
  */
  std::vector<Key> getData() {return data_;}

  /*
  * @brief Sobrecarga del operador []
  * @param p posición
  * @return Key& dato
  */
  Key& operator[](const int& p) {
    return data_[p];
  }

 protected:
  unsigned start_;
  unsigned size_;
  std::vector<Key> data_;
};