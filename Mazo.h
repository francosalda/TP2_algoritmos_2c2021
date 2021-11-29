#ifndef MAZO_H
#define MAZO_H
#include "Lista.h" 
#include "Carta.h"
#define CANTIDAD_CARTAS_MAZO_PRINCIPAL 50 
/* [TDA MAZO]:
	.mazoCartas : es el conjunto de todas las cartas que posee el mazo

*/

class Mazo 
{
private:
	Lista<Carta*> mazoCartas; 

public:

	Mazo(int cantidadCartas);
	 virtual ~Mazo();

	void agregarCarta(Carta * nuevaCarta);
	Carta *obtenerCartaSuperior();
	void barajarMazo();
	void destruirMazo();
};
#endif /* MAZO_H_ */
