// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#pragma once

#include <fstream>
#include <iostream>
#include <vector>

#include "cell.h"

class Cell;
typedef std::pair<int,int> Position;

class Lattice {
 public:
  // Constructor
  Lattice() {
    nfilas_ = 0;
    ncolumnas_ = 0;
  }
  Lattice(const int nfilas, const int ncolumnas);
  Lattice(const char* file);

  // Getters
  const int GetFilas() const { return nfilas_; }
  const int GetColumnas() const { return ncolumnas_; };
  const Cell& GetReflectiveCell(int x, int y) const;
  const Cell GetCell(int x, int y) const;
  const std::string& GetFrontera() const { return frontera_; };

  // Setters
  void SetFilas(const int filas) { nfilas_ = filas; }

  void SetColumnas(const int columnas) { ncolumnas_ = columnas; }
  void setFrontera(std::string& frontera) { frontera_ = frontera; }

  // Métodos
  bool isValidCell(int row, int col) const;
  void Population();
  void PrintLattice();
  void NextGeneration();
  bool ComprobarCeldas();
  void Anadir();
  void AnadirFilaInicio();
  void AnadirFilaFinal();
  void AnadirColumnaInicio();
  void AnadirColumnaFinal();
  void Corregir();

  // Sobrecargas
  Cell& operator[](const Position& position);

 private:
  std::vector<std::vector<Cell> > lattice_;
  int nfilas_;
  int ncolumnas_;
  std::string frontera_;
  bool filainit;
  bool filafin;
  bool columnainit;
  bool columnafin;
};


