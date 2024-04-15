// Universidad de La Laguna
// Escuela Superior de Ingenier ́ıa y Tecnolog ́ıa
// Grado en Ingenier ́ıa Inform ́atica
// Asignatura: AyEDA
// Curso: 2º
// Autor: Pablo García Pérez
// Correo: alu0101496139@ull.es

#include "cell.h"
#include "lattice.h"
#include "utilidad.h"

int main(int argc, char* argv[]) {
  // Función que no se llega a implementar
  Usage(argc, argv);
  if (argc == 4) {
    ConFichero(argv);
    std::string info_entrada = argv[3];
    std::string info_convertida = ConvertirEntrada(info_entrada);
    std::string contenido_archivo = LeerArchivo(info_convertida);
    std::cout << contenido_archivo;

  } else if (argc == 3) {
    std::string info = argv[1];
    std::string info_forntera = argv[2];
    std::string info_FC = argv[2];

    int numero_cell_final = ConvertirCelula(info);
    std::string tipo_frontera = ConvertirFrontera(info_forntera);
    int tipoFC = ConvertirFC(info_FC);
    if (tipo_frontera == "open") {
      if (tipoFC == 0) {
        tipo_frontera = "openf"; 

      } else if (tipoFC == 1) {
        tipo_frontera = "openc";
      }
    } else {
      tipo_frontera = "periodic";
    }
    Lattice principal(numero_cell_final, tipo_frontera);
    for (int i = 0; i < principal.GetSize(); i++) {
      if (i == (principal.GetSize() / 2)) {
        principal.GetCell0(i).SetState(1);
      } else {
        principal.GetCell0(i).SetState(0);
      }
      principal.GetCell0(i).SetPosicion(i);
    }
    Algoritmo(numero_cell_final, tipo_frontera, principal);
  }
  return 0;
}
