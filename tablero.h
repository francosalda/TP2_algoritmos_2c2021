#ifndef TABLERO_H
#define TABLERO_H
#include "Lista.h"
#include "casillero.h"

using namespace std;

/*
    .casilleros: es la lista de listas de lista de punteros a casillero
    .cantFilas : es la cantidad de filas que tiene el tablero
    .cantColumnas : es la cantidad de columnas que tiene el tablero
    .cantEnProfundidad : es la cantidad de profundo que tiene el tablero
*/

class Tablero {
private:
    Lista<Lista<Lista<Casillero*>*>*>* casilleros; //  
    size_t cantFilas;
    size_t cantColumnas;
    size_t cantEnProfundidad;

public:
    Tablero(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad);
    Tablero();
    virtual ~Tablero();
    Casillero *getCasillero(size_t filaIntroducida, size_t columnaIntroducida, size_t profundidadIntroducida);
    void setCasilla(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad, char simboloFicha); 
    size_t getCantFilasTablero();
    size_t getCantColumnasTablero();
    size_t getCantProfundidadTablero();
    void llenarMatrizAdyacentes(size_t fil, size_t col,size_t pro);
    bool existeLaCasilla(size_t m, size_t n, size_t l);
    Lista<Lista<Lista<Casillero*>*>*>* obtenerMatrizTablero();


};


#endif //TP2_TABLERO_H
