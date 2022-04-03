#ifndef _FE_LINEAL_
#define _FE_LINEAL_

#include "exploration_function.h"

template <class Key>
class feLineal : public ExplorationFunction<Key> {
 public:
  // Constructores
  feLineal() {};
  // Sobrecarga del operador ()
  unsigned operator()(const Key& k, unsigned i) const { return i; }
};

#endif  // _FE_LINEAL_