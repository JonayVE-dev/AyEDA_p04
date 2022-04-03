#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <iostream>

#include "dispersion_fuction.h"
#include "exploration_function.h"
#include "sequence.h"
#include "list.h"
#include "block.h"

template <class Key>
class HashTable {
 public:
  HashTable(size_t table_size, DispersionFunction<Key>* fd, ExplorationFunction<Key>* fe, size_t block_size) : table_size_(table_size), fd_(fd), fe_(fe), block_size_(block_size) { 
    table_ = new Sequence<Key>[table_size];
    if (fe_ == nullptr) {
      for (size_t i = 0; i < table_size; ++i) {
        table_[i] = new List<Key>;
      }
    } else {
      for (size_t i = 0; i < table_size; ++i) {
        table_[i] = new Block<Key>(block_size_);
      }
    }
  };

  ~HashTable() {
    for (size_t i = 0; i < table_size_; ++i) {
        delete table_[i];
    }
    delete table_;
  }

  bool Search(const Key& k) const {
    unsigned table_pos = (*fd_)(k);
    for (size_t i = 0; i < table_size_; ++i) {
      unsigned exploration_value = (*fe_)(k, i); 

      if(table_[table_pos + exploration_value]->Search()) return true;

      if (!table_[table_pos]->IsFull())  return false;
    }
    return false;
    }

  bool Insert(const Key& k) {
    unsigned table_pos = (*fd_)(k);
    for (size_t i = 0; i < table_size_; ++i) {
      unsigned exploration_value = (*fe_)(k, i);

      if(!table_[table_pos + exploration_value]->Search() && !table_[table_pos + exploration_value->IsFull()]){
          table_[table_pos + exploration_value]->Insert(k);
          return true;
      }
      if(table_[table_pos + exploration_value]->Search()) return false;
    }
    return false;
  }

 private:
  size_t table_size_;
  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_ = nullptr;
  size_t block_size_ = 0;
  Sequence<Key>* table_;
};

#endif  // _HASH_TABLE_H