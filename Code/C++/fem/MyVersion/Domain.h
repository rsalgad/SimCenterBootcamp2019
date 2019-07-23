#ifndef _DOMAIN
#define _DOMAIN

#include <map>
#include "Constraint.h"
#include "Node.h"


class Domain {
 public:
  Domain();
  ~Domain();

  Node *getNode(int tag);
  Constraint *getConstraint(int tag);
  void Print(std::ostream &s);
  int AddNode(Node *theNode);
  int AddConstraint(Constraint *theConstraint);

 private:
  std::map<int, Node *>theNodes;
  std::map<int, Constraint *>theConstraints;
};

#endif
