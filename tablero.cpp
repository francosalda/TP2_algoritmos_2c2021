#include <iostream>
#include "tablero.h"
#include "casillero.h"


Tablero::Tablero(int cantFilas, int cantColumnas, int cantEnProfundidad) {
    if ((cantFilas < 2) || (cantColumnas<2) || (cantEnProfundidad<2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }
    this->cantFilas=cantFilas;
    this->cantColumnas=cantColumnas;
    this->cantEnProfundidad=cantEnProfundidad;
    this-> casilleros = new Lista<Lista<Lista<Casillero*>*>*>(); //esto crea el puntero a primero de la lista, con todo en nuuull

    for(int i=0; i<this->cantEnProfundidad; i++) {
        Lista<Lista<Casillero*>*>* columna = new Lista<Lista<Casillero*>*> ();
        for (int j=0; j<this->cantFilas; j++) {
            Lista<Casillero *> *fila = new Lista<Casillero *>();
            for (int k = 0; k < this->cantColumnas; k++)
            {
                Casillero *casillero = new Casillero();
                fila->agregar(casillero);
            }
            columna->agregar(fila);
        }
        this->casilleros->agregar(columna);
    }
//ASIGNO LOS VECINOS
    for (int i = 0; i < getAncho(); i++) { //el primer for me agarra la primer columna
        for (int j = 0; j < getAlto(); j++) { //el segundo for me define la fila
            for (int k = 0; k < getProfundidad(); k++) { //el 3er for la profundidad
                Casillero *casillero = getCasilla(i, j, k);
                for (int l = -1; l < 1; l++) {
                    for (int m = -1; m < 1; m++) {
                        for (int n = -1; n < 1; n++) {
                            if (existeLaCasilla(i + l, j + m, k + n)) { //Implementar existeLaCasilla (>0, <ancho, <alto, <profundo)
                                //Con este if resolvemos la parte imaginaria(osea los que estarian en NULL porq estan por fuera del tablero)
                                Casillero *casilleroVecino = getCasilla(i + l, j + m, k +n); //SI NO EXISTE LA CASILLA, getCasilla tendria q devolver excepcoion
                                casilleroVecino->asignarVecino(l, m, n, casilleroVecino);
                            }
                        }
                    }
                }
            }
        }
    }
}


Tablero::~Tablero() {
//destruir casilleros
}

Casillero *Tablero::getCasilla(int filaIntroducida, int columnaIntroducida, int profundidadIntroducida) { //me devuleve el dato en la posicion x y
    //validar
    if((filaIntroducida<0) || (columnaIntroducida<0) || (profundidadIntroducida<0)){// || (filaIntroducida>this->x)) || (columnaIntroducida>this->y) ||(profundidadIntroducida>this->z){
     //   string CoordInvalidas = "coordenadas de casilleros iunvalidas";
       // throw Coordinvalidas;
    }
   // return this->casilleros->getElemento(profundidadIntroducida)->getElemento(filaIntroducida)->getElemento(columnaIntroducida);
    return NULL;
}

void Tablero::setCasilla(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha) {
    //this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->setFicha(ficha);
}
