#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "ficha.h"
#include "Mazo.h"

/*TDA JUGADOR :)*/

using namespace std;
class Jugador
{
private:
	string  nombreJugador;
	Ficha * fichaJugador;
	Mazo  * mazoJugador; // son las cartas que tiene en mano el jugador
public:
	Jugador(string nombre,char simboloFicha);
	~Jugador();

	string obtenerNombreJugador();
	void setNombreJugador(string nombre);
	char obtenerFichaJugador();
	void setFichaJugador(Ficha * nuevaFicha);

/*
	void asignarMazoJugador();
	void asignarCartaJugador();

*/


};



#endif