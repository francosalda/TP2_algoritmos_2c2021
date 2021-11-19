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
    this->estaBloqueada = true;
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

char Ficha::getSimboloFicha(Ficha *inputFicha){
    return this->simbolo;
}

