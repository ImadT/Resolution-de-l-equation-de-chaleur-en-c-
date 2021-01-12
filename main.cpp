#include <iostream>
#include "matrix.h"
#include <string>
using namespace ensiie;

int main() {

  std::cout << "Hello World!\n";
  Matrix m(3, 4);
  m(0, 1) = 3;
  m(2, 2) = 5;

  std::string c ;
  char caractere[] = "je suis imad +++";
  c = caractere;


  std::cout << c << std::endl;

  std::cout << m << std::endl;

}