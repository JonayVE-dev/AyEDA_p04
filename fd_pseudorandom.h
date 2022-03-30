#ifndef _FD_PSEUDORANDOM_H_
#define _FD_PSEUDORANDOM_H_

#include <cstdlib>

#include "dispersion_fuction.h"

template <class Key>
class fdPseudoRandom : public DispersionFunction<Key> {
 public:
  fdPseudoRandom(const unsigned n) : table_size_(n) {}
  unsigned operator()(const Key& k) const {
    srand(k);
    return rand() % table_size_;
  }

 private:
  unsigned table_size_;
};

#endif  // _FD_PSEUDORANDOM_H_