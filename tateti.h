#ifndef  TATETI_H
#define TATETI_H
#include "Lista.h"
#include "tablero.h"
#include "jugador.h"
#include "Cola.h"

#define MAX_CANTIDAD_JUGADORES 20
#define CANTIDAD_CARTAS_MAZO_PRINCIPAL 50 


/* [TDA Tateti]:

.tableroDeJuego:Es el tablero  de juego
.listaDeJugadores :Es la lista que almacena los jugadores actuales
.colaDeTurnos :Es la cola que almacena el orden en el que se 
llevan a cabo los turnos 
.cantidadJugadasRealizadas :Lleva la cuenta de la cantidad
de jugadas que se realizaron en la partida actual
.mazoPrincipal: Es el mazo principal del juego
.turnoActual : indica  de que jugador es el turno actual
*/

class Tateti
{
	private:
		Tablero *tableroDeJuego;
		Lista <Jugador *>  listaDeJugadores; 
		Cola <Jugador *> colaDeTurnos; //debe ser en realidad una cola de turnos de jugadores
		size_t cantidadJugadasRealizadas;
		Mazo * mazoPrincipal;
		Jugador * turnoActual;
		// Tablero  tableroAnterior;
	public:
		Tateti();
		~Tateti();
//metodos relacionados a los jugadores
		void crearJugadores();
		void imprimirJugadores();
		void inicializarTurnosJugadores();
		void destruirJugadores();
//metodos relacionados a la partida
		void iniciarJuego();
		void jugarJuego();
		bool hayGanador();
		void crearMazoPrincipal();
		void destruiMazoPrincipal();
		void avanzarTurno();
//metodos relacionados al tablero
		void crearTablero();
		/*asignarTablero();
		asignarFichasJugador();
		imprimirTablero();
		imprimirCartasJugador();
*/

};

#endif