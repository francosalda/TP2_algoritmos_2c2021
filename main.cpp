#include "ficha.h"
#include "casillero.h"
#include <iostream>
#include "jugador.h"
#include "tateti.h"


int main()
{
    Tateti * juegoActual = new Tateti();
    juegoActual->iniciarJuego();
    juegoActual->activarGraficarBmp(); // juegoActual->desactivarGraficarBmp();
    juegoActual->jugarJuego();

    delete juegoActual;
    return 0;
}
