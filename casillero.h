#ifndef CASILLLERO_H
#define CASILLLERO_H
#include "ficha.h"
#include <iostream>
using namespace std;


/*[TDA CASILLERO]
    .contenidoCasillero : Es la ficha almacenada por el casillero
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroVacio: indica si un casillero contiene una ficha
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/

class Casillero{

private:

    Ficha *contenidoCasillero;
    size_t turnosRestantesDesbloqueo;
    bool casilleroVacio;
    bool casilleroAnulado;

    void vaciarCasillero();
    //edit matriz vecinos
    char ficha;
    Casillero**** matrizDeVecinos;
    //edit matriz vecinos


public:
    Casillero();
    virtual ~Casillero();

    bool estaCasilleroVacio();
    bool estaCasilleroAnulado();
    void copiarCasillero(Casillero* dest);
    
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();

    void bloquearFichaDelCasillero();
    void setFicha(char ficha);
    void anularCasillero();
    char obtenerFicha();
    //void asignarMatrizVecinos(Casillero**** matrizVec);

    //void asignarVecino(int l, int m, int n, Casillero* casilleroVecino);



    //edit matriz vecinos
    /*
    bool tieneVecino(int l, int m, int n);
    void existeLaCasilla();

    unsigned int getLongitud(unsigned int i, unsigned int j, unsigned int k);
    Casillero *getVecino(unsigned int i,unsigned int j,unsigned int k);
     */
    //edit matriz vecinos


};

#endif 