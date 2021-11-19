#include "ficha.h"
#include <iostream>


/*
pre: el tp esta para ser aprobado
post: de vuelve una ficha vacia

*/
Ficha::Ficha(){
    this->estaBloqueada = false;
    this->simbolo = SIMBOLO_VACIO;

std::cout<<"FICHA VACIA CREADA"<<std::endl;
}
/*
post : devulve una ficha  conteniendo el caracter ingresado por el jugador
*/
Ficha::Ficha(char caracter){
    this->estaBloqueada = false;
    this->simbolo = caracter;

std::cout<<"caracter ingresado en la ficha"<<std::endl;

}
/*
pre: se creo la ficha
post: se elimino la ficha
*/

Ficha::~Ficha(){
std::cout<<"se borro la ficha"<<std::endl;

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

