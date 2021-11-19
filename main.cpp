#include "ficha.h"
#include "casillero.h"
#include <iostream>



int main(){
    Ficha *vectorFichas = new Ficha[4];
    delete[] vectorFichas;


    Casillero *vectorCasilleros = new Casillero[4];
    delete[] vectorCasilleros;

    return 0;
}