#include <iostream>
#include "Node.h"
#include "Domain.h"
#include "Constraint.h"

int main(int argc, char **argv) {
  Node *node1 = new Node(1,0.0,0.0);
  Node *node2 = new Node(2,1.0,1.0);
  Node *node3 = new Node(3,2.0,2.0);
  Constraint *constr1 = new Constraint(1, 1, 1, 1, 0);
  Constraint *constr2 = new Constraint(2, 3, 0, 1, 0);
  Domain theDomain;
  theDomain.AddNode(node1);
  theDomain.AddNode(node2);
  theDomain.AddNode(node3);
  theDomain.AddConstraint(constr1);
  theDomain.AddConstraint(constr2);

  theDomain.Print(std::cout);

  Node *theNode = theDomain.getNode(2);
  if (theNode != 0)
    theNode->Print(std::cout);

}
