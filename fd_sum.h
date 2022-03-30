#ifndef _FD_SUM_H_
#define _FD_SUM_H_

#include "dispersion_fuction.h"

template <class Key>
class fdSum : public DispersionFunction<Key> {
 public:
  fdSum(const unsigned n) : table_size_(n) {}
  unsigned operator()(const Key& k) const {
    Key d = 0;
    Key x = k;
    while (x > 0) {
      Key y = x % 10;
      d += y;
      x /= 10;
    }
    return (d % table_size_);
  }

 private:
  unsigned table_size_;
};

#endif  // _FD_SUM_H_