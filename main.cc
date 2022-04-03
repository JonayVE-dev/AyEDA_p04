#include <iostream>
#include "hash_table.h"
#include "fd_module.h"
#include "fd_pseudorandom.h"
#include "fd_sum.h"
#include "fe_lineal.h"
#include "fe_quadratic.h"
#include "fe_double_dispersion.h"
#include "fe_redispersion.h"
#include "string"

typedef long key;
int main() {
  // Tamaño de la tabla
  size_t table_size{0};
  std::cout << "Introduzca el tamaño de la tabla: ";
  std::cin >> table_size;
  
  // Selección de la función de dispersión
  char fd_option;
  DispersionFunction<key>* fd;
  std::cout << "Introduzca la función de dispersión a utilizar, M(Module), R(Pseudorandom), S(Sum): ";
  std::cin >> fd_option;
  switch (fd_option) {
    case 'M':
      fd = new fdModule<key>(table_size);
      break;
    case 'R':
      fd = new fdPseudoRandom<key>(table_size);
      break;
    case 'S':
      fd = new fdSum<key>(table_size);
      break;
    default:
      std::cerr << "Función de dispersión no valida" << std::endl;
      return 1;
      break;
  }
  
  // Técnica de dispersión utilizada, tamaño de bloque y función de exploración
  char disper_option, fe_option;
  size_t block_size = 0;
  ExplorationFunction<key>* fe = nullptr;
  std::cout << "Introduzca la técnica de dispersión a utilizar, A(Abierta), C(Cerrada): ";
  std::cin >> disper_option;
  if(disper_option == 'C') {
    std::cout << "Introduzca el tamaño del bloque: ";
    std::cin >> block_size;
    
    std::cout << "Introduzca la función de exploración a utilizar, L(Lineal), C(Cuadrática), D(DobleDispersión), R(Redispersión): ";
    std::cin >> fe_option;
    switch (fe_option) {
    case 'L':
      fe = new feLineal<key>;
      break;
    case 'C':
      fe = new feQuadratic<key>;
      break;
    case 'D':
      fe = new feDoubleDispersion<key>(*fd);
      break;
    case 'R':
      fe = new feRedispersion<key>;
      break;
    default:
      std::cerr << "Función de dispersión no valida" << std::endl;
      return 1;
      break;
    }
  }
  
  // Creación de la hash_table
  HashTable<key> table(table_size, fd, fe, block_size);

  // Menú de la hash_table
  while (true) {
    std::cout << "¿Qué operación desea realizar?" << std::endl;
    std::cout << "1. Buscar" << std::endl;
    std::cout << "2. Insertar" << std::endl;
    std::cout << "0. Salir" << std::endl;
    int option;
    std::cin >> option;
    key key_;
    switch (option) {
      case 0:
        std::cout << "FIN DEL PROGRAMA" << std::endl;
        // table.PrintTable();
        return 0;
        break;
      case 1:
        std::cout << "Introduzca la clave a buscar: ";
        std::cin >> key_;
        std::cout << "La clave" << (table.Search(key_) ? " se ha encontrado" : " no se ha encontrado") << std::endl;
        break;
      case 2:
        std::cout << "Introduzca la clave a insertar: ";
        std::cin >> key_;
        std::cout << "La clave" << (table.Insert(key_) ? " se ha insertado" : " no se ha insertado") << std::endl;
      break;
      default:
        std::cout << "Opción no válida" << std::endl;
      break;
    }
    std::cout << std::endl;
  }
  return 0;
}
