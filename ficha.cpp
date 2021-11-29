#include "ficha.h"
#include <iostream>


/*
Post: Inicializa una ficha totalemente vacia
*/
Ficha::Ficha(){
    this->estaBloqueada = false;
    this->simbolo = SIMBOLO_VACIO;
}
/*
Post : devuelve una ficha  conteniendo el caracter ingresado por el jugador
*/
Ficha::Ficha(char caracter){
    this->estaBloqueada = false;
    this->simbolo = caracter;

}
/*
pre: la ficha fue creada anteriormente
post: se elimina la ficha
*/

Ficha::~Ficha(){

}
/*
pre: la ficha existe
post: devuelve el caracter contenido en la ficha
*/

char Ficha::getSimboloFicha(){
    return this->simbolo;
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

