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

class Fecha {
 public:
  Fecha() : numero_(0) {}
  Fecha(long int numero) : numero_(numero) {}
  Fecha(std::string fecha) : fecha_(fecha) {
    for (int i = 0; i < fecha_.size(); i++) {
      numero_ += fecha_[i];
    }
  }
  long int get_numero() const {return numero_;}
  std::string get_fecha() const {return fecha_;}
  void set_fecha(std::string fecha) {fecha_ = fecha;}

  bool operator<(const Fecha& fecha) const {return numero_ < fecha.numero_;}
  bool operator>(const Fecha& Fecha) const {return numero_ > Fecha.numero_;}
  bool operator==(const Fecha& Fecha) const {return numero_ == Fecha.numero_;}
  bool operator!=(const Fecha& Fecha) const {return numero_ != Fecha.numero_;}
  bool operator<=(const Fecha& Fecha) const {return numero_ <= Fecha.numero_;}
  bool operator>=(const Fecha& Fecha) const {return numero_ >= Fecha.numero_;}
  Fecha& operator=(const Fecha& Fecha) {numero_ = Fecha.numero_; fecha_ = Fecha.fecha_; return *this;}

 private:
  long int numero_;
  std::string fecha_;
};

std::ostream& operator<<(std::ostream& os, const Fecha& Fecha) {
  os << Fecha.get_fecha();
  return os;
}

std::istream& operator>>(std::istream& is, Fecha& fecha) {
  std::string nueva;
  is >> nueva;
  fecha = Fecha(nueva);
  return is;
}