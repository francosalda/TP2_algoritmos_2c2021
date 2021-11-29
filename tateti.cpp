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
	this ->colaDeTurnos = NULL;
	this->cantidadJugadasRealizadas= 0;
	this->mazoPrincipal = NULL;

}


/*POST: realiza la configuracion inicial de los parametros 
del Tateti mediante la interaccion con el usuario*/
void Tateti:: iniciarJuego()
{
	cout<<"--------------->Bienvenido a TATETI   Multiplayer<-----------------------\n";
	this->crearJugadores();
	this->imprimirJugadores();
	this->asignarTurnosJugadores();
	this->CrearMazoPrincipal();
	//this-> cargar_tablero()
}

/*Imprime la lista de jugadores actuales con sus fichas*/

void Tateti::imprimirJugadores()
{
	cout<<"Los jugadores se esta partida son:\n";
	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		cout<<"["<<(this->listaDeJugadores.obtenerCursor())->obtenerIdJugador()<<"]";
		cout<<(this->listaDeJugadores.obtenerCursor())->obtenerNombreJugador();
		cout<<" con la ficha : "<<this->listaDeJugadores.obtenerCursor()->obtenerSimboloFichaJugador()<<"\n";
	}


}

/*POST: inicializa la lista de jugadores del tateti
con sus nombres y fichas*/

void Tateti::  crearJugadores()
{
	cout<<"Ingrese la cantidad de jugadores: \n";
	size_t inputCantidadJugadores = 2;
	cin>>(inputCantidadJugadores); //falta verificar rango
	if(inputCantidadJugadores < 2 || inputCantidadJugadores > MAX_CANTIDAD_JUGADORES)
	{
		return;
	}

	string nombreJugador ;
	Jugador *nuevoJugador = NULL;
	char simboloFicha = ' ';

	for(size_t i = 0; i < inputCantidadJugadores;i++)
	{

		cout<<"Ingrese el nombre del jugador:\n";
		cin>>nombreJugador;
		cout<<"Ingrese la ficha del jugador (1 caracter):\n";
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

/*POST: carga la cola de turnos del tateti
con los jugadores presentes*/
void  Tateti::asignarTurnosJugadores()
{

// carga en la cola de turnos la lista de jugadores.



}
/*Post: crea el mazo principal del juego*/
void  Tateti:: CrearMazoPrincipal()
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
	while(!hayGanador())
	{
		int x;
		cout<<"Ingrese donde desea colocar la ficha: \n";
		cin >>x;

		// colocar fichas en tablero
		//dar una carta a cada jugador luego de su turno
		// si ya se colocaron todas las fichas moverlas
		//usar las cartas
		//etc...

	}


	
}



/*POST: libera toda la memoria dinamic asociada al tateti*/
Tateti::~Tateti()
{
	destruirJugadores();
	destruiMazoPrincipal();
}