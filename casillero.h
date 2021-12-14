#ifndef CASILLLERO_H
#define CASILLLERO_H
#include "ficha.h"
#include "Lista.h"
#include <iostream>
using namespace std;


/*[TDA CASILLERO]
    .contenidoCasillero : Es la ficha almacenada por el casillero
    .turnosRestantesDesbloqueo: es la cantidad de turnos antes de poder desbloquearse
    .casilleroAnulado: indica si  en ese casillero puede colocarse una ficha
*/

class Casillero{

private:

    Ficha *contenidoCasillero;
    size_t turnosRestantesDesbloqueo;
    bool casilleroAnulado;

    void vaciarCasillero();
    //edit matriz vecinos
   // Casillero**** matrizDeVecinos;
    Lista<Lista<Lista<Casillero *>*>*> * matrizDeVecinos;


public:
    Casillero(char simboloFicha);
    virtual ~Casillero();

    bool estaCasilleroVacio();
    bool estaCasilleroAnulado();
    void copiarCasillero(Casillero* dest);
    
    void setTurnosRestantesDesbloqueo(size_t cantidadTurnos);
    size_t getTurnosRestantesDesbloqueo(); 
    void decrementarTurnosRestantesDesbloqueo();

    void bloquearFichaDelCasillero();
    void setSimboloFichaDelCasillero(char simboloFicha);
    char obtenerSimboloFichaDelCasillero();
    void anularCasillero();
  

    void crearMatrizVecinosVacia(int cantFil,int cantCol,int cantProf);
    void destruirMatrizVecinos(int cantFil,int cantCol,int cantProf);
    //void asignarMatrizVecinos(Casillero**** matrizVec);

    //void asignarVecino(int l, int m, int n, Casillero* casilleroVecino);



    //edit matriz vecinos
    /*
    bool tieneVecino(int l, int m, int n);
    void existeLaCasilla();

    unsigned int getLongitud(unsigned int i, unsigned int j, unsigned int k);
    Casillero *getVecino(unsigned int i,unsigned int j,unsigned int k);
     */
    

};

#endif 