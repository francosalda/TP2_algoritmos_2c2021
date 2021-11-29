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

    //edit matriz vecinos
   // this->vecinos = new Casillero*[3[3][3];
    //edit matriz vecinos


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

