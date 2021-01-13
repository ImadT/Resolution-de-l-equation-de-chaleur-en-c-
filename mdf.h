#ifndef MDF_H
#define MDF_H
#include "matrix.h"
#include "materiau.h"

namespace ensiie {
  class MDF{
    private:
      int N_;
      double L_;
      double tmax_;
      double u0_;
      double dt_;
      double dx_;
      double alpha_;
      double f_;
      Materiau mat_;
    
    public:
      Matrix F;
      Matrix T;
      Matrix d;
      Matrix a;
      Matrix b;
      Matrix c;

    public:
      MDF(int N, double L, double tmax, double u0, double f, Materiau mat);
      //~MDF();

      void calcule_du_pas();
      void source_de_chaleur();
      void conditions_initiales();
      void instancier_les_coefficients_a_b_c_alpha();
      void algo_de_thomas();
      void enregistrer_csv(char *nom_du_fichier);

      int get_N();
      double get_L();
      double get_tmax();
      double get_u0();
      double get_dt();
      double get_dx();
      double get_alpha();
      double get_f();





  };
}

#endif