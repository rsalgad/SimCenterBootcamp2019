#include <iostream>
#include "Domain.h"
#include "Node.h"
#include "Constraint.h"

Domain::Domain() {
  theNodes.empty();
  theConstraints.empty();
}

Domain::~Domain() {
  theNodes.empty();
  theConstraints.empty();
}

Node *
Domain::getNode(int tag){
  Node *res = NULL;

  // create iterator & iterate over all elements
  std::map<int, Node *>::iterator it = theNodes.find(tag);

  if (it != theNodes.end()) {
      Node *theNode = it->second;
      return theNode;
  }
  return res;
}

Constraint *
Domain::getConstraint(int tag){
  Constraint *res = NULL;

  // create iterator & iterate over all elements
  std::map<int, Constraint *>::iterator it = theConstraints.find(tag);

  if (it != theConstraints.end()) {
      Constraint *theConstraint = it->second;
      return theConstraint;
  }
  return res;
}

void 
Domain::Print(std::ostream &s){
  // create iterator & iterate over all elements
  std::map<int, Node *>::iterator it = theNodes.begin();

  while (it != theNodes.end()) {
      Node *theNode = it->second;
      theNode->Print(s);
      it++;
    }

  std::map<int, Constraint *>::iterator it2 = theConstraints.begin();

  while (it2 != theConstraints.end()) {
      Constraint *theConstraint = it2->second;
      theConstraint->Print(s);
      it2++;
    }

}
//function.insert(std::map<int, int>::value_type(0, 42));
int
Domain::AddNode(Node *theNode) {
  if (theNodes.insert (std::map<int, Node *>::value_type(theNode->GetTag(), theNode)).second == false)
    return false;
  else
    return true;
}

int
Domain::AddConstraint(Constraint *theConstraint) {
  if (theConstraints.insert (std::map<int, Constraint *>::value_type(theConstraint->GetTag(), theConstraint)).second == false)
    return false;
  else
    return true;
}
