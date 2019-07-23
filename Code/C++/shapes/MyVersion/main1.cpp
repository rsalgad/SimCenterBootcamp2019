#include "Rectangle.h"
#include "Circle.h"
#include "Diamond.h"

int main(int argc, char **argv) {
  Diamond s1(4.0, 2.0);

  s1.PrintAreaToFile("DiamondArea.txt");

  return 0;
}


