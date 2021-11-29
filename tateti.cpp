#include "tateti.h"
#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;

/*POS : */

Tateti::Tateti()
{
	this->tableroDeJuego = NULL;
	this ->colaDeTurnos = NULL;





}





void Tateti:: iniciarJuego()
{
	cout<<"--------------->Bienvenido a TATETI   Multiplayer<-----------------------\n";
	asignarJugadores();

	


}


void Tateti::imprimirJugadores()
{
	cout<<"Imprimiendo lista de jugadores \n";
	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		cout<<(this->listaDeJugadores.obtenerCursor())->obtenerNombreJugador()<<"con el caracter : "<<this->listaDeJugadores.obtenerCursor()->obtenerFichaJugador()<<"\n";
	}


}

/*POST: inicializa la lista de jugadores del tateti
con sus nombres y fichas*/


void Tateti::  asignarJugadores()
{
	cout<<"Ingrese la cantidad de jugadores: \n";
	size_t inputCantidadJugadores = 2;
	cin>>(inputCantidadJugadores); //falta verificar rango
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
		//this->listaDeJugadoreslist
		this->listaDeJugadores.agregar(nuevoJugador);

	}


}

Tateti::~Tateti()
{
	destruirJugadores();
}


/*libera la memoria de los jugadores, faltaria liberar la memoria del contenido de ellos (fichas,etc)*/
void Tateti::destruirJugadores()
{

	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		delete (this->listaDeJugadores.obtenerCursor());
	}


}