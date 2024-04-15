// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#pragma once

#include <iostream>
#include <string>

class Lattice;

class Cell {
 public:
  // Macros
  typedef int State;
  typedef int Position;

  // Constructor de la clase
  Cell() { posicion_ = 0, estado_ = 0; }
  Cell(const Position& posicion, const State& estado) : posicion_(posicion), estado_(estado){};

  // Getters
  State GetState() const { return estado_; };

  // Setters
  State SetState(State estado) {
    estado_ = estado;
    return estado_;
  }

  State SetPosicion(State posicion) {
    posicion_ = posicion;
    return posicion_;
  }

  // Métodos
  void UpdateState();
  State NextState(const Lattice&);  // Regla 110
  

 private:
  State estado_;
  State estado_siguiente_;
  Position posicion_;
};

// inline std::ostream& operator<<(std::ostream& os, const Cell& cell) {
//   return cell.print(os);
// }
std::ostream& operator<<(std::ostream& os, const Cell& cell);