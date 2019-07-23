#include <Shape.h>
#include <iostream>
#include <fstream>
#include <string>

Shape::Shape() {

}

Shape::~Shape() {
  std::cout << "Shape Destructor\n";
}

void
Shape::PrintArea(std::ostream &s) {
  s << "UNKOWN area: " << this->GetArea() << "\n";
}

void Shape::PrintAreaToFile(std::string fileName){
  std::ofstream myFile;
  if (myFile.is_open()){
  myFile.close();
  } else {
  myFile.open(fileName);
  myFile << "Unknown area: " << this->GetArea() << "\n";
  myFile.close();
  }
}
  

