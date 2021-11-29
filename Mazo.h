#ifndef MAZO_H
#define MAZO_H
#include "Lista.h" 
#include "Carta.h"
#define MAX_CANTIDAD_CARTAS_MAZO 50

/* [TDA MAZO]:
	.mazoCartas : es el conjunto de todas las cartas que posee el mazo

*/

class Mazo 
{
private:
	Lista<Carta*> mazoCartas; 

public:
	Mazo();
	 virtual ~Mazo();
	void agregarCarta(Carta * nuevaCarta);
	Carta *obtenerCartaSuperior();
	void barajarMazo();
};
#endif /* MAZO_H_ */
