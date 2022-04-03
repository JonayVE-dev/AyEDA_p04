#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <iostream>

#include "block.h"
#include "dispersion_fuction.h"
#include "exploration_function.h"
#include "list.h"
#include "sequence.h"

template <class Key>
class HashTable {
 public:
  // Constructores
  HashTable(size_t table_size, DispersionFunction<Key>* fd,
            ExplorationFunction<Key>* fe, size_t block_size)
      : table_size_(table_size), fd_(fd), fe_(fe), block_size_(block_size) {
    table_ = new Sequence<Key>*[table_size];
    if (fe_ == nullptr) {
      for (size_t i = 0; i < table_size; ++i) {
        table_[i] = new List<Key>();
      }
    } else {
      for (size_t i = 0; i < table_size; ++i) {
        table_[i] = new Block<Key>(block_size_);
      }
    }
  };

  // Destructor
  ~HashTable() {
    for (size_t i = 0; i < table_size_; ++i) {
      delete table_[i];
    }
    delete table_;
  }

  // Métodos para buscar una Key en la HashTable
  bool Search(const Key& k) const {
    unsigned table_pos = (*fd_)(k);
    if (fe_ != nullptr) {
      for (size_t i = 0; i < table_size_; ++i) {
        unsigned exploration_value = (*fe_)(k, i);

        if (table_[(table_pos + exploration_value) % table_size_]->Search(k))
          return true;

        if (!table_[table_pos]->IsFull()) return false;
      }
    }

    if (table_[table_pos]->Search(k)) return true;
    return false;
  }

  // Métodos para insertar una Key en la HashTable
  bool Insert(const Key& k) {
    unsigned table_pos = (*fd_)(k);
    if (fe_ != nullptr) {
      for (size_t i = 0; i < table_size_; ++i) {
        unsigned exploration_value = (*fe_)(k, i);

        if (!table_[(table_pos + exploration_value) % table_size_]->Search(k) &&
            !table_[(table_pos + exploration_value) % table_size_]->IsFull()) {
          table_[(table_pos + exploration_value) % table_size_]->Insert(k);
          return true;
        }
        if (table_[(table_pos + exploration_value) % table_size_]->Search(k))
          return false;
      }
      return false;
    }

    if (table_[table_pos]->Search(k)) return false;
    table_[table_pos]->Insert(k);
    return true;

  }

 private:
  size_t table_size_; // Tamaño de la tabla
  DispersionFunction<Key>* fd_; // Función de dispersión
  ExplorationFunction<Key>* fe_ = nullptr;  // Función de exploración
  size_t block_size_ = 0; // Tamaño de bloque
  Sequence<Key>** table_; // Contenedor de la hastble
};

#endif  // _HASH_TABLE_H