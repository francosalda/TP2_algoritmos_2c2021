#ifndef MAZO_H
#define MAZO_H
#include "Lista.h" 
#include "Carta.h"

/* [TDA MAZO]:
	.mazoCartas : es el conjunto de todas las cartas que posee el mazo

*/
class Mazo 
{
private:
	Lista<Carta*> mazoCartas; 

public:

	Mazo(int cantidadCartas);
	Mazo();
	virtual ~Mazo();
	void agregarCarta(Carta * nuevaCarta);
	Carta *obtenerCartaSuperior();
	void barajarMazo();
	void destruirMazo();
	void imprimirMazo();
	void eliminarCarta(unsigned int pos);
	Lista<Carta*>&getMazoCartas();
	unsigned int getCantidadCartas();

};
#endif /* MAZO_H_ */
