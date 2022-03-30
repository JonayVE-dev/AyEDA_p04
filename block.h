#ifndef _BLOCK_H_
#define _BLOCK_H_

#include <vector>

#include "sequence.h"

template <class Key>
class Block : public Sequence<Key> {
 public:
  Block(const int& block_size) : block_size_(block_size) {
    data_.reserve(block_size);
  }
  bool search(const Key& k) const {
    for (int i = 0; i < data_.size(); ++i) {
      if (data_[i] == k) return true;
    }
    return false;
  }

  bool insert(const Key& k) {
    if (!search(k) && !isFull()) {
      data_.push_back(k);
      return true;
    }
    return false;
  }

  bool isFull() const { return data_.size() >= block_size_; }

 private:
  std::vector<Key> data_;
  size_t block_size_;
};

#endif  // _BLOCK_H_