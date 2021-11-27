#include "Mazo.h"
Mazo::Mazo()
{
	this->mazo=new Pila<Carta>();
}
void Mazo::agregarCarta(Carta dato)
{
	this->mazo->push(dato);
}
int Mazo::sacarCarta(Carta & dato)
{
	return this->mazo->pop(dato);
}
Mazo::~Mazo()
{
	this->mazo->~Pila();
}
