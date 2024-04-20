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

// -------------------------------------------------- [Modificación]
#pragma once

#include <string>

class TarjetaDeRed {
 public:
  TarjetaDeRed() {}
  TarjetaDeRed(const long int& MACint_) : MACint_(MACint_) {}
  bool operator==(const long& MACint_) const { return MACint_ == MACint_; }
  bool operator==(const TarjetaDeRed& MACint_) const {
    return MACint_ == MACint_.getMACint_();
  }
  bool operator!=(const long& MACint_) const { return MACint_ != MACint_; }
  bool operator<(const long& MACint_) const { return MACint_ < MACint_; }
  bool operator>(const long& MACint_) const { return MACint_ > MACint_; }
  bool operator<=(const long& MACint_) const { return MACint_ <= MACint_; }
  bool operator>=(const long& MACint_) const { return MACint_ >= MACint_; }
  long int operator/=(long MACint_) const { return MACint_ / MACint_; }
  long int operator%=(long MACint_) const { return MACint_ % MACint_; }
  long int operator+(long MACint_) const { return MACint_ + MACint_; }
  long int operator+=(TarjetaDeRed& MACint_) const {
    return MACint_ + MACint_.getMACint_();
  }
  long int operator-(long MACint_) const { return MACint_ - MACint_; }
  long int operator*(long MACint_) const { return MACint_ * MACint_; }
  long int operator/(long MACint_) const { return MACint_ / MACint_; }
  long int operator%(long MACint_) const { return MACint_ % MACint_; }
  long int operator++() { return ++MACint_; }
  long int getMACint_() const { return MACint_; }
  int getvelocidad() const { return velocidad_; }
  std::string getmarca() const { return marca_; }
  std::string getmodelo() const { return modelo_; }
  int getsalidas() const { return salidas_; }
  std::string getMAC() const { return MAC_; }
  bool getAltaVelocidad() const { return altaVelocidad_; }
  void setMACint_(const long int& MACint) { MACint_ = MACint; }
  void setvelocidad(const int& velocidad) { velocidad_ = velocidad; }
  void setmarca(const std::string& marca) { marca_ = marca; }
  void setmodelo(const std::string& modelo) { modelo_ = modelo; }
  void setsalidas(const int& salidas) { salidas_ = salidas; }
  void setMAC(const std::string& MAC) { MAC_ = MAC; }
  void setAltaVelocidad(const bool& altaVelocidad) {
    altaVelocidad_ = altaVelocidad;
  }
  void changeMAC() {
    for (int i = 0; i < MAC_.size(); i++) {
      if (MAC_[i] == ':') {
        MACint_ = MACint_;
      } else {
        MACint_ += MAC_[i];
      }
    }
  }

 private:
  long int MACint_ = 0;
  std::string MAC_;
  int velocidad_;
  std::string marca_;
  std::string modelo_;
  int salidas_;
  bool altaVelocidad_;
};

/*
 * @brief Sobrecarga del operador de salida
 * @param os Flujo de salida
 * @param MACint_ MACint_ a imprimir
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& os, const TarjetaDeRed& MACint_) {
  os << MACint_.getMAC() << " " << MACint_.getvelocidad() << " "
     << MACint_.getmarca() << " " << MACint_.getmodelo() << " "
     << MACint_.getsalidas() << std::endl;
  return os;
}

/*
 * @brief Sobrecarga del operador de entrada
 * @param is Flujo de entrada
 * @param MACint_ MACint_ a leer
 * @return Flujo de entrada
 */
std::istream& operator>>(std::istream& is, TarjetaDeRed& MACint) {
  std::string aux;
  int aux2;
  bool aux3;
  is >> aux;
  MACint.setMAC(aux);
  MACint.changeMAC();
  is >> aux2;
  MACint.setvelocidad(aux2);
  is >> aux;
  MACint.setmarca(aux);
  is >> aux;
  MACint.setmodelo(aux);
  is >> aux2;
  MACint.setsalidas(aux2);
  is >> aux3;
  MACint.setAltaVelocidad(aux3);
  return is;
}