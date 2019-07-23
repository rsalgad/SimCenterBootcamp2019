#ifndef _DIAMOND
#define _DIAMOND

#include "Shape.h"

class Diamond: public Shape {
 public:
  Diamond(double w, double h);
  ~Diamond();
  double GetArea(void);
  void PrintArea(std::ostream &s);  

 protected:

 private:
  double width, height;
  static int numDia;
};

#endif // _DIAMOND

  
