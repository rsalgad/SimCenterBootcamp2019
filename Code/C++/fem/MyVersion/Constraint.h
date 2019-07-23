#ifndef _CONSTRAINT
#define _CONSTRAINT

#include <iostream>

class Constraint {
 public:
  Constraint(int tag, int nodeTag, int crt1, int crt2, int crt3);
  int GetTag(void); 
  int GetNodeTag();
  const int *GetConstraint();

  void Print(std::ostream &s);
 private:
  int tag;
  int nodeTag;
  int constraint[3];
};

#endif
