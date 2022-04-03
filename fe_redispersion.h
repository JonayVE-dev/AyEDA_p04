#ifndef _FE_REDISPERSION_
#define _FE_REDISPERSION_

#include <cstdlib>

#include "exploration_function.h"

template <class Key>
class feRedispersion : public ExplorationFunction<Key> {
 public:
  // Constructores
  feRedispersion() {};
  // Sobrecarga del operador ()
  unsigned operator()(const Key& k, unsigned i) const {
    srand(k);
    int random{0};
    for (unsigned j = 0; j < i ; ++j) {
      random = rand();
    }
    return random;
  }
};
#endif  // _FE_REDISPERSION_