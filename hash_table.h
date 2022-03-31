#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <iostream>

#include "dispersion_fuction.h"
#include "exploration_function.h"
#include "sequence.h"

template <class Key>
class HashTable {
 public:
  bool search(const key& k) const;
  bool insert(const Key& k);

 private:
  size_t table_size_;
  size_t block_size = 0;
  Sequence<Key>* table_;

  DispersionFunction<Key>* fd_;
  ExplorationFunction<Key>* fe_ = nullptr;
};

#endif  // _HASH_TABLE_H