#include "jugador.h"

using namespace std;
/*
POST: Crea un jugador con un nombre y una ficha asignada,
sin mazo.
*/
Jugador::Jugador(string nombre,char simboloFicha)
{

	this->nombreJugador = nombre;
	 /// ATENCION PERDIDA DE MEMORIA DE FICHAS , !!!!!!!!!!!!!!!!
	this->fichaJugador =  new Ficha(simboloFicha);
	this-> mazoJugador = NULL;
	this->idJugador = 0;
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

/* POST :Devuelve el caracter que representa la ficha del jugador*/
char Jugador:: obtenerSimboloFichaJugador()
{
	return this->fichaJugador->getSimboloFicha();
}

/*POST: asigna al jugador la nuevaFicha */
void Jugador::setFichaJugador(Ficha * nuevaFicha)
{
	this->fichaJugador = nuevaFicha;
}

/*
PRE: la ficha fue creada anteriormente
POST: libera la memoria de la ficha del jugador*/
void Jugador::destruirFichaJugador()
{
	delete  this->fichaJugador;
}
/*
PRE: el jugador existe
POST: devuelve la ID del jugador*/
size_t Jugador:: obtenerIdJugador()
{
	return this->idJugador;
}
void Jugador::setearIdJugador(size_t id)
{
	this->idJugador = id;
}
