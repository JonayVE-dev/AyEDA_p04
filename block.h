#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>

#include "sequence.h"

template <class Key>
class Block : public Sequence<Key> {
 public:
  // Constructores
  Block() {};
  Block(const int& block_size) : block_size_(block_size) {
    data_.reserve(block_size);
  }
  // Métodos virtuales
  bool Search(const Key& k) const {
    for (size_t i = 0; i < data_.size(); ++i) {
      if (data_[i] == k) return true;
    }
    return false;
  }

  bool Insert(const Key& k) {
    if (!Search(k) && !IsFull()) {
      data_.push_back(k);
      return true;
    }
    return false;
  }

  bool IsFull() const { return data_.size() >= block_size_; }

 private:
  std::vector<Key> data_; // Contenedor de keys
  size_t block_size_; // Tamaño del contenedor
};

#endif  // _BLOCK_H_