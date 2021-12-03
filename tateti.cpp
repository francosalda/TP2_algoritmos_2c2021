#include "tateti.h"
#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;

/*POS : crea una partida de tateti para posteriormente
ser cargada su configuracion */

Tateti::Tateti()
{
	this->tableroDeJuego = NULL;
	this->cantidadJugadasRealizadas= 0;
	this->mazoPrincipal = NULL;

}

void Tateti:: crearTablero(){
	//this->tableroDeJuego = new Tablero(3, 3, 3);
	this->tableroDeJuego = new Tablero();
}
/*POST: realiza la configuracion inicial de los parametros 
del Tateti mediante la interaccion con el usuario*/
void Tateti:: iniciarJuego()
{
	cout<<"--------------->Bienvenido a TATETI   Multiplayer<-----------------------\n";
	this->crearTablero();
	this->crearJugadores();
	this->imprimirJugadores();
	this->inicializarTurnosJugadores();
	this->crearMazoPrincipal();
	
}

/*Imprime la lista de jugadores actuales con sus fichas*/

void Tateti::imprimirJugadores()
{
	cout<<"-------------------------------------------\n";
	cout<<"Los jugadores de esta partida son:\n";
	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		cout<<"["<<(this->listaDeJugadores.obtenerCursor())->obtenerIdJugador()<<"]";
		cout<<(this->listaDeJugadores.obtenerCursor())->obtenerNombreJugador();
		cout<<" con la ficha : "<<this->listaDeJugadores.obtenerCursor()->obtenerSimboloFichaJugador()<<"\n";
	}

	cout<<"-------------------------------------------\n";
}

/*POST: inicializa la lista de jugadores del tateti
con sus nombres y fichas*/

void Tateti::  crearJugadores()
{
	cout<<"Ingrese la cantidad de jugadores: \n";
	size_t inputCantidadJugadores = 2;
	cin>>(inputCantidadJugadores); //falta verificar rango
	
	string nombreJugador ;
	Jugador *nuevoJugador = NULL;
	char simboloFicha = ' ';

	for(size_t i = 0; i < inputCantidadJugadores;i++)
	{

		cout<<"Ingrese el nombre del jugador "<<i<<":\n";
		cin>>nombreJugador;
		cout<<"Ingrese la ficha del jugador "<<i<<" (1 caracter):\n";
		cin >>simboloFicha; //falta validar fichas
		nuevoJugador = new Jugador(nombreJugador,simboloFicha);
		nuevoJugador->setearIdJugador(i);
		this->listaDeJugadores.agregar(nuevoJugador);

	}


}



/*libera la memoria de los jugadores, faltaria liberar la memoria del contenido de ellos (fichas,etc)*/
void Tateti::destruirJugadores()
{

	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		(this->listaDeJugadores.obtenerCursor())->destruirFichaJugador(); //libera la memoria de la ficha del jugador
		delete (this->listaDeJugadores.obtenerCursor()); //libera la memoria del jugador

	}


}

/*POST: inicia la cola de turnos del tateti
con los jugadores presentes en el orden en el que se ingresaron por interfaz*/
void  Tateti::inicializarTurnosJugadores()
{

	this->listaDeJugadores.iniciarCursor();
	while(listaDeJugadores.avanzarCursor())
	{
		this->colaDeTurnos.acolar(listaDeJugadores.obtenerCursor()); 
	}

	

// carga en la cola de turnos la lista de jugadores.



}
/*Post: crea el mazo principal del juego*/
void  Tateti:: crearMazoPrincipal()
{
	Mazo * nuevoMazo = NULL;
	nuevoMazo = new Mazo(CANTIDAD_CARTAS_MAZO_PRINCIPAL);
	nuevoMazo->barajarMazo();
	this->mazoPrincipal = nuevoMazo;

}

void  Tateti:: destruiMazoPrincipal()
{
	this->mazoPrincipal->destruirMazo();

	delete this->mazoPrincipal;
}



/*POST: devuelve true si algun jugador logro realizar
el tateti*/
bool Tateti::hayGanador()
{
	return false;
}
/*es el bucle principal del juego*/
void Tateti::jugarJuego()
{
	int filaIngresada,columnaIngresada,profundidadIngresada;

	cout<<"[DEBUG]: (SOLO 6 rondas y corta ya que no tenemos chequearganador() aun)\n";

	while( this->cantidadJugadasRealizadas < 6) // el '3' solo para que no haiga un bucle infinito por ahora
	{
		this->cantidadJugadasRealizadas++;
		this->turnoActual = colaDeTurnos.desacolar();


		cout<<"-> [Ronda: "<<this->cantidadJugadasRealizadas <<"] Es el turno del jugador ["<<this->turnoActual->obtenerIdJugador()<<"]: '"<<this->turnoActual->obtenerNombreJugador()<<"'\n";
		cout<<"Ingrese la fila donde desea colocar su ficha : \n";
		cin >> filaIngresada;
		cout<<"Ingrese la Columna donde desea colocar su ficha : \n";
		cin >> columnaIngresada;
		cout<<"Ingrese la profundidad donde desea colocar su ficha : \n";
		cin >> profundidadIngresada;

		if(filaIngresada < 1 || filaIngresada  > 3 ||columnaIngresada <1 || columnaIngresada > 3 ||   profundidadIngresada < 1 ||profundidadIngresada>3)
		{
			cout<<"[Error]: Posicion invalida, intenta con una mayor a 0! PIERDES EL TURNO\n";
			this->avanzarTurno();
			continue;
		}

		// colocar fichas en tablero
		//dar una carta a cada jugador luego de su turno
		// si ya se colocaron todas las fichas moverlas
		//usar las cartas
		//etc...

        
		///this->tableroDeJuego->setCasilla(filaIngresada,columnaIngresada,profundidadIngresada,this->turnoActual->obtenerSimboloFichaJugador());
		//this->tableroDeJuego->verificar(filaIngresada,columnaIngresada,profundidadIngresada,this->turnoActual->obtenerSimboloFichaJugador());
		this->avanzarTurno();


	}


	
}
/*Post: avanza el turno actual al siguiente jugador
en la cola de turnos */
void Tateti:: avanzarTurno()
{
	//pone el jugador actual al final de la cola
	this->colaDeTurnos.acolar(this->turnoActual);
	

}

/*POST: libera toda la memoria dinamic asociada al tateti*/
Tateti::~Tateti()
{
	destruirJugadores();
	destruiMazoPrincipal();
	this->tableroDeJuego->destruirTablero();
	//delete this->tableroDeJuego;
	delete this->tableroDeJuego;
}




