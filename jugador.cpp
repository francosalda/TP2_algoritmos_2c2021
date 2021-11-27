#include "jugador.h"

using namespace std;
/*
POST: Crea un jugador con un nombre y una ficha asignada,
sin mazo.
*/
Jugador::Jugador(string nombre,char simboloFicha)
{

	this->nombreJugador = nombre;
	this->fichaJugador = new Ficha(simboloFicha);
	this-> mazoJugador = NULL;
}


/**/
Jugador::~Jugador()
{

}

/*POST: Devuelve el nombre del jugador*/
string Jugador::obtenerNombreJugador()
{
	return this->nombreJugador;
}

/*POST: Setea el nombre del jugador*/
void Jugador::setNombreJugador(string nombre)
{
	this->nombreJugador = nombre;

}

/* POST :Devuelve la ficha que tiene asignada el jugador*/
char Jugador:: obtenerFichaJugador()
{
	return this->fichaJugador->getSimboloFicha();
}

/*POST: asigna al jugador la nuevaFicha */
void Jugador::setFichaJugador(Ficha * nuevaFicha)
{
	this->fichaJugador = nuevaFicha;
}
