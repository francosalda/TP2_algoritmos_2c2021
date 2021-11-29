#include "Mazo.h"

/*
POST: Crea una mazo con una cantidad de cartas sin efecto
*/

Mazo::Mazo(int cantidadCartas)
{
	Carta * nuevaCarta = NULL;
	for(int i = 0 ; i <cantidadCartas ; i++ )
	{
		nuevaCarta = new Carta(CARTA_SIN_EFECTO);
		this->mazoCartas.agregar(nuevaCarta);
	}
}

/*
PRE: existe la carta nueva y el mazo
POST: agrega al mazo la carta recibida al final del mismo
*/
void Mazo::agregarCarta(Carta * nuevaCarta)
{	
	this->mazoCartas.agregar(nuevaCarta);

}
/*
PRE: el mazo existe y posee almenos 1 carta
POST: devuelve la carta superior del mazo
*/
Carta * Mazo::obtenerCartaSuperior()
{
	// se deuelve la ultima carta agregada al mazo es decir la superior
	return this->mazoCartas.obtener(0);
}/*POST: Libera la memoria dinamica de un mazo*/
void Mazo::destruirMazo()
{
	this->mazoCartas.iniciarCursor();
	while(this->mazoCartas.avanzarCursor())
	{
	delete this->mazoCartas.obtenerCursor();
	}
}


Mazo::~Mazo()
{
	

}
/*
Post: asgina de manera aleatoria
efectos a las cartas de un mazo
*/
void Mazo::barajarMazo()
{
	this->mazoCartas.iniciarCursor();
	while(this->mazoCartas.avanzarCursor())
	{
		this->mazoCartas.obtenerCursor()->setHabilidad(this->mazoCartas.obtenerCursor()->generarEfectoAleatorio());
	}

}