#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

template <class Key>
class Sequence {
 public:
  // Constructores
  Sequence() {};
  // Métodos virtuales
  virtual ~Sequence() {}
  virtual bool Search(const Key& k) const = 0;
  virtual bool Insert(const Key& k) = 0;
  virtual bool IsFull() const = 0;
};

#endif  // _SEQUENCE_H_