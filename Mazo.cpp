#include "Mazo.h"

/*
POST: inicializa un mazo de cartas vacio*/
Mazo::Mazo()
{
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
}
/*POST: libera la memoria de todo lo que conforma
el mazo*/
Mazo::~Mazo()
{
	this->mazoCartas.iniciarCursor();
	while(mazoCartas.avanzarCursor())
	{
	delete this->mazoCartas.obtenerCursor();
	}

}
/*
Post: devuelve un mazo al cual
se le asignaron cartas con efectos aleatorios
*/
void Mazo::barajarMazo()
{
	Carta * nuevaCarta = NULL;
	for(int i = 0 ; i <MAX_CANTIDAD_CARTAS_MAZO ; i++ )
	{
		nuevaCarta = new Carta(nuevaCarta->generarEfectoAleatorio());
		this->mazoCartas.agregar(nuevaCarta);
	}

}