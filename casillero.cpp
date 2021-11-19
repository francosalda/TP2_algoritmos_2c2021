#include "ficha.h"
#include "casillero.h"
#include <iostream>


/*
pre: el tp esta para ser aprobado
post: de vuelve una ficha vacia

*/
Casillero::Casillero(){
    this->contenidoCasillero = NULL;
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroVacio = true;
    this->casilleroAnulado = false;


std::cout<<"casillero VACIA CREADA"<<std::endl;
}

Casillero::~Casillero(){
    std::cout<<"se borro el casillero"<<std::endl;
}

bool Casillero::estaCasilleroVacio(){
    return this->casilleroVacio;
}

bool Casillero::estaCasilleroAnulado(){
    return this->casilleroAnulado;
}

void Casillero::anularCasillero(){
    this->casilleroAnulado = true;
}

void Casillero::vaciarCasillero(){
    this->contenidoCasillero = NULL;
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroVacio = true;
    this->casilleroAnulado = false;
}


void Casillero::copiarCasillero(Casillero* dest){
    dest->contenidoCasillero = this->contenidoCasillero;
    dest->casilleroVacio = false;
}

/*

pre: casillero fue creado
post :retorna la cantidad de turnos restantes por los cuales el casillero esta bajo efectos de una carta

*/

size_t Casillero::getTurnosRestantesDesbloqueo(){
    return this->turnosRestantesDesbloqueo;
}


/*

pre : casillero creado
post : setea la cantidad de turnos restantes por los cuales el casillero esta bajo efectos de una carta

*/
void Casillero::setTurnosRestantesDesbloqueo(size_t cantidadTurnos){
    this->turnosRestantesDesbloqueo = cantidadTurnos;

}

void Casillero::decrementarTurnosRestantesDesbloqueo(){
    (this->turnosRestantesDesbloqueo)--;
}


void Casillero::bloquearFichaDelCasillero(){
    //(this->contenidoCasillero)->bloquearFicha();

}