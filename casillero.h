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
    .matrizDeVecinos: posee la matriz de vecinos del casillero
*/

class Casillero{

private:

    Ficha *contenidoCasillero;
    size_t turnosRestantesDesbloqueo;
    bool casilleroAnulado;
    Lista<Lista<Lista<Casillero *>*>*> * matrizDeVecinos;
    void vaciarCasillero();
   
  

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
    Ficha* obtenerContenidoCasillero();
    void desbloquearCasillero();

    //matriz de vecinos
    void crearMatrizVecinosVacia(int cantFil,int cantCol,int cantProf);
    void destruirMatrizVecinos(int cantFil,int cantCol,int cantProf);
    Lista<Lista<Lista<Casillero *>*>*> * obtenerMatrizDeVecinos();
    void setCasillaMatrizVecinos(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad, Casillero* punteroCasillero);
    Casillero * getAdayacente(int i , int j, int k);
    bool estaCasillaAdayacenteVacia(int i , int j, int k);
    bool existeCasillaAdyacente(int i , int j, int k);
    size_t getLongitud(int i,int j,int k,Casillero * casilleroOrigen);

};

#endif 
