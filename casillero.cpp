#include "ficha.h"
#include "casillero.h"
#include <iostream>


/*
Post: Inicializa un casillero listo para colocarle una ficha
*/
Casillero::Casillero(){
    this->contenidoCasillero = NULL;
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroVacio = true;
    this->casilleroAnulado = false;

    //edit matriz vecinos
   // this->vecinos = new Casillero*[3[3][3];
    //edit matriz vecinos

}

Casillero::~Casillero(){
}

/*
Post: : devuelve true si el casillero esta vacio
*/
bool Casillero::estaCasilleroVacio(){
    return this->casilleroVacio;
}
/* Post: devuelve true si el casillero esta anulado para colocar fichas*/
bool Casillero::estaCasilleroAnulado(){
    return this->casilleroAnulado;
}
/*
PRE: el casillero esta vacio al momento de anularse
Post:  anula un casillero , entonces no podran colocarse fichas en el
*/
void Casillero::anularCasillero(){
    this->casilleroAnulado = true;
}
/*
PRE: el casillero existe
Post: vacia un casillero para que pueda colocarse otra ficha
*/
void Casillero::vaciarCasillero(){
    this->contenidoCasillero = NULL;
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroVacio = true;
    this->casilleroAnulado = false;
}
/*
PRE: el casillero existe
Post: copia el contenido de un casillero a otro casillero
*/
void Casillero::copiarCasillero(Casillero* dest){
    dest->contenidoCasillero = this->contenidoCasillero;
    dest->casilleroVacio = false;
}

/*
Pre: casillero fue creado anteriormete
Post :retorna la cantidad de turnos restantes por los cuales el casillero esta bloqueado
*/
size_t Casillero::getTurnosRestantesDesbloqueo(){
    return this->turnosRestantesDesbloqueo;
}

/*
Pre : casillero creado anteriormete
Post : setea la cantidad de turnos restantes por los cuales el casillero esta bajo efectos de una carta
*/

void Casillero::setTurnosRestantesDesbloqueo(size_t cantidadTurnos){
    this->turnosRestantesDesbloqueo = cantidadTurnos;

}
/*Post : Decrementa en 1 la cantidad de turnos restantes para que pueda usarse el casillero*/

void Casillero::decrementarTurnosRestantesDesbloqueo(){
    (this->turnosRestantesDesbloqueo)--;
}
/*
PRE: el casillero fue creado anteriormente y posee una ficha en el
Post : Bloquea la ficha del casillero
*/
void Casillero::bloquearFichaDelCasillero(){
    //(this->contenidoCasillero)->bloquearFicha();

}
/*
Post : Asigna una ficha al casillero
*/

void Casillero::setFicha(char ficha) {
    this->ficha = ficha;
}

//edit matriz vecinos
/*
 *
void Casillero::asignarVecino(int l, int m, int n, Casillero *casilleroVecino){
    this->vecinos[l+1][m+1][n+1] = casilleroVecino; //donde l m n son alto ancho profundo
}

bool Casillero::tieneVecino(int l, int m, int n) {
    return false;
}

void Casillero::existeLaCasilla() {}


unsigned int Casillero::getLongitud(unsigned int i, unsigned int j, unsigned int k) {
    if(!tieneVecino(i,j,k) || (!estaOcupado(i,j,k))){ // si no tiene vecino devuelve 0, osea si no tiene vecino o si se acabo el tablero
        return 0;
    }
    // tiene vecino?
    Casillero *casilleroVecino = this->getVecino(i,j,k);
    if (this->tienenMismaFicha(casilleroVecino)){ //Implementar tienenMismaFicha()
        return (1 + casilleroVecino->getLongitud(i,j,k)); //Funcion recursiva
    }
    // las fichas son distitntas y la longitud de fichas iguales es 0
    return 0;
}

Casillero *Casillero::getVecino(unsigned int i, unsigned int j, unsigned int k) {
    return this->vecinos[i][j][k];
}
*
*/
//edit matriz vecinos

