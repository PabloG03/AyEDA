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

#include <iostream>
#include <string>

class Nif {
 public:
  Nif () {}
  Nif(long nif) : LongNif_(nif) {}

  long int getLong() { return LongNif_; } 

  friend std::ostream& operator<<(std::ostream& os, const Nif& nif);
  bool operator==(const Nif& nif) const;
  bool operator<(const Nif& nif) const;
  bool operator>(const Nif& nif) const;
  bool operator<=(const Nif& nif) const;
  bool operator>=(const Nif& nif) const;
  bool operator!=(const Nif& nif) const;

  Nif operator+(const Nif& nif) const {
    return Nif(LongNif_ + nif.LongNif_);
  }

  Nif operator-(const Nif& nif) const {
    return Nif(LongNif_ - nif.LongNif_);
  }

  Nif operator*(const Nif& nif) const {
    return Nif(LongNif_ * nif.LongNif_);
  }

  Nif operator/(const Nif& nif) const {
    return Nif(LongNif_ / nif.LongNif_);
  }

  Nif operator%(const Nif& nif) const {
    return Nif(LongNif_ % nif.LongNif_);
  }

  Nif& operator=(const Nif& nif) {
    LongNif_ = nif.LongNif_;
    return *this;
  }
  
  char operator[](int i) {
    std::string nif = std::to_string(LongNif_);
    return nif[i];
  }

  long int getINT() {
    return LongNif_;
  }

 private:
  long LongNif_;
};

bool Nif::operator==(const Nif& nif) const {
  return LongNif_ == nif.LongNif_;
}

bool Nif::operator<(const Nif& nif) const {
  return LongNif_ < nif.LongNif_;
}

std::ostream& operator<<(std::ostream& os, const Nif& nif) {
  os << nif.LongNif_;
  return os;
}

bool Nif::operator>(const Nif& nif) const {
  return LongNif_ > nif.LongNif_;
}

bool Nif::operator<=(const Nif& nif) const {
  return LongNif_ <= nif.LongNif_;
}

bool Nif::operator>=(const Nif& nif) const {
  return LongNif_ >= nif.LongNif_;
}

bool Nif::operator!=(const Nif& nif) const {
  return LongNif_ != nif.LongNif_;
}