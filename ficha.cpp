#include "ficha.h"
/*
Post: Inicializa una ficha totalemente vacia
*/
Ficha::Ficha(){
    this->estaBloqueada = false;
    this->simbolo = SIMBOLO_FICHA_VACIA;
}
/*
Post : devuelve una ficha  conteniendo el caracter ingresado por el jugador
*/
Ficha::Ficha(char caracter){
    this->estaBloqueada = false;
    this->simbolo = caracter;

}

Ficha::~Ficha()
{
}
/*
pre: la ficha existe
post: devuelve el caracter que representa  la ficha
*/

char Ficha::getSimboloFicha(){
    return this->simbolo;
}
/*
pre: la ficha existe
post: setea el caracter que representa  la ficha
*/
void Ficha::setSimboloFicha(char nuevoSimbolo)
{

    this->simbolo = nuevoSimbolo;
}

/*
PRE: la ficha existe
post: se devuleve si la ficha esa bloqueada o no
*/
bool Ficha::estaBloqueadaFicha(){
    return this->estaBloqueada;
}

/*
PRE: la ficha existe
post: bloque la ficha ingresada
*/
void Ficha::bloquearFicha(){
    this->estaBloqueada = true;
}

/*
PRE: la ficha existe
post: bloque la ficha ingresada
*/
void Ficha::desbloquearFicha(){
    this->estaBloqueada = false;
}

