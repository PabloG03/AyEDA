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
#include "Nodo.h"
#include "Nif.h"
#include "Fechas.h"
#include <vector>

template <class Key>
class AB {
 public:
  AB() {}
  virtual bool insertar(const Key& dato) = 0;
  virtual bool buscar(const Key& dato) const = 0;
  virtual void inorden() const;
  virtual void postorden() const;
  void print() const;

 protected:
  Nodo<Key>* raiz_ = NULL;
  int nivel_;
  void inorden(Nodo<Key>* actual) const;
  void postorden(Nodo<Key>* actual) const;
  void print(Nodo<Key>* actual, std::vector<Nodo<Key> >& cola) const;
  void introducir(Nodo<Key>* actual, std::vector<Nodo<Key> >& cola) const;
};

/**
 * @brief Función que muestra el recorrido inorden del árbol binario de busqueda
 * @return void
 */
template <class Key>
void AB<Key>::inorden() const {
  Nodo<Key>* actual = this->raiz_;
  if (actual != NULL) {
    inorden(actual->get_izquierda());
    std::cout << actual->get_dato() << " ";
    inorden(actual->get_derecha());
  }
}

/**
 * @brief Función que muestra el recorrido inorden del árbol binario de busqueda
 * @param actual Nodo actual
 * @return void
 */
template <class Key>
void AB<Key>::inorden(Nodo<Key>* actual) const {
  if (actual != NULL) {
    inorden(actual->get_izquierda());
    std::cout << actual->get_dato() << " ";
    inorden(actual->get_derecha());
  }
}

/**
 * @brief Función que imprime el árbol
 * @return void
 */
template <class Key>
void AB<Key>::print() const {
  std::vector<Nodo<Key> > cola;
  Nodo<Key>* actual = this->raiz_;
  introducir(actual, cola);
  if (actual != NULL) {
    print(actual->get_izquierda(), cola);
    print(actual->get_derecha(), cola);
  }
  for (int i = 0; i < cola.size(); i++) {
    std::cout << cola[i].get_dato() << "    ";
    if (cola[i].get_nivel() != cola[i + 1].get_nivel()) {
      std::cout << std::endl;
    }
  }
}

/**
 * @brief Función que busca los nodos a imprimir
 * @param actual Nodo actual
 * @param cola Vector de nodos
 * @return void
 */
template <class Key>
void AB<Key>::print(Nodo<Key>* actual, std::vector<Nodo<Key> >& cola) const {
  if (actual != NULL) {
    introducir(actual, cola);
    print(actual->get_izquierda(), cola);
    print(actual->get_derecha(), cola);
  }
}

/**
 * @brief Función que introduce un nodo en el vector de nodos
 * @param actual Nodo actual
 * @param cola Vector de nodos
 * @return void
 */
template <class Key>
void AB<Key>::introducir(Nodo<Key>* actual, std::vector<Nodo<Key> >& cola) const {
  for (int i = 0; i < cola.size(); i++) {
    if (actual->get_nivel() < cola[i].get_nivel()) {
      cola.insert((cola.begin() + i), *actual);
      return;
    }
  }
  cola.push_back(*actual);
}

/**
 * @brief Función que muestra el recorrido postorden del árbol binario de busqueda
 * @return void
 */
template <class Key>
void AB<Key>::postorden() const {
  Nodo<Key>* actual = this->raiz_;
  if (actual != NULL) {
    postorden(actual->get_izquierda());
    postorden(actual->get_derecha());
    std::cout << actual->get_dato() << " ";
  }
}

/**
 * @brief Función que muestra el recorrido postorden del árbol binario de busqueda
 * @param actual Nodo actual
 * @return void
 */
template <class Key>
void AB<Key>::postorden(Nodo<Key>* actual) const {
  if (actual != NULL) {
    postorden(actual->get_izquierda());
    postorden(actual->get_derecha());
    std::cout << actual->get_dato() << " ";
  }
}