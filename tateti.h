#ifndef  TATETI_H
#define TATETI_H
#include "Lista.h"
#include "tablero.h"
#include "jugador.h"

#define MAX_CANTIDAD_JUGADORES 20


/* [TDA Tateti]:

.tableroDeJuego:Es el tablero  de juego
.listaDeJugadores :Es la lista que almacena los jugadores actuales
.colaDeTurnos :Es la cola que almacena el orden en el que se 
llevan a cabo los turnos 
.cantidadJugadasRealizadas :Lleva la cuenta de la cantidad
de jugadas que se realizaron en la partida actual
.mazoPrincipal: Es el mazo principal del juego
*/

class Tateti
{
	private:
		Tablero *tableroDeJuego;
		Lista <Jugador *>  listaDeJugadores; 
		Lista <Jugador *> *colaDeTurnos; //debe ser en realidad una cola de turnos de jugadores
		size_t cantidadJugadasRealizadas;
		Mazo * mazoPrincipal;
		// Tablero  tableroAnterior;
	public:
		Tateti();
		~Tateti();
//metodos relacionados a los jugadores
		void crearJugadores();
		void imprimirJugadores();
		void asignarTurnosJugadores();
		void destruirJugadores();
//metodos relacionados a la partida
		void iniciarJuego();
		void jugarJuego();
		bool hayGanador();
		void CrearMazoPrincipal();
		void destruiMazoPrincipal();
//metodos relacionados al tablero
		
		/*asignarTablero();
		asignarFichasJugador();
		imprimirTablero();
		imprimirCartasJugador();
*/

};

#endif