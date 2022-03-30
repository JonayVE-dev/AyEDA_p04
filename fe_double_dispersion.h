#ifndef _FE_DOUBLE_DISPERSION_
#define _FE_DOUBLE_DISPERSION_

#include "dispersion_fuction.h"
#include "exploration_function.h"

template <class Key>
class feDoubleDispersion : public FuncionExploracion<Key> {
 public:
  feDoubleDispersion(const DispersionFunction<Key>& fd) : fd_(fd) {}
  unsigned operator()(const Key& k, unsigned i) const { return i * fd_(k); }

 private:
  DispersionFunction<Key>& fd_;
};

#endif  // _FE_DOUBLE_DISPERSION_