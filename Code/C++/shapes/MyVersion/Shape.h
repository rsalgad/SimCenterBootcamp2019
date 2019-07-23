#ifndef _SHAPE
#define _SHAPE

#include <fstream>
#include <iostream>
#include <string>

class Shape {
 public:
  Shape();
  virtual ~Shape();
  virtual double GetArea(void) =0;
  virtual void PrintArea(std::ostream &s);
  virtual void PrintAreaToFile(std::string fileName);
};

#endif // _SHAPE

  
