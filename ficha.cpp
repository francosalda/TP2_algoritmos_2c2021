#include "ficha.h"
/*
Post: Inicializa una ficha totalemente vacia
*/
Ficha::Ficha(){
    this->estaBloqueada = false;
    this->simbolo = SIMBOLO_FICHA_VACIA;
    this->turnosRestantesDesbloqueo=0;
}
/*
Post : inicializa una ficha  con el simbolo   caracter 
*/
Ficha::Ficha(char caracter){
    this->estaBloqueada = false;
    this->simbolo = caracter;
    this->turnosRestantesDesbloqueo=0;
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
/*
 * POST:asigna a "turnosRestantesDesbloqueo"la cantidad de turnos que le falta antes de que se desbloquee la ficha
 */
void Ficha::setTurnosRestantesDesbloqueo(unsigned int cantidadTurnos){
    this->turnosRestantesDesbloqueo = cantidadTurnos;

}
/*
 * POST:Resta en uno la cantidad de turnos que le falta a la ficha antes de desbloquearse
 */
void Ficha::decrementarTurnosRestantesDesbloqueo(){
    (this->turnosRestantesDesbloqueo)--;
}
/*
 * POST:devuelve la cantidad de turnos que le falta a la ficha antes de desbloquearse
 */
unsigned int Ficha::getTurnosRestantesDesbloqueo()
{
	return this->turnosRestantesDesbloqueo;
}
