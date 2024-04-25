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

class Nif {
 public:
  Nif() : numero_(0) {}
  Nif(long int numero) : numero_(numero) {}
  long int get_numero() const {return numero_;}

  bool operator<(const Nif& nif) const {return numero_ < nif.numero_;}
  bool operator>(const Nif& nif) const {return numero_ > nif.numero_;}
  bool operator==(const Nif& nif) const {return numero_ == nif.numero_;}
  bool operator!=(const Nif& nif) const {return numero_ != nif.numero_;}
  bool operator<=(const Nif& nif) const {return numero_ <= nif.numero_;}
  bool operator>=(const Nif& nif) const {return numero_ >= nif.numero_;}
  Nif& operator=(const Nif& nif) {numero_ = nif.numero_; return *this;}

 private:
  long int numero_;
};

std::ostream& operator<<(std::ostream& os, const Nif& nif) {
  os << nif.get_numero();
  return os;
}

std::istream& operator>>(std::istream& is, Nif& nif) {
  long int numero;
  is >> numero;
  nif = Nif(numero);
  return is;
}