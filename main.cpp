#include <iostream>
#include "matrix.h"
#include "materiau.h"
#include "mdf.h"
#include <string>
using namespace ensiie;

int main() {


  Materiau Cuivre(389,8940,380);
  Materiau fer(80.2, 7874,440);
  Materiau verre(1.2, 2530, 840);
  Materiau polystyrene(0.1, 1040, 1200);

  MDF MDF_cuivre(1001, 1.0, 12.0, 286.15, 353.15, Cuivre);
  MDF_cuivre.algo_de_thomas();
  char str_cuivre[20] = "cuivre.txt";
  MDF_cuivre.enregistrer_csv(str_cuivre);

  MDF MDF_fer(1001, 1.0, 12.0, 286.15, 353.15, fer);
  MDF_fer.algo_de_thomas();
  char str_fer[20] = "fer.txt";
  MDF_fer.enregistrer_csv(str_fer);

  MDF MDF_verre(1001, 1.0, 12.0, 286.15, 353.15, verre);
  MDF_verre.algo_de_thomas();
  char str_verre[20] = "verre.txt";
  MDF_verre.enregistrer_csv(str_verre);

  MDF MDF_polystyrene(1001, 1.0, 12.0, 286.15, 353.15, polystyrene);
  MDF_polystyrene.algo_de_thomas();
  char str_polystyrene[20] = "polystyrene.txt";
  MDF_polystyrene.enregistrer_csv(str_polystyrene);




  std::cout << "\n" << "the enddd" << std::endl;

  return 0;

}