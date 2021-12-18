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

	string obtenerNombreJugador();
	char obtenerSimboloFichaJugador();
	void setNombreJugador(string nombre);
	void setFichaJugador(Ficha * nuevaFicha);
	void setMazoJugador(Mazo * nuevoMazo);
	void setearIdJugador(size_t id);
	size_t obtenerIdJugador();
	Mazo * getMazoJugador();
	void destruirFichaJugador();

};

#endif
