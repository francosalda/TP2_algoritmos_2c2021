#include "casillero.h"
#include <iostream>


/*
Post: Inicializa un casillero con  una ficha nueva con el simbolo especificado
*/
Casillero::Casillero(char simboloFicha){
    this->contenidoCasillero = new Ficha(simboloFicha);
    this->turnosRestantesDesbloqueo = 0;
    this->casilleroAnulado = false;
    this->crearMatrizVecinosVacia(3,3,3);
}
/*
Pre:Existe el casillero
Post: elimina la memoria dinamica del casillero
y de la ficha que contiene
*/
Casillero::~Casillero()
{

    this->destruirMatrizVecinos(3,3,3);
    if(this->contenidoCasillero)
    {
        delete  this->contenidoCasillero;
    }

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
void Casillero::setCasillaMatrizVecinos(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad, Casillero* punteroCasillero) {
    this->matrizDeVecinos->obtener(cantFilas)->obtener(cantColumnas)->asignar(punteroCasillero, cantEnProfundidad)  ;


    ///this->matrizDeVecinos->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad) =  punteroCasillero ;

}
Lista<Lista<Lista<Casillero *>*>*> * Casillero::obtenerMatrizDeVecinos(){
    return this->matrizDeVecinos;
}

Casillero *  Casillero::getAdayacente(int i , int j, int k)
{
    return this->matrizDeVecinos->obtener(i)->obtener(j)->obtener(k);
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
/*Pre: existe la matriz de vecinos
Post: devuelve true si  la casilla 
en la matriz de vecinos en la posicion i,j,k tiene la ficha vacia
*/
bool Casillero::estaCasillaAdayacenteVacia(int i , int j, int k)
{
    if(getAdayacente(i,j,k)->estaCasilleroVacio())
    {
     

        return true;
    }
    return false;
}

/*Pre: existe la matriz de vecinos
Post: devuelve true si existe la casilla 
en la matriz de vecinos en la posicion i,j,k
*/
bool Casillero::existeCasillaAdyacente(int i , int j, int k)
{
    if(i<1 || j<1||k<1 || i >3 ||j>3 || k>3  || getAdayacente(i,j,k) == NULL)
    {
        return false;
    }
    return true;
}

/*
Pre :existe la matriz de vecinos
Pos:devuelve la cantidad de fichas iguales que hay en una determinada direcion
de las matrices de vecinos (RECURSIVAMENTE)*/
size_t Casillero:: getLongitud(int i,int j,int k,Casillero * casilleroOrigen)
{
 

    if(!casilleroOrigen->existeCasillaAdyacente(i,j,k)  || casilleroOrigen->estaCasillaAdayacenteVacia(i,j,k))
    {
        return 0;
    }


    
    Casillero * casilleroAdyacente = casilleroOrigen->getAdayacente(i,j,k);
   

    if(casilleroAdyacente->obtenerSimboloFichaDelCasillero() == casilleroOrigen->obtenerSimboloFichaDelCasillero())
    {

        return 1+casilleroAdyacente->getLongitud(i,j,k,casilleroAdyacente);
    }


    return 0; 
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
/*
Pre : casillero creado anteriormetePost : Decrementa en 1 la cantidad de turnos restantes para que pueda usarse el casillero*/

void Casillero::decrementarTurnosRestantesDesbloqueo(){
    (this->turnosRestantesDesbloqueo)--;
}
/*
PRE: el casillero fue creado anteriormente y posee una ficha en el
Post : Bloquea la ficha del casillero
*/
void Casillero::bloquearFichaDelCasillero(){
    this->contenidoCasillero->bloquearFicha();
}
/*Pre : casillero creado anteriormete
 * POST:asigna una ficha en el contenido del casillero
 */

void Casillero::setSimboloFichaDelCasillero(char simboloFicha) {
    this->contenidoCasillero->setSimboloFicha(simboloFicha);
}
/*Pre : casillero creado anteriormete
 * POST:obtiene la ficha del casillero
 */

char Casillero::obtenerSimboloFichaDelCasillero() {
    return this->contenidoCasillero->getSimboloFicha();
}
/*Pre : casillero creado anteriormete
 * POST:devuelve el contenido del casillero
 */
/*
Pre : casillero creado anteriormete
Post: devuelve el contenido del casillero*/
Ficha* Casillero::obtenerContenidoCasillero()
{
	return this->contenidoCasillero;
}
/*Pre : casillero creado anteriormete
 * POST:Desbloquea el casillero cambiando el estado de casilleroAnulado a false
 */
void Casillero::desbloquearCasillero()
{
	this->casilleroAnulado=false;
}


