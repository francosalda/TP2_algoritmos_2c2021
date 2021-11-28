#ifndef CASILLLERO_H
#define CASILLLERO_H
#include "ficha.h"
#include <iostream>

class Casillero{

private:

    Ficha *contenidoCasillero;
    size_t turnosRestantesDesbloqueo;
    bool casilleroVacio;
    bool casilleroAnulado;
    void vaciarCasillero();

    //edit
    char ficha();
    Casillero **** vecinos();
    //

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

    //edit
    void setFicha(char ficha);
    void asignarVecino(int l, int m, int n, Casillero* casilleroVecino);
    Casillero *getVecino(int l, int m, int n);
    bool tieneVecino(int l, int m, int n);
    void existeLaCasilla();
    //

};

#endif 