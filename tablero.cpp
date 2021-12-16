#include <iostream>
#include "tablero.h"
#include "casillero.h"
using namespace std;


Tablero::Tablero(size_t cantFilas, size_t cantColumnas, size_t cantEnProfundidad) {
    if ((cantFilas < 2) || (cantColumnas<2) || (cantEnProfundidad<2))
    {
        string DimensionInvalida = "dimensiones de tablero incorrectas";
        throw DimensionInvalida;
    }
    this->cantFilas=cantFilas;
    this->cantColumnas=cantColumnas;
    this->cantEnProfundidad=cantEnProfundidad; 
    Lista<Lista <Lista<Casillero *>*>*> * filas  = new Lista<Lista <Lista<Casillero *>*>*>;

    for(size_t i=0;  i<this->cantFilas; i++)
    {
        Lista<Lista <Casillero *>*> *columnas = new Lista<Lista <Casillero *>*>;
        for (size_t j=0; j<this->cantColumnas; j++) 
        {
            Lista<Casillero *> * profundidad = new Lista<Casillero *>;

            for (size_t k = 0; k < this->cantEnProfundidad; k++)
            {
                Casillero* nuevoCasillero = new Casillero(SIMBOLO_FICHA_VACIA);
              
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
    
/*
Pre: existe el tablero y el casillero solicitado
Post: devuelve el casillero ubicado en la posicion [fila][columna][profundidad]
*/

Casillero * Tablero::getCasillero(size_t fila, size_t columna, size_t profundidad) 
{ 
    if((fila <= 0) || (columna<= 0) || (profundidad <=0) || (fila>this->cantFilas) || (columna>this->cantColumnas) ||(profundidad>this->cantEnProfundidad))
    {
        string CoordInvalidas = "coordenadas de casilleros invalidas";
        throw CoordInvalidas;
    }
    return this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad);
}


/*
Pre: existe el casillero establecido y esta en el rango del tablero
Post:Establece la ficha del casillero ubicado en la posicion [fila][columna][profundidad] 
con el simbolo 'simboloFicha'*/
void Tablero::setCasilla(size_t fila, size_t columna, size_t profundidad, char simboloFicha) {
    this->casilleros->obtener(fila)->obtener(columna)->obtener(profundidad)->setSimboloFichaDelCasillero(simboloFicha);

}

Lista<Lista<Lista<Casillero*>*>*>* Tablero::obtenerMatrizTablero()
{
    return this->casilleros;
}   

bool Tablero::existeLaCasilla(size_t m, size_t n, size_t l) {
    if(this->cantFilas < m ||this->cantColumnas < n ||this->cantEnProfundidad < l ||
        m< 1 || n<1 || l<1){
        return false;
    }
    return true;
}

/*
Pre: existe el tablero
Post:Devuelve la cantidad de filas que posee el tablero
*/
size_t Tablero::getCantFilasTablero()
{
    return this->cantFilas;
}
/*
Pre: existe el tablero
Post:Devuelve la cantidad de columnas que posee el tablero
*/
size_t Tablero::getCantColumnasTablero()
{
    return this->cantColumnas;
}
/*
Pre: existe el tablero
Post:Devuelve la profundidad que posee el tablero
*/
size_t Tablero::getCantProfundidadTablero()
{
    return this->cantEnProfundidad;

}

/*Pre: existe la matriz de adyacentes , y existen los casilleros del tablero
Post:  recorre el tablero al rededor del casillero central ubicado en [fil,col,prof]
y completa la matriz de adyacentes de 3x3x3 de dicho casillero*/

void Tablero::llenarMatrizAdyacentes(size_t fil, size_t col,size_t prof)
{
    for(size_t i = fil-1,i1 =1; i <= (fil+1);i++,i1++)
    {
        for(size_t j = col-1,j1 = 1; j<= (col+1);j++,j1++)
        {

            for(size_t k = prof-1,k1=1; k<= (prof+1);k++,k1++)
            {
                if(this->existeLaCasilla(i, j, k))
                {
                    if(i == fil && j ==col && k==prof)
                    {
                        Casillero * casilleroCentral = this->getCasillero(i,j,k);
                        casilleroCentral->setCasillaMatrizVecinos(2,2,2,casilleroCentral);
                        continue;
                    } 
                    this->getCasillero(fil,col,prof)->setCasillaMatrizVecinos(i1,j1,k1,this->getCasillero(i,j,k)); 
                }
                else
                {
                    this->getCasillero(fil,col,prof)->setCasillaMatrizVecinos(i1,j1,k1,NULL);
                }

             
            }
        }
    }

    //imprimir matriz de vecino para el casillero actual fil,col,prof
    /*cout<<"Imprimiendo matriz de vecinos del casillero del tablero:["<<fil<<","<<col<<","<<prof<<"]"<<endl;
    for(size_t i= 1 ; i <=3; i++)
    {
        for(size_t j= 1 ;j <=3; j++)
        {
            for(size_t k = 1 ; k <=3;k++)
            {
                
                Casillero * casilleroActual = this->getCasillero(fil,col,prof)->obtenerMatrizDeVecinos()->obtener(i)->obtener(j)->obtener(k);
                //VERY IMPORTAN COMPROBATION
                if(casilleroActual)
                {
                        cout<<"["<<i<<","<<j<<","<<k<<"]";
                         cout<<casilleroActual->obtenerSimboloFichaDelCasillero()<<endl;
                }
               
            }
        }

    }*/
    
    





}
   /* for(size_t i = fil -1 , i1 = 0; i < fil + 1; i++, i1++){

        for(size_t j = col -1, j1 = 0; j < col + 1; j++, j1++){

            for(size_t k = pro-1, k1 = 0; k < pro + 1; k++, k1++)
            {
                if (i == fil && j== col && k == pro)
                {
                    
                    this->getCasillero(i,j,k)->setCasillaMatrizVecinos(i1,j1,k1,this->getCasillero(i,j,k));
                    continue;
                }
                
                if (this->existeLaCasilla(i, j, k))
                {
                    this->getCasillero(i,j,k)->setCasillaMatrizVecinos(i1,j1,k1,NULL);
                    //this->getCasillero(i+1,j+1,k+1)->setCasillaMatrizVecinos(i1,j1,k1,this->getCasillero(i+1,j+1,k+1));
                }
                else
                {
                //this->getCasillero(i+1,j+1,k+1)->setCasillaMatrizVecinos(i1,j1,k1,NULL);
                
            }
                

            }
                
                

            }
        }
    }

    } 
*/


























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