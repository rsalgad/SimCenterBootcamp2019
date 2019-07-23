#include "node.h"
#include "domain1.h"

int main(int argc, char **argv) {
  Domain theDomain;
  theDomain.theNodes=0;
  theDomain.numNodes=0;
  theDomain.maxNumNodes=0;
  domainAddNode(&theDomain, 1, 0.0, 0.0);
  domainAddNode(&theDomain, 2, 1.0, 0.0);
  domainAddNode(&theDomain, 3, 2.0, 0.0);
  domainAddNode(&theDomain, 4, 1.0, 1.0);
  
  int constraint1[3] = {1, 1, 0};
  int constraint2[3] = {1, 1, 0};
  int constraint3[3] = {1, 1, 1};
  domainAddConstraint(&theDomain, 1, constraint1); 
  domainAddConstraint(&theDomain, 2, constraint2); 
  domainAddConstraint(&theDomain, 3, constraint3); 

  double load1[3] = {10, -5, 0};
  domainAddLoad(&theDomain, 4, load1); 
  domainPrint(&theDomain);

  // get and print singular node
  //printf("\nsingular node:\n");
  //Node *theNode = domainGetNode(&theDomain, 2);
  //nodePrint(theNode);
}
