#ifndef  TATETI_H
#define TATETI_H
#include "Lista.h"
#include "tablero.h"
#include "jugador.h"
#include "Cola.h"

#define MAX_CANTIDAD_JUGADORES 20
#define CANTIDAD_CARTAS_MAZO_PRINCIPAL 50 
#define CANTIDAD_CARTAS_MAZO_JUGADORES 5


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
		Tablero *jugadaAnterior;
		Lista <Jugador *>  listaDeJugadores; 
		Cola <Jugador *> colaDeTurnos; //debe ser en realidad una cola de turnos de jugadores
		size_t cantidadJugadasRealizadas;
		Mazo * mazoPrincipal;
		Jugador * turnoActual;
		int ***matrizResultadosChequeoGanador;
		int largoLineaGanarTateti;
		bool hayTateti;
		bool graficarBitmap;
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
		bool solicitarMoverFicha(int &filas, int &columnas,int & profundidad);
		bool esFichaValida(int &filas, int &columnas,int & profundidad);
		void validarCasillero(Casillero* &casilleroOrigen,int &filas,int &columnas,int &profundidad);
		void solicitarIngresoDeLargoLineaTateti();

		void crearMatrizResultadosGanador(int cantFilas,int cantColumnas,int cantProfundidad);
		void destruirMatrizResultadosGanador(int cantFilas,int cantColumnas);
		bool chequearMatrizGanadorTateti();
		void activarGraficarBmp();
		void desactivarGraficarBmp();



		void usarCarta(unsigned int numero);
		void anularCasillero();
		void eliminarCartaJugador();
		void robarCartaJugador();
		void bloquearFicha();
//metodos relacionados al tablero del tateti
		void crearTablero();
		bool estaCasilleroLibre(size_t fila,size_t columna,size_t profundidad);
		bool estaEnRangoValido(int fila,int columna,int profundidad);
		int obtenerIdJugadorPropietarioFicha(char ficha);
	 	Tablero *obtenerTableroDeJuego();




		bool estaFichaBloqueada(Casillero * casilleroOrigen);
	 	void imprimirCordenadasFichaJugador(char ficha);
	 	void decrementarTurnosCasillerosYFichas();
	 	void desbloquearCasilleroYficha();
		bool estaCasilleroAnulado(size_t fila,size_t columna,size_t nuevaProfundidad);


};

#endif
