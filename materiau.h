#ifndef MATERIAU_H
#define MATERIAU_H

#include <string>


namespace ensiie {
  class MATERIAU{
    private:
      double lambda_;
      double rho_;
      double c_;
      //string materiau;
    
    public:
      MATERIAU(double lambda, double rho, double c);
      double get_lambda();
      double get_rho();
      double get_c();
  };
}

#endif