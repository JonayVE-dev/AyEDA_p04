#ifndef _LIST_H_
#define _LIST_H_

#include <vector>

#include "sequence.h"

template <class Key>
class List : public Sequence<Key> {
 public:
  List() {};
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

 private:
  std::vector<Key> data_;
};

#endif  // _LIST_H_