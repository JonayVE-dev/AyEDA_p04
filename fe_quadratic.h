#ifndef _FE_QUADRATIC_
#define _FE_QUADRATIC_

#include "exploration_function.h"

template <class Key>
class feQuadratic : public ExplorationFunction<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const { return i * i; }
};

#endif  // _QUADRATIC_