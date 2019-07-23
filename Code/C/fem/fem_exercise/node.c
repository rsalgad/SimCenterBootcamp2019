#include <stdio.h>
#include "node.h"

void nodePrint(Node *theNode){
  printf("Node : %d ", theNode->tag);
  printf("Crds: %f %f ", theNode->coord[0], theNode->coord[1]);
  printf("Disp: %f %f %f \n", theNode->disp[0], theNode->disp[1], theNode->disp[2]);

   for (int i = 0; i < 3; i++){
    if (theNode->constraints[i] == 1){ 
    switch(i)
   {
    case 0:
      printf("Constraint: X-Dir\n");
      break;
    case 1:
      printf("Constraint: Y-Dir\n");
      break;
    case 2:
      printf("Constraint: Z-Rot\n");
      break;
    default:
      break;
    }
   }
  }

  for (int i = 0; i < 3; i++){
    if (theNode->loads[i] != 0){ 
    switch(i)
   {
    case 0:
      printf("Load X-Dir: %f\n", theNode->loads[i]);
      break;
    case 1:
      printf("Load Y-Dir: %f\n", theNode->loads[i]);
      break;
    case 2:
      printf("Load Z-Dir: %f\n", theNode->loads[i]);
      break;
    default:
      break;
    }
   }
  }


}

void nodeSetup(Node *theNode, int tag, double crd1, double crd2) {
  theNode->tag = tag;
  theNode->coord[0] = crd1;
  theNode->coord[1] = crd2;
  theNode->next = NULL;
  theNode->constraints[0] = 0; //all free at initalization
  theNode->constraints[1] = 0;
  theNode->constraints[2] = 0;
}
