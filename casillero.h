#ifndef CASILLLERO_H
#define CASILLLERO_H
#include "ficha.h"
#include <iostream>
using namespace std;

class Casillero{

private:

    Ficha *contenidoCasillero;
    size_t turnosRestantesDesbloqueo;
    bool casilleroVacio;
    bool casilleroAnulado;
    void vaciarCasillero();


    //edit matriz vecinos
    char ficha;
    Casillero **** vecinos;
    //edit matriz vecinos


public:
    Casillero();
    virtual ~Casillero();
    bool estaCasilleroVacio();
    bool estaCasilleroAnulado();
    void anularCasillero();
    void copiarCasillero(Casillero* dest);
    size_t getTurnosRestantesDesbloqueo(); 
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    void decrementarTurnosRestantesDesbloqueo();
    void bloquearFichaDelCasillero();
    void setFicha(char ficha);

    //edit matriz vecinos
    /*
    void asignarVecino(int l, int m, int n, Casillero* casilleroVecino);
    bool tieneVecino(int l, int m, int n);
    void existeLaCasilla();
    unsigned int getLongitud(unsigned int i, unsigned int j, unsigned int k);
    Casillero *getVecino(unsigned int i,unsigned int j,unsigned int k);
     */
    //edit matriz vecinos


};

#endif 