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

#include "AB.h"

template <class Key>
class ABB : public AB<Key> {
 public:
  ABB() : AB<Key>() {}
  virtual bool insertar(const Key& dato) override;
  virtual bool buscar(const Key& dato) const override;

 private:
};

/**
 * @brief Función que inserta un dato en el árbol binario de busqueda
 * @param dato Dato a insertar
 * @return bool Devuelve true si se ha insertado correctamente
 */
template <class Key>
bool ABB<Key>::insertar(const Key& dato) {
  int nivel = 0;
  Nodo<Key>* nuevo = new Nodo<Key>(dato);
  if (this->raiz_ == NULL) {
    this->raiz_ = nuevo;
    nuevo->set_nivel(nivel);
    return true;
  }
  Nodo<Key>* actual = this->raiz_;
  Nodo<Key>* auxiliar = NULL;
  while (actual != NULL) {
    auxiliar = actual;
    if (dato < actual->get_dato()) {
      actual = actual->get_izquierda();
    } else if (dato > actual->get_dato()) {
      actual = actual->get_derecha();
    } else {
      return false;
    }
    nivel++;
  }
  nuevo->set_nivel(nivel);
  if (dato < auxiliar->get_dato()) {
    auxiliar->set_izquierda(nuevo);
  } else {
    auxiliar->set_derecha(nuevo);
  }
  return true;
}

/**
 * @brief Función que busca un dato en el árbol binario de busqueda
 * @param dato Dato a buscar
 * @return bool Devuelve true si se ha encontrado el dato
 */
template <class Key>
bool ABB<Key>::buscar(const Key& dato) const {
  Nodo<Key>* actual = this->raiz_;
  while (actual != NULL) {
    if (dato < actual->get_dato()) {
      actual = actual->get_izquierda();
    } else if (dato > actual->get_dato()) {
      actual = actual->get_derecha();
    } else if (dato == actual->get_dato()) {
      return true;
    }
  }
  return false;
}