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
// edit matriz vecinos // Algoritmo que Crea la matriz de vecinos // Terminado, falta implementar existeLaCasilla
/*
    for (int i = 0; i < this->cantColumnas; i++) { //el primer for me agarra la primer columna
        for (int j = 0; j < this->cantFilas; j++) { //el segundo for me define la fila
            for (int k = 0; k < this->cantEnProfundidad; k++) { //el 3er for la profundidad
                Casillero *casillero = this->getCasilla(i, j, k);
                for (int l = -1; l < 2; l++) {
                    for (int m = -1; m < 2; m++) {
                        for (int n = -1; n < 2; n++) {
                            if (existeLaCasilla(i + l, j + m, k + n)) {   //Implementar existeLaCasilla (>0, <ancho, <alto, <profundo)
                                //Con este if resolvemos la parte imaginaria(osea los que estarian en NULL porq estan por fuera del tablero)
                                Casillero *casilleroVecino = this->getCasilla(i + l, j + m, k +n); //SI NO EXISTE LA CASILLA, getCasilla tendria q devolver excepcoion
                                casilleroVecino->asignarVecino(l, m, n, casilleroVecino);
                            }
                        }
                    }
                }
            }
        }
    }
    */
//edit matriz vecinos

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
   return this->casilleros->obtener(profundidadIntroducida)->obtener(filaIntroducida)->obtener(columnaIntroducida);
   // return NULL;
}

void Tablero::setCasilla(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha) {
    ((this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->setFicha(ficha)));
}


//edit matriz vecinos //TERMINAR!!
/*
 * //Algoritmo que verifica el ganador
 *
bool Tablero::hayTateti(Casillero *casilleroOrigen, direccion) { //casilleroOrigen es donde estoy parado(revisar que seria)
    casilleroOrigen->getVecinos();
    int longitudesAdyacentes[3][3][3];

    for (int i = 0; i <3 ; i++) {
        for (int j = 0; j <3 ; j++) {
            for (int k = 0; k <3 ; k++) {
                longitudesAdyacentes[i][j][k] = casilleroOrigen->getLongitud(i,j,k); //Devuelve la longitud de los casiilrros usados x la misma ficha
            }
        }
    }
    for (int i = 0; i <3 ; i++) {
        for (int j = 0; j <3 ; j++) {
            for (int k = 0; k <3 ; k++) {
                longitudesAdyacentes[i][j][k];

            }
        }
    }
}
*/
//edit matriz vecinos