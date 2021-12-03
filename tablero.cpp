#include <iostream>
#include "tablero.h"
#include "casillero.h"


Tablero::Tablero(int cantFilas, int cantColumnas, int cantEnProfundidad) {
    if ((cantFilas < 2) || (cantColumnas<2) || (cantEnProfundidad<2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }
    this->cantFilas=cantFilas;
    this->cantColumnas=cantColumnas;
    this->cantEnProfundidad=cantEnProfundidad; 
    Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>;

    for(int i=0;  i<this->cantFilas; i++)
    {
        Lista<Lista <Casillero *>*> *columnas = new Lista<Lista <Casillero *>*>;
        for (int j=0; j<this->cantColumnas; j++) 
        {
            Lista<Casillero *> * profundidad = new Lista<Casillero *>;

            for (int k = 0; k < this->cantEnProfundidad; k++)
            {
                Casillero* nuevoCasillero = new Casillero();
                profundidad->agregar(nuevoCasillero);
            }
            columnas->agregar(profundidad);
        }
        filas->agregar(columnas);
    }
    this->casilleros = filas;
}





Tablero::~Tablero() {

     Lista<Lista <Lista<Casillero *>*>*> * filas = this->casilleros;

     while(filas->avanzarCursor())
     {
        Lista<Lista <Casillero *>*> *columnas = this->casilleros->obtenerCursor();
        while(columnas->avanzarCursor())
        {

            Lista<Casillero *> * profundidad = columnas->obtenerCursor();
            while(profundidad->avanzarCursor())
            {
                delete profundidad->obtenerCursor();

            }delete profundidad;

        }delete columnas;


     }delete filas;
   
     
}
    


Casillero *Tablero::getCasilla(int filaIntroducida, int columnaIntroducida, int profundidadIntroducida) 
{ //me devuleve el dato en la posicion x y
    //validar
    if((filaIntroducida<0) || (columnaIntroducida<0) || (profundidadIntroducida<0) || (filaIntroducida>this->cantFilas) || (columnaIntroducida>this->cantColumnas) ||(profundidadIntroducida>this->cantEnProfundidad))
    {
        string CoordInvalidas = "coordenadas de casilleros iunvalidas";
        throw CoordInvalidas;
    }
    return this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad);


}



void Tablero::setCasilla(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha) {
    this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->setFicha(ficha);
}

void Tablero::verificar(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha) {
    std::cout<<this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->obtenerFicha()<<std::endl;
    if(this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->obtenerFicha() == ficha){
        std::cout<<this->casilleros->obtener(cantFilas)->obtener(cantColumnas)->obtener(cantEnProfundidad)->obtenerFicha()<<std::endl;
        std::cout<<"funciono xd"<<std::endl;
    }
}

/*void Tablero::crearMatrizVecinos(int cantFilas, int cantColumnas, int cantEnProfundidad) {

   Casillero *casilla;

    for (int i = 0; i < this->cantFilas; i++) {
        for (int j = 0; j < this->cantColumnas; j++) {
            for (int k = 0; k < this->cantEnProfundidad; k++) {

                casilla = this->getCasilla(i,j,k);
                Casillero**** matrizVecinal = new Casillero***();

                for (int l = 0; l <3; l++) {
                    //Casillero *** columna = new Casillero**();
                    matrizVecinal[l] = new Casillero** ();
                    for (int m = 0; m < 3; m++) {
                        matrizVecinal[l][m] = new Casillero*();
                        for (int n = 0; n < 3; n++) {
                            matrizVecinal[l][m][n] = new Casillero();
                        }
                    }
                }
                casilla->asignarMatrizVecinos(matrizVecinal);
            }
        }
    }
}*/

Lista<Lista<Lista<Casillero*>*>*>* Tablero::obtenerMatrizTablero()
{
    return this->casilleros;
}   

bool Tablero::existeLaCasilla(int m, int n, int l) {
    if(
    this->cantFilas < m ||
    this->cantColumnas < n ||
    this->cantEnProfundidad < l){
        return false;
    }
    return true;
}

//ASIGNO LOS VECINOS
// edit matriz vecinos // Algoritmo que Asigna la matriz de vecinos //falta implementar existeLaCasilla
/*
    for (int i = 0; i < this->cantColumnas; i++) { //el primer for me agarra la primer columna
        for (int j = 0; j < this->cantFilas; j++) { //el segundo for me define la fila
            for (int k = 0; k < this->cantEnProfundidad; k++) { //el 3er for la profundidad
                Casillero* casillero = this->getCasilla(i,j,k);
                for (int l = -1; l < 2; l++) {
                    for (int m = -1; m < 2; m++) {
                        for (int n = -1; n < 2; n++) {
                            if (existeLaCasilla(i + l, j + m, k + n)) {   //Implementar existeLaCasilla (>0, <ancho, <alto, <profundo)
                            //Con este if resolvemos la parte imaginaria(osea los que estarian en NULL porq estan por fuera del tablero)
                            Casillero *casilleroVecino = this->getCasilla(i + l, j + m, k +n); //SI NO EXISTE LA CASILLA, getCasilla tendria q devolver excepcoion
                            casilleroVecino->asignarVecino(l, m, n, casilleroVecino);
                            }
                        }
                    }
                }
            }
        }
    }
}

//edit matriz vecinos
//edit matriz vecinos

//edit matriz vecinos //TERMINAR!!
//Algoritmo que verifica el ganador
bool Tablero::hayTateti(Casillero *casilleroOrigen, direccion) { //casilleroOrigen es donde estoy parado(revisar que seria)
   casilleroOrigen->getVecinos();
   int longitudesAdyacentes[3][3][3];

   for (int i = 0; i <3 ; i++) {
       for (int j = 0; j <3 ; j++) {
           for (int k = 0; k <3 ; k++) {
               longitudesAdyacentes[i][j][k] = casilleroOrigen->getLongitud(i,j,k); //Devuelve la longitud de los casiilrros usados x la misma ficha
           }
       }
   }
   for (int i = 0; i <3 ; i++) {
       for (int j = 0; j <3 ; j++) {
           for (int k = 0; k <3 ; k++) {
               longitudesAdyacentes[i][j][k];

           }
       }
   }
}
*/
//edit matriz vecinos