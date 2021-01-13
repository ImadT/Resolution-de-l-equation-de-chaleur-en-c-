#include <stdio.h>
#include "mdf.h"
#include <iostream>
#include <fstream>

namespace ensiie{
  MDF::MDF(int N, double L, double tmax, double u0, double f, Materiau mat): N_(N), L_(L), tmax_(tmax), u0_(u0), f_(f), mat_(mat), F(N), T(N,N),d(N),a(N), b(N), c(N), alpha_(0.0){

  }
/*
  MDF::~MDF(){
    try{
      F.~Matrix();
      T.~Matrix();
      d.~Matrix();
      a.~Matrix();
      b.~Matrix();
      c.~Matrix();
    }catch( const char *s){
      std::cout << s << std::endl;
    }catch( int i){
      std::cout << i << std::endl;
    }
  }
*/

  void MDF::calcule_du_pas(){
    dt_ = tmax_ / double(N_-1);
    dx_ = L_ / double(N_-1);
  }

  void MDF::source_de_chaleur(){
    for(int i=0; i<N_; i++){
      if((i >= (N_-1)/10.0 ) && (i <= 2*(N_-1)/10.0)){
        F(i)= tmax_ * f_* f_;
      }
      else if((i >= 5*(N_-1)/10.0 ) && (i <= 6*(N_-1)/10.0)){
        F(i)= (3.0/4.0) * tmax_ * f_ * f_;
      }
    }
  }

  void MDF::conditions_initiales(){
    for(int i=0; i< N_; i++){
      // condition initiale à l'instant t = 0
      T(i,0) = u0_;

      // // condition de temperature constante pour x = L qlq soit t
      T(N_-1,i) = u0_;
    }
  }

  void MDF::instancier_les_coefficients_a_b_c_alpha(){
    // calcule du coef alpha 
    alpha_ = (dt_* mat_.get_lambda()) /(dx_ * dx_ * mat_.get_rho() * mat_.get_c());

    //std::cout << "lambda" <<  mat_.get_lambda() << "rho" << mat_.get_rho() << "c" << mat_.get_c() << "alpha" <<  alpha_ << std::endl;
    

    for(int i=0; i< N_; i++){
      if (i == 0){
        b(i) = 2.0 * alpha_;
        c(i) = 1 - 2.0 * alpha_;
      }
      else if (i == N_-1){
        b(i) = 1;
      }
      else{
        b(i) = 1 + 2.0 * alpha_;
        c(i) = - alpha_;
        a(i) = - alpha_;
      }
    }
  }


  void MDF::algo_de_thomas(){

    calcule_du_pas();
    source_de_chaleur();
    conditions_initiales();
    instancier_les_coefficients_a_b_c_alpha();
    
    Matrix c_algo(N_);
    Matrix d_algo(N_);

    for(int i=0; i<N_-1;i ++){
      if(i == 0)
        c_algo(i) = c(i) / b(i);
      else
        c_algo(i) = c(i) / (b(i) - a(i) * c_algo(i-1));
    }

    //std::cout << c_algo << std::endl;

    double coef = dt_ /(mat_.get_rho()*mat_.get_c());
    for (int n=1; n<N_; n++){
      for(int i=0; i<N_; i++){
        if(i==0){
          d(i) = coef * F(1) + T(1,n-1);
          d_algo(i) = d(i) / b(i);
        }
        else if(i == N_-1){
          d(i) = u0_;
          d_algo(i) = (d(i)-a(i)*d_algo(i-1)) / (b(i)-a(i)*c_algo(i-1));
        }
        else {
          d(i) = coef * F(i) + T(i,n-1);
          d_algo(i) = (d(i)-a(i)*d_algo(i-1)) / (b(i)-a(i)*c_algo(i-1));
        }
      }

      for(int i=N_-2; i>=0; i--){
        T(i,n) = d_algo(i) - c_algo(i)*T(i+1,n);
      }
    }
  }

  void MDF::enregistrer_csv(char nom_du_fichier[20]){
    //std::ofstream fdm_out(nom_du_fichier);
    std::ofstream f(nom_du_fichier);
    if (f.is_open())
    {
      for (int i=0;i<N_;i++)
          f<<i<< " "<<(T(i,N_-1)- 273.15)<<std::endl;
    }
  }





  //getters
  int MDF::get_N(){
    return N_;
  }
  double MDF::get_L(){
    return L_;
  }
  double MDF::get_tmax(){
    return tmax_;
  }
  double MDF::get_u0(){
    return u0_;
  }
  double MDF::get_dt(){
    return dt_;
  }
  double MDF::get_dx(){
    return dx_;
  }
  double MDF::get_alpha(){
    return alpha_;
  }
  double MDF::get_f(){
    return f_;
  }  
}