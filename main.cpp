#include "ficha.h"
#include "casillero.h"
#include <iostream>
#include "jugador.h"


int main()
{

    
    Jugador * jugador_1 = new Jugador("Mijail",'X');
    Jugador * jugador_0 = new Jugador("Franco",'0');


    cout<<"El jugador 1 es "<<jugador_1->obtenerNombreJugador()<<" con la ficha :"<<jugador_1->obtenerFichaJugador()<<"\n";
    
    cout<<"El jugador 0 es "<<jugador_0->obtenerNombreJugador()<<" con la ficha :"<<jugador_0->obtenerFichaJugador()<<"\n";

    delete jugador_1;delete jugador_0;



    return 0;
}