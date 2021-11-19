#include "ficha.h"
#include <iostream>


int main(){
    Ficha* ficha1 = new Ficha('j');
    std::cout<<ficha1->getSimboloFicha(ficha1)<<std::endl;
    delete ficha1;
    return 0;
}