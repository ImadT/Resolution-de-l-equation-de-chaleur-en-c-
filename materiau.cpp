#include "materiau.h"

namespace ensiie{
  Materiau::Materiau(double lambda, double rho, double c):lambda_(lambda), rho_(rho), c_(c){
  }

  Materiau::Materiau(const Materiau& m){
    lambda_= m.lambda_;
    rho_ = m.rho_;
    c_ = m.c_;
  }

  double Materiau::get_lambda(){
    return lambda_;
  }

  double Materiau::get_rho(){
    return rho_;
  }

  double Materiau::get_c(){
    return c_;
  }
}