#ifndef  TATETI_H
#define TATETI_H
#include "tablero.h"
#include "jugador.h"
class Tateti
{
	private:
		Tablero *tableroDeJuego;
		Lista <Jugador *> listaDeJugadores; 
		Lista <Jugador *> *colaDeTurnos; //debe ser en realidad una cola de turnos de jugadores
		// Tablero  tableroAnterior;
	public:
		Tateti();
		~Tateti();
		//guardarEstadoTablero(tablero * tableroDestino)
		void asignarJugadores();
		void iniciarJuego();
		void imprimirJugadores();
		void destruirJugadores();
		/*asignarTablero();
		asignarFichasJugador();
		imprimirTablero();
		imprimirCartasJugador();
*/

};



#endif