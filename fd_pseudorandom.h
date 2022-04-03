#ifndef _FD_PSEUDORANDOM_H_
#define _FD_PSEUDORANDOM_H_

#include <cstdlib>

#include "dispersion_fuction.h"

template <class Key>
class fdPseudoRandom : public DispersionFunction<Key> {
 public:
  // Constructores
  fdPseudoRandom(const unsigned n) : table_size_(n) {}
  // Sobrecarga del operador ()
  unsigned operator()(const Key& k) const {
    srand(k);
    return rand() % table_size_;
  }

 private:
  unsigned table_size_; // Tamaño de la tabla
};

#endif  // _FD_PSEUDORANDOM_H_