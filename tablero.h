#ifndef TABLERO_H
#define TABLERO_H
#include "Lista.h"
#include "casillero.h"

using namespace std;


class Tablero {
private:
    Lista<Lista<Lista<Casillero*>*>*>* casilleros; // casilleros es una lista de lista de punteros a casillero(puntero casillero pq es un tda)
    int x;
    int y;
    int z;

public:
    //PRE: Los argumentos deben ser >0
    //POST: Crea un tablero de dimensiones x.y.z = cantcasillas
    Tablero(int x, int y, int z);

    //PRE:
    //POST:
    virtual ~Tablero();

    //PRE: Recibe los valores de filas columnas y profundidad elegidos
    //POST: Devuelve la ficha que se encuentra en la casilla elegida
    Casillero *getCasilla(int filaIntroducida, int columnaIntroducida, int profundidadIntroducida);

    //PRE: Recibe los valores de filas columnas y profundidad elegidos
    //POST: Coloca una nueva ficha en la casilla selecionada si es que no esta ocupada (Validar)
    void setCasilla(int x, int y, int z, char ficha); //char seria la ficha, x ahora lo pongo asi y en casillero pongo char ficha,

    //PRE:
    //POST:
    //  void moverFicha(int x1, int y2, int x2, int y2);
    //validar


    // void imprimirTablero(); //TDA TATETI


    // void verificarGanador(); //TDA TATETI

};


#endif //TP2_TABLERO_H