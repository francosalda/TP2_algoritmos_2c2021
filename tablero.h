#ifndef TABLERO_H
#define TABLERO_H
#include "Lista.h"
#include "casillero.h"

using namespace std;


class Tablero {
private:
    Lista<Lista<Lista<Casillero*>*>*>* casilleros; // casilleros es una lista de lista de punteros a casillero(puntero casillero pq es un tda)
    int cantFilas;
    int cantColumnas;
    int cantEnProfundidad;

public:
    //PRE: Los argumentos deben ser >0
    //POST: Crea un tablero de dimensiones x.y.z = cantcasillas
    Tablero(int cantFilas, int cantColumnas, int cantEnProfundidad);
    Tablero();
    //PRE:
    //POST:
    virtual ~Tablero();

    //PRE: Recibe los valores de filas columnas y profundidad elegidos
    //POST: Devuelve la ficha que se encuentra en la casilla elegida
    Casillero *getCasilla(int filaIntroducida, int columnaIntroducida, int profundidadIntroducida);

    //PRE: Recibe los valores de filas columnas y profundidad elegidos
    //POST: Coloca una nueva ficha en la casilla selecionada si es que no esta ocupada (Validar)
    
    void setCasilla(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha); //char seria la ficha, x ahora lo pongo asi y en casillero pongo char ficha,
    void verificar(int cantFilas, int cantColumnas, int cantEnProfundidad, char ficha);

   
    //PRE:
    //POST:
   // void crearMatrizVecinos(int cantFilas, int cantColumnas, int cantEnProfundidad);

    //PRE:
    //POST:
    bool existeLaCasilla(int m, int n, int l);
  Lista<Lista<Lista<Casillero*>*>*>* obtenerMatrizTablero();

  void destruirTablero();


    //edit matriz vecinos
    /*
    bool hayTateti(Casillero* casilleroOrigen, direccion);
     */
    //edit matriz vecinos


    //PRE:
    //POST:
};


#endif //TP2_TABLERO_H