#ifndef _FE_REDISPERSION_
#define _FE_REDISPERSION_

#include <cstdlib>

#include "exploration_function.h"

template <class Key>
class feRedispersion : public FuncionExploracion<Key> {
 public:
  unsigned operator()(const Key& k, unsigned i) const {
    srand(k);
    int random{0};
    for (int j = 0; j < i ; ++j) {
      random = rand();
    }
    return random;
  }
};
#endif  // _FE_REDISPERSION_