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
* @brief Constructor de la clase Lattice
* @param int número de filas
* @param int número de columnas
* @return void
*/
Lattice::Lattice(const int nfilas, const int ncolumnas) {
  nfilas_ = nfilas;
  ncolumnas_ = ncolumnas;
  for (int i = 0; i < nfilas_; i++) {
    lattice_.push_back(std::vector<Cell>());
    for (int j = 0; j < ncolumnas_; j++) {
      Cell cell;
      lattice_[i].push_back(cell);
      lattice_[i][j].SetPosition(Position(i, j));
    }
  }
}

/*
* @brief Constructor de la clase Lattice a partir de un archivo
* @param const char* nombre del archivo
* @return void
*/
Lattice::Lattice(const char* file) {
  std::string filasColumnas;
  std::ifstream archivo(file);
  getline(archivo, filasColumnas);
  // Resta para la tabla ASCII
  nfilas_ = filasColumnas[0] - '0';
  ncolumnas_ = filasColumnas[1] - '0';
  for (int i = 0; i < nfilas_; i++) {
    lattice_.push_back(std::vector<Cell>());
    getline(archivo, filasColumnas);
    for (int j = 0; j < ncolumnas_; j++) {
      Cell cell;
      lattice_[i].push_back(cell);
      lattice_[i][j].SetPosition(Position(i, j));
      lattice_[i][j].SetState(filasColumnas[j] - '0');
    }
  }
  archivo.close();
}



/*
* @brief calcula la población de la matriz
* @param void
* @return std::size_t población de la matriz
*/
void Lattice::Population() {
  int contador = 0;
  for (int i = 0; i < nfilas_; i++) {
    for (int j = 0; j < ncolumnas_; j++) {
      if (lattice_[i][j].GetState() == 1) {
        contador++;
      }
    }
  }
  std::cout << contador;
}

/*
* @brief get de una celda de la matriz
* @param void
* @return Cell celda
*/
const Cell Lattice::GetCell(int x, int y) const{
  if (x < 0 || x >= nfilas_ || y < 0 || y >= ncolumnas_) {
    if (frontera_ == "reflective") {
      return GetReflectiveCell(x, y);
    }
    if (frontera_ == "noborder") {
      return Cell(0, Position(x,y)); // Devuelve célula estado muerta (ojalá yo)
    }
  }
  return lattice_[x][y];
}

/*
* @brief get de una celda de la matriz con frontera reflectante
* @param int posición x
* @param int posición y
* @return Cell celda
*/
const Cell& Lattice::GetReflectiveCell(int x, int y) const{
  if (x < 0) {
    x += 1;
  }
  if (y < 0) {
    y += 1;
  }
  if (x >= nfilas_) {
    x -= 1;
  }
  if (y >= ncolumnas_) {
    y -= 1;
  }
  return lattice_[x][y];
}

/*
* @brief imprime la matriz
* @param void
* @return void
*/
void Lattice::PrintLattice() {
  for (int i = 0; i < nfilas_; i++) {
    std::cout << '|';
    for (int j = 0; j < ncolumnas_; j++) {
      std::cout << lattice_[i][j] << '|';
    }
    std::cout << std::endl;
  }
}

/*
* @brief calcula la siguiente generación de la matriz
* @param void
* @return void
*/
void Lattice::NextGeneration() {

  for (int i = 0; i < nfilas_; i++) {
    for (int j = 0; j < ncolumnas_; j++) {
      lattice_[i][j].NextState(*this);
    }
  }
  if (frontera_ == "noborder") {
    if (ComprobarCeldas() == true) {
      Anadir();
      Corregir();
    }
  }
  for (int i = 0; i < nfilas_; i++) {
    for (int j = 0; j < ncolumnas_; j++) {
      lattice_[i][j].UpdateState();
    }
  }
}

/*
* @brief sobrecarga del operador []
* @param Position posición
* @return Cell celda
*/
Cell& Lattice::operator[](const Position& position) {
  return lattice_[position.first][position.second];
}

/*
* @brief anade filas y columnas si es necesario
* @param void
* @return void
*/
void Lattice::Anadir() {
  if (columnafin == true) {
    AnadirColumnaFinal();
    ncolumnas_++;
  }
  if (columnainit == true) {
    AnadirColumnaInicio();
    ncolumnas_++;
  }
  if (filainit == true) {
    AnadirFilaInicio();
    nfilas_++;
  }
  if (filafin == true) {
    AnadirFilaFinal();
    nfilas_++;
  }
}

/*
* @brief anade una columna al inicio de la matriz
* @param void
* @return void
*/
void Lattice::AnadirColumnaInicio() {
  for (int i = 0; i < nfilas_; i++) {
    lattice_[i].insert(lattice_[i].begin(), Cell(0, Position(i, 0)));
  }
}

/*
* @brief anade una columna al final de la matriz
* @param void
* @return void
*/
void Lattice::AnadirColumnaFinal() {
  for (int i = 0; i < nfilas_; i++) {
    lattice_[i].push_back(Cell(0, Position(i, ncolumnas_)));
  }
}

/*
* @brief anade una fila al inicio de la matriz
* @param void
* @return void
*/
void Lattice::AnadirFilaInicio() {
  lattice_.insert(lattice_.begin(), std::vector<Cell>(ncolumnas_));
}

/*
* @brief anade una fila al final de la matriz
* @param void
* @return void
*/
void Lattice::AnadirFilaFinal() {
  lattice_.push_back(std::vector<Cell>(ncolumnas_));
}

/*
* @brief comprueba si hay celdas vivas en los bordes
* @param void
* @return void
*/
bool Lattice::ComprobarCeldas() {
  filainit = false;
  filafin = false;
  columnainit = false;
  columnafin = false;
  bool retorno = false;
  for (int i = 0; i < nfilas_; i++) {
    if (lattice_[i][0].GetState() == 1) {
      columnainit = true;
      retorno = true;
    }
    if (lattice_[i][ncolumnas_ - 1].GetState() == 1) {
      columnafin = true;
      retorno = true;
    }
  }
  for (int i = 0; i < ncolumnas_; i++) {
    if (lattice_[0][i].GetState() == 1) {
      filainit = true;
      retorno = true;
    }
    if (lattice_[nfilas_ - 1][i].GetState() == 1) {
      filafin = true;
      retorno = true;
    }
  }
  return retorno;
}

/*
* @brief corrige las posiciones de las celdas
* @param void
* @return void
*/
void Lattice::Corregir() {
  for (int i = 0; i < nfilas_; i++) {
    for (int j = 0; j < ncolumnas_; j++) {
      lattice_[i][j].SetPosition(Position(i, j));
    }
  }
}