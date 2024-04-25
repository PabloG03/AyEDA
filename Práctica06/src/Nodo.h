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

template <class Key>
class Nodo {
 public:
  Nodo(const Key& dato) : dato_(dato) {}
  Key& get_dato() {return dato_;}
  Nodo<Key>* get_derecha() {return derecha_;}
  Nodo<Key>* get_izquierda() {return izquierda_;}
  int get_nivel() {return nivel_;}
  void set_dato(const Key& dato) {dato_ = dato;}
  void set_derecha( Nodo<Key>* derecha) {derecha_ = derecha;}
  void set_izquierda( Nodo<Key>* izquierda) {izquierda_ = izquierda;}
  void set_nivel(int nivel) {nivel_ = nivel;}

 private:
  Key dato_;
  Nodo<Key>* derecha_ = NULL;
  Nodo<Key>* izquierda_ = NULL;
  int nivel_;
};