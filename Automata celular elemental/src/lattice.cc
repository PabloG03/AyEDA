// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#include "lattice.h"

#include "cell.h"
/*
 * @brief constructor de lattice
 * @param[in] int con el tamaño
 * @param[in] std::string frontera
 * @return objeto clase lattice
 */

Lattice::Lattice(const int size, const std::string& frontera) {
  generacion_ = 0;
  frontera_ = frontera;
  tamano_ = size;
  assert(size > 0);
  celulas_ = new Cell[size];
  assert(celulas_ != NULL);
}

/*
 * @brief retorna la posición de la celula
 * @param[in] la posicion
 * @return la información de la posicion
 */

const Cell& Lattice::GetCell(const Position position) const {
  assert(position >= 0 && position < tamano_);
  return celulas_[position];
}

/*
 * @brief retorna la posición de la celula
 * @param[in] la posicion
 * @return la información de la posicion
 */

Cell& Lattice::GetCell0(const Position position) const {
  assert(generacion_ == 0);
  assert(position >= 0 && position < tamano_);
  return celulas_[position];
}

/*
 * @brief retorna el tipo de frontera
 * @return tipo de forntera
 */

const std::string Lattice::GetFrontera() const { return frontera_; }


/*
 * @brief retorna el tamaño
 * @return tamaño
 */
const int Lattice::GetSize() const { return tamano_; }


/*
 * @brief calcula la siguiente generación
 */

void Lattice::NextGeneration() {
  for (Position i = 0; i < tamano_; i++) {
    celulas_[i].NextState(*this);
  }
  for (Position i = 0; i < tamano_; i++) {
    celulas_[i].UpdateState();
  }
}