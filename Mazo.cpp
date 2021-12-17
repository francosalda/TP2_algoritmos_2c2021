#include "Mazo.h"
#include <cstdlib> 
#include <ctime> 
#include <iostream>
/*
 * POST:devuelve la cantidad de cartas que tiene un mazo
 */
unsigned int Mazo::getCantidadCartas()
{
	return this->mazoCartas.contarElementos();
}
/*
POST: Crea una mazo con una cantidad de cartas sin efecto
*/

Mazo::Mazo(int cantidadCartas)
{
	//Carta * nuevaCarta = NULL;
	for(int i = 0 ; i <cantidadCartas ; i++ )
	{
		//nuevaCarta = new Carta(CARTA_SIN_EFECTO);
		this->mazoCartas.agregar(new Carta());
	}
}
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
	Carta * cartaSuperior = this->mazoCartas.obtener(this->mazoCartas.contarElementos());
	this->mazoCartas.remover(this->mazoCartas.contarElementos()); 

	return cartaSuperior;
}/*POST: Libera la memoria dinamica del contenido de un mazo*/
void Mazo::destruirMazo()
{
	//this->mazoCartas.~Lista();
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
	srand(static_cast<unsigned int>(std::time(NULL))); 
	this->mazoCartas.iniciarCursor();
	while(this->mazoCartas.avanzarCursor())
	{
		this->mazoCartas.obtenerCursor()->setHabilidad(this->mazoCartas.obtenerCursor()->generarEfectoAleatorio());
	}

}

void Mazo::imprimirMazo(){
	int i=1;
	this->mazoCartas.iniciarCursor();
	while(this->mazoCartas.avanzarCursor())
	{
		std::cout<<"carta numero "<<i++<<": ";
		this->mazoCartas.obtenerCursor()->imprimirHabilidadCarta();
	}
}
Lista<Carta*>& Mazo::getMazoCartas()
{
	return this->mazoCartas;
}
void Mazo::eliminarCarta(unsigned int pos)
{
	this->mazoCartas.remover(pos);
}


