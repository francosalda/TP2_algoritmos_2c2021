
#include "casillero.h"
#include <iostream>


/*
Post: Inicializa un casillero listo para colocarle una ficha
*/
Casillero::Casillero(char simboloFicha){
    this->contenidoCasillero = new Ficha(simboloFicha);
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroAnulado = false;
    this->crearMatrizVecinosVacia(3,3,3);
   
    
          
}

/*Post condicion crea una matriz de vecinos
para un casillero implementada con listas  con elementos
puntero a casilleros iniciados en NULL*/
void Casillero::crearMatrizVecinosVacia(int cantFil,int cantCol,int cantProf)
{
   Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>;

    for(int i=0;  i<cantFil; i++)
    {
        Lista<Lista <Casillero *>*> *columnas = new Lista<Lista <Casillero *>*>;
        for (int j=0; j<cantCol; j++) 
        {
            Lista<Casillero *> * profundidad = new Lista<Casillero *>;

            for (int k = 0; k < cantProf; k++)
            {
                Casillero* nuevoCasillero = NULL;
              
                profundidad->agregar(nuevoCasillero);
            }
            columnas->agregar(profundidad);
        }
        filas->agregar(columnas);
    }

    this->matrizDeVecinos = filas;
}



/*
Pre:existe la matriz de vecinos
Post: elimina la memoria dinamica de la matriz vecinal
no elimina la memoria de los elementos de la matriz, solo
de su estructura
*/

void Casillero::destruirMatrizVecinos(int cantFil,int cantCol,int cantProf)
{
    Lista<Lista <Lista<Casillero *>*>*> * filas = this->matrizDeVecinos;

     while(filas->avanzarCursor())
     {
        Lista<Lista <Casillero *>*> *columnas = this->matrizDeVecinos->obtenerCursor();
        while(columnas->avanzarCursor())
        {

            Lista<Casillero *> * profundidad = columnas->obtenerCursor();
            //while(profundidad->avanzarCursor())
            //{
                //delete profundidad->obtenerCursor();

            //}
            delete profundidad;

        }delete columnas;

     }delete filas;
}



Casillero::~Casillero()
{

    this->destruirMatrizVecinos(3,3,3);
    if(this->contenidoCasillero)
    {
        delete  this->contenidoCasillero;    
    }
    
}

/*
Post: : devuelve true si el casillero esta vacio
*/
bool Casillero::estaCasilleroVacio()
{
    if(this->contenidoCasillero->getSimboloFicha() == SIMBOLO_FICHA_VACIA)
    {
        return true;
    }
    return false;
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
asignandole la ficha vacia
*/
void Casillero::vaciarCasillero(){
    this->contenidoCasillero->setSimboloFicha(SIMBOLO_FICHA_VACIA);
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroAnulado = false;

}
/*
PRE: el casillero existe
Post: copia el contenido de un casillero a otro casillero
*/
void Casillero::copiarCasillero(Casillero* dest){
    dest->contenidoCasillero->setSimboloFicha(this->contenidoCasillero->getSimboloFicha());
    this->contenidoCasillero->setSimboloFicha(SIMBOLO_FICHA_VACIA);


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


void Casillero::setSimboloFichaDelCasillero(char simboloFicha) {
    this->contenidoCasillero->setSimboloFicha(simboloFicha);
}


char Casillero::obtenerSimboloFichaDelCasillero() {
    return this->contenidoCasillero->getSimboloFicha();
}





void Casillero::setCasillaMatrizVecinos(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad, Casillero* punteroCasillero) {
    this->matrizDeVecinos->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad) =  punteroCasillero ;

}


Lista<Lista<Lista<Casillero *>*>*> * Casillero::obtenerMatrizDeVecinos(){
    return this->matrizDeVecinos;
}



/*void Casillero::asignarMatrizVecinos(Casillero ****matrizVec) {
    this->matrizDeVecinos = matrizVec;
}

//edit matriz vecinos

void Casillero::asignarVecino(int l, int m, int n, Casillero *casilleroVecino){
    this->matrizDeVecinos[l+1][m+1][n+1] = casilleroVecino; //donde l m n son alto ancho profundo
}
*/
/*
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

