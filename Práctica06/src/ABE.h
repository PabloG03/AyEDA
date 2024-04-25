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
class ABE : public AB<Key> {
 public:
  ABE() : AB<Key>() {}
  virtual bool insertar(const Key& dato) override;
  virtual bool buscar(const Key& dato) const override;

 private:
  void insertar(Nodo<Key>* actual, Nodo<Key>* nuevo, int nivel);
  int get_tamanio(Nodo<Key>* actual, int tam) const;
  bool buscar(Nodo<Key>* actual, const Key& dato) const;
};

/**
 * @brief Función que inserta un dato en el árbol binario equilibrado
 * @param dato Dato a insertar
 * @return bool Devuelve true si se ha insertado correctamente
 */
template <class Key>
bool ABE<Key>::insertar(const Key& dato) {
  int nivel = 0;
  Nodo<Key>* nuevo = new Nodo<Key>(dato);
  if (this->raiz_ == NULL) {
    this->raiz_ = nuevo;
    nuevo->set_nivel(nivel);
    return true;
  }
  insertar(this->raiz_, nuevo, nivel);
}

/**
 * @brief Función que inserta un dato en el árbol binario equilibrado
 * @param actual Nodo actual
 * @param nuevo Nodo a insertar
 * @param nivel Nivel del nodo
 */
template <class Key>
void ABE<Key>::insertar(Nodo<Key>* actual, Nodo<Key>* nuevo, int nivel) {
  if (get_tamanio(actual->get_izquierda(), 0) <= get_tamanio(actual->get_derecha(), 0)) {
    if (actual->get_izquierda() != NULL) {
      insertar(actual->get_izquierda(), nuevo, nivel + 1);
    } else {
      actual->set_izquierda(nuevo);
      actual->get_izquierda()->set_nivel(nivel); 
    }
  } else {
    if (actual->get_derecha() != NULL) {
      insertar(actual->get_derecha(), nuevo, nivel + 1);
    } else {
      actual->set_derecha(nuevo);
      actual->get_derecha()->set_nivel(nivel); 
    }
  } 
}

/**
 * @brief Función que obtiene el tamaño del árbol/subárbol binario equilibrado
 * @param actual Nodo actual
 * @param tam Tamaño del árbol
 * @return int Tamaño del árbol
 */
template <class Key>
int ABE<Key>::get_tamanio(Nodo<Key>* actual, int tam) const {
  if (actual != NULL) {
    tam++;
    get_tamanio(actual->get_izquierda(), tam);
    get_tamanio(actual->get_derecha(), tam);
  }
}

/**
 * @brief Función que busca un valor en el árbol binario equilibrado
 * @param dato Dato a buscar
 * @return bool Devuelve true si se ha encontrado el dato
 */
template <class Key>
bool ABE<Key>::buscar(const Key& dato) const {
  Nodo<Key>* actual = this->raiz_;
  if (buscar(actual->get_derecha(), dato)) {
    return true;
  }
  if (buscar(actual->get_izquierda(), dato)) {
    return true;
  }
  return false;
}

/**
 * @brief Función que busca un valor en el árbol binario equilibrado
 * @param actual Nodo actual
 * @param dato Dato a buscar
 * @return bool Devuelve true si se ha encontrado el dato
 */
template <class Key>
bool ABE<Key>::buscar(Nodo<Key>* actual, const Key& dato) const {
  if (actual != NULL) {
    if (actual->get_dato() == dato) {
      return true;
    }
    buscar(actual->get_izquierda(), dato);
    buscar(actual->get_derecha(), dato);
  }
  return false;
}
