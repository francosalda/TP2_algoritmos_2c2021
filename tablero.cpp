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
                /*se eliminaron los parametros de  casillero ya que esyos no tenian uso*/
                fila->agregar(casillero);
            }
            columna->agregar(fila);
        }
        this->casilleros->agregar(columna);
    }
}


Tablero::~Tablero() {

    this->casilleros->iniciarCursor();
    while(this->casilleros->estaVacia())
    {
        this->casilleros->obtenerCursor()->iniciarCursor();
        while(this->casilleros->obtenerCursor()->estaVacia())
        {
        (this->casilleros->obtenerCursor())->obtenerCursor()->iniciarCursor();
        (this->casilleros->obtenerCursor())->avanzarCursor();    

            while((this->casilleros->obtenerCursor())->obtenerCursor()->estaVacia())
            {
                /*borrar memoria de ficha cuando  se pida la misma*/
                delete (this->casilleros->obtenerCursor())->obtenerCursor()->obtenerCursor();
                (this->casilleros->obtenerCursor())->obtenerCursor()->avanzarCursor();
            }
            delete this->casilleros->obtenerCursor()->obtenerCursor();
            this->casilleros->avanzarCursor();
        }
        delete this->casilleros->obtenerCursor();
    }
    delete this->casilleros;
//destruir casilleros
}

Casillero *Tablero::getCasilla(int filaIntroducida, int columnaIntroducida, int profundidadIntroducida) 
{ //me devuleve el dato en la posicion x y
    //validar
    if((filaIntroducida<0) || (columnaIntroducida<0) || (profundidadIntroducida<0) || (filaIntroducida>this->cantFilas) || (columnaIntroducida>this->cantColumnas) ||(profundidadIntroducida>this->cantEnProfundidad))
    {
        string CoordInvalidas = "coordenadas de casilleros iunvalidas";
        throw CoordInvalidas;
    }
    return this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad);


}



void Tablero::setCasilla(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha) {
    this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->setFicha(ficha);
}
