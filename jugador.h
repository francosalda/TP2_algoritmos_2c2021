#ifndef JUGADOR_H
#define JUGADOR_H
#include <string>
#include "ficha.h"
#include "Mazo.h"

/* [TDA JUGADOR] :
	.nombreJugador : Es el nombre del jugador
	.fichaJugador : Es la ficha del jugador
	.mazoJugador : Es el mazo propio del jugador o 'mano' del jugador
	.idJugador: Es un identificatorio del jugador
 */

using namespace std;
class Jugador
{
private:
	string  nombreJugador;
	Ficha * fichaJugador;
	Mazo  * mazoJugador; // son las cartas que tiene en mano el jugador
	size_t idJugador;
public:
	Jugador(string nombre,char simboloFicha);
	~Jugador();

	void setNombreJugador(string nombre);
	string obtenerNombreJugador();
	char obtenerSimboloFichaJugador();
	void setFichaJugador(Ficha * nuevaFicha);
	void destruirFichaJugador();
	size_t obtenerIdJugador();
	void setearIdJugador(size_t id);
	

/*
	void asignarMazoJugador();
	void asignarCartaJugador();

*/


};



#endif