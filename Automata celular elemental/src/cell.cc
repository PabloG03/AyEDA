// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#include "cell.h"

#include "lattice.h"


/*
 * @brief calcula el siguiente estado
 * @return Lattice& red
 */
Cell::State Cell::NextState(const Lattice& red) {
  // C(G+1)=(C(G)+R(G)+C(G)*R(G)+L(G)*C(G)*R(G))%2
  if (red.GetFrontera() == "openf") {  // Si la frontera es abierta y fría
    if (posicion_ == 0 || posicion_ == 1 || posicion_ == 2 || posicion_ == 3) {
      State izquierda = 0;
      State derecha = red.GetCell(posicion_ + 4).GetState();
      estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
      return estado_siguiente_;
    }
    if (posicion_ == red.GetSize() - 1 || posicion_ == red.GetSize() - 2 || posicion_ == red.GetSize() - 3 || posicion_ == red.GetSize() - 4) {
      State izquierda = red.GetCell(posicion_ - 4).GetState();
      State derecha = 0;
      estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
      return estado_siguiente_;
    }
  }
  if (red.GetFrontera() == "openc") {  // Si la frontera es abierta y caliente
    if (posicion_ == 0 || posicion_ == 1 || posicion_ == 2 || posicion_ == 3) {
      State izquierda = 1;
      State derecha = red.GetCell(posicion_ + 4).GetState();
      estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
      return estado_siguiente_;
    }
    if (posicion_ == red.GetSize() - 1 || posicion_ == red.GetSize() - 2 || posicion_ == red.GetSize() - 3 || posicion_ == red.GetSize() - 4) {
      State izquierda = red.GetCell(posicion_ - 4).GetState();
      State derecha = 1;
      estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
      return estado_siguiente_;
    }
  }
  if (red.GetFrontera() == "periodic") {  // Si la frontera es periódica
    if (posicion_ == 0 || posicion_ == 1 || posicion_ == 2 || posicion_ == 3) {
      State izquierda = red.GetCell(red.GetSize()- 4 - posicion_).GetState();
      State derecha = red.GetCell(posicion_ + 4 + posicion_).GetState();
      estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
      return estado_siguiente_;
    }
    if (posicion_ == red.GetSize() - 1 || posicion_ == red.GetSize() - 2 || posicion_ == red.GetSize() - 3 || posicion_ == red.GetSize() - 4) {
      State izquierda = red.GetCell(posicion_ - 4 ).GetState();
      State derecha = red.GetCell(4 - (red.GetSize()- posicion_)).GetState();
      estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
      return estado_siguiente_;
    }
  }
  // Calculo para el resto de casos que no se vean afectados por el tipo de
  // frontera
  State izquierda = red.GetCell(posicion_ - 1).GetState();
  State derecha = red.GetCell(posicion_ + 1).GetState();
  estado_siguiente_ = (estado_ + derecha + estado_ * derecha + izquierda * derecha * estado_) % 2;
  return estado_siguiente_;
}

/*
 * @brief actualiza el estado
 */
void Cell::UpdateState() { estado_ = estado_siguiente_; }

/*
 * @brief sobrecarga del operador
 * @param[in] std::ostream& os
 * @param[in] Cell& cell
 * @return salida de datos
 */
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.GetState() == 1) {
    os << "X";
  } else {
    os << " ";
  }
  return os;
}