#ifndef _DISPERSION_FUNCTION_H_
#define _DISPERSION_FUNCTION_H_

template <class Key>
class DispersionFunction {
 public:
  DispersionFunction() {};
  virtual unsigned operator()(const Key& k) const = 0;
};

#endif  // _DISPERSION_FUNCTION_H_