#ifndef _LIST_H_
#define _LIST_H_

#include <list>

#include "sequence.h"

template <class Key>
class List : public Sequence<Key> {
 public:
  bool search(const Key& k) {
    for (int i = 0; i < data_.size(); ++i) {
      if (data_[i] == k) return true;
    }
    return false;
  }

  bool insert(const Key& k) {
    if (!search(k)) {
      data_.push_back(k);
      return true;
    }
    return false;
  }

  bool isFull() const { return false; }

 private:
  std::list<Key> data_;
};

#endif  // _LIST_H_