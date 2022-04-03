#ifndef _FD_MODULE_H_
#define _FD_MODULE_H_

#include "dispersion_fuction.h"

template <class Key>
class fdModule : public DispersionFunction<Key> {
 public:
  // Constructores
  fdModule(const unsigned n) : table_size_(n) {}
  // Sobrecarga del operador ()
  unsigned operator()(const Key& k) const { return k % table_size_; }

 private:
  unsigned table_size_; // Tamaño de la tabla
};

#endif  // _FD_MODULE_H_