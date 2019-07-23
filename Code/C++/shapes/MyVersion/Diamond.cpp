#include <Diamond.h>

int Diamond::numDia = 0;

Diamond::~Diamond() {
  numDia--;
  std::cout << "Diamond Destructor\n";
}

Diamond::Diamond(double w, double d)
  :Shape(), width(w), height(d)
{
  numDia++;
}

double Diamond::GetArea(void) {
  return width*height / 2;
}

void 
Diamond::PrintArea(std::ostream &s) {
  s << "Diamond: " << width * height / 2 << " numDia: " << numDia << "\n";
}

