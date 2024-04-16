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
 * @brief Calcula el estado de la celula en la siguiente generación según las
 * reglas del automata
 * @param[in] Lat matriz de celulas
 * @return nextState_
 */
int Cell::NextState(Lattice& Lat) {
  int neighbors = 0;
  countVecinos(
      Lat, neighbors);  // Cuenta la cantidad de vecinos que tiene una célula
  switch (state_) {     // Si el estado es 1
    case 1:
      // Si el número de vecinos es 2 o 3 el estado es 1
      if (neighbors == 2 || neighbors == 3) {
        nextState_ = 1;
      } else {
        nextState_ = 0;
      }
      break;

    case 0:  // Si el estado es 0
      if (neighbors == 3) {
        nextState_ = 1;
      } else {
        nextState_ = 0;
      }
      break;
    default:
      break;
  }

  return nextState_;
}

/*
 * @brief Actualiza el estado de la celula según el estado calculado en
 * nextState_
 */
void Cell::UpdateState() { state_ = nextState_; }

/*
 * @brief Sobrecarga del operador <<
 * @param[in] os Stream de salida
 * @param[in] cell Celula
 * @return os
 */
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.GetState() == 1) {
    os << 'X';
  } else {
    os << ' ';
  }
  return os;
}

/*
 * @brief Cuenta el número de vecinos de una celula
 * @param[in] Lat matriz de celulas
 * @param[in] vecinos Número de vecinos
 */
void Cell::countVecinos(Lattice& lat, int& neighbors) {
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        neighbors = neighbors;
      } else if (i == 1 && j == 0) {
        if (lat.GetCell(position_.first + i +1, position_.second + j).GetState() == 1) {
          neighbors++;
        }
      } else if (i == -1 && j == 0) {
        if (lat.GetCell(position_.first + i -1, position_.second + j).GetState() == 1) {
          neighbors++;
        }
      } else if (j == -i || j == i) {
        if (lat.GetCell(position_.first + (i), position_.second + (j)).GetState() == 1) {
          neighbors++;
        }
      } else if (j == -1) {
        if (lat.GetCell(position_.first + i, position_.second + j -1).GetState() == 1) {
          neighbors++;
        }
      }
      else {
        if (lat.GetCell(position_.first + i, position_.second + j).GetState() == 1) {
          neighbors++;
        }
      }
    }
  }
}
