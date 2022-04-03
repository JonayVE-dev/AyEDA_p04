#ifndef _LIST_H_
#define _LIST_H_

#include <vector>

#include "sequence.h"

template <class Key>
class List : public Sequence<Key> {
 public:
  // Constructores
  List() {};

  // Métodos virtuales
  bool Search(const Key& k) const{
    for (size_t i = 0; i < data_.size(); ++i) {
      if (data_[i] == k) return true;
    }
    return false;
  }

  bool Insert(const Key& k) {
    if (!Search(k)) {
      data_.push_back(k);
      return true;
    }
    return false;
  }

  bool IsFull() const { return false; }

  void Print() {
    for(auto const& k : data_) std::cout << k << ' ';
  }

 private:
  std::vector<Key> data_; // Contenedor de keys
};

#endif  // _LIST_H_