// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#pragma once
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

#include "lattice.h"
#include "cell.h"

void Usage(int argc, char* argv[]);
int ConvertirCelula(std::string);
std::string ConvertirFrontera(std::string);
int ConvertirFC(std::string);
std::string ConvertirEntrada(std::string);
void ConFichero(char* argv[]);
void SinFichero(char* argv[]);
std::string LeerArchivo(const std::string& nombre_archivo);
void ConstruirLattice(Lattice& red, const int tamano, State estado);
void ConstruirLattice(Lattice& lattice, const int size, const std::string& datos, State estado);
void Algoritmo(int numero, std::string tipo, Lattice&);

