#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sculptor.h"
#include "Leitura.h"
/** Aluna: Maihara Estefany
 * Turma Programação Avançada
 *UFRN
**/

using namespace std;

int main()
{
   Sculptor *desenho;
    Leitura dg;
    vector<FiguraGeometrica*> figuras;
  //arquivo de texto com valores
    figuras = dg.parse("sculptor.txt");

    desenho = new Sculptor(dg.getDx(), dg.getDy(), dg.getDz());

    for(size_t i = 0; i < figuras.size(); i++){
        figuras[i] -> draw(*desenho);
    }

    
    desenho -> writeOFF((char*)"desenho.off");

    for(size_t i = 0; i < figuras.size(); i++){
        delete figuras[i];
    }

    delete desenho;
    return 0;

}