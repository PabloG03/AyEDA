// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es
#pragma once;

#include <iostream>

#include "lattice.h"

typedef int State;
typedef std::pair<int, int> Position;
class Lattice;

class Cell {
  // Atributos públicos
 public:
  // Constructor
  Cell() {
    state_ = 0;
    nextState_ = 0;
    position_.first = 0;
    position_.second = 0;
  }
  Cell(const State& state, const Position& position) {
    state_ = state;
    position_ = position;
    nextState_ = 0;
  }

  // Getters
  State GetState() const { return state_; }
  Position GetPosition() const { return position_; };

  // Setters
  void SetState(State state) { state_ = state; };
  void SetPosition(Position position) { position_ = position; }

  // Métodos
  int NextState(Lattice& Latt);
  void UpdateState();

  // Atributos privados
 private:
  State state_;
  Position position_;
  State nextState_;
  void countVecinos(Lattice& Lat, int& vecinos);
};

std::ostream& operator<<(std::ostream& os, const Cell& cell);