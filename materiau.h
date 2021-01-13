#ifndef MATERIAU_H
#define MATERIAU_H

#include <string>


namespace ensiie {
  class Materiau{
    private:
      double lambda_;
      double rho_;
      double c_;
      //string materiau;
    
    public:
      Materiau(double lambda, double rho, double c);
      Materiau(const Materiau& m);
      double get_lambda();
      double get_rho();
      double get_c();
  };
}

#endif