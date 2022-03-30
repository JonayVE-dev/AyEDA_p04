#ifndef _SEQUENCE_H_
#define _SEQUENCE_H_

template <class Key>
class Sequence {
 public:
  virtual bool search(const Key& k) const = 0;
  virtual bool insert(const Key& k) = 0;
  virtual bool isFull() const = 0;
};

#endif  // _SEQUENCE_H_