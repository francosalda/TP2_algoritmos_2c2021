#ifndef  TATETI_H
#define TATETI_H
#include "Lista.h"
#include "tablero.h"
#include "jugador.h"
#include "Cola.h"

#define MAX_CANTIDAD_JUGADORES 20
#define CANTIDAD_CARTAS_MAZO_PRINCIPAL 50 
#define CANTIDAD_CARTAS_MAZO_JUGADORES 3


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
		int ***matrizResultadosChequeoGanador;
		// Tablero  tableroAnterior;
	public:
		Tateti();
		~Tateti();
//metodos relacionados a los jugadores del tateti
		void crearJugadores();
		void destruirJugadores();
		void imprimirJugadores();
		void inicializarTurnosJugadores();
		bool FichaYaOcupadaPorOtroJugador(char simboloFichaElegido);
		bool perteneceFichaAlJugador(char simboloFichaElegido);
//metodos relacionados a la partida de tateti
		void iniciarJuego();
		void jugarJuego();
		bool hayGanador(int filaIngresada,int columnaIngresada,int profundidadIngresada);
		void crearMazoPrincipal();
		void destruiMazoPrincipal();
		void crearMazoJugadores();
		void destruirMazoJugadores();
		void avanzarTurno();
		void solicitarIngresoDeCordenadas(int &filas, int &columnas,int & profundidad);
		size_t obtenerMinimaCantidadJugadasTateti();
		size_t obtenerCantidadJugadoresActuales();
		void repartirCartaAlJugador();
		bool solicitarIngresoNuevaFicha(int &filas, int &columnas,int & profundidad);
		bool solicitarMoverFicha(int &filas, int &columnas,int & profundidad);
		void crearMatrizResultadosGanador(int cantFilas,int cantColumnas,int cantProfundidad);
		void destruirMatrizResultadosGanador(int cantFilas,int cantColumnas);
		
//metodos relacionados al tablero del tateti
		void crearTablero();
		bool estaCasilleroLibre(size_t fila,size_t columna,size_t profundidad);
		bool estaEnRangoValido(int fila,int columna,int profundidad);
		int obtenerIdJugadorPropietarioFicha(char ficha);
	 	Tablero *obtenerTableroDeJuego();
		bool hayGanador();
};

#endif