#include <iostream>
#include "tablero.h"
#include "casillero.h"


Tablero::Tablero(int x, int y, int z) {
    if ((x < 2) || (y<2) || (z<2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }
    this->x=x;
    this->y=y;
    this->z=z;
    this-> casilleros = new Lista<Lista<Casillero*>*>(); //esto crea el puntero a primero de la lista, con todo en nuuull
    for(int i=0; i<x; i++){
        Lista<Casillero*>* columna = new Lista<Casillero*>();
        for(int j=0; j<y; j++){
            Casillero *casillero = new Casillero();
            columna->agregar(casillero);
        }
        this->casilleros->agregar(columna);
    }
}


Tablero::~Tablero() {
//destruir casilleros
}

Casillero *Tablero::getCasilla(int filaIntroducida, int columnaIntroducida, int profundidadIntroducida) { //me devuleve el dato en la posicion x y
    //validar
    if((filaIntroducida<0) || (columnaIntroducida<0) || (profundidadIntroducida<0) || (filaIntroducida>this->x)) || (columnaIntroducida>this->y) ||(profundidadIntroducida>this->z){
        string CoordInvalidas = "coordenadas de casilleros iunvalidas";
        throw Coordinvalidas;
    }
    return this->casilleros->getElemento(profundidadIntroducida)->getElemento(filaIntroducida)->getElemento(columnaIntroducida);
}

void Tablero::setCasilla(int x, int y, int z, char ficha) {
    this->casilleros->obtener(x)->obtener(y)->obtener(z)->setFicha(ficha);
}
