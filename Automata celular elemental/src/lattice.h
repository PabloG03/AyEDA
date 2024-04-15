// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#pragma once
#include <iostream>
#include <cassert>

typedef int State;
typedef int Position;

class Cell;

class Lattice {
 public:

 //Constructor
  Lattice(const int size, const std::string& frontera);
  Lattice(){}

 //Método
  void NextGeneration();

 //Getters
  Cell& GetCell0(const Position position) const;
  const Cell& GetCell(const Position position) const;
  const int GetSize() const;
  const std::string GetFrontera() const;


 private:
  int tamano_;
  Cell* celulas_;
  int generacion_;
  std::string frontera_;
};