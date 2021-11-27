#include "Carta.h"
Carta::Carta()
{
	this->habilidad=0;
}
Carta::Carta(int numero)
{
	this->habilidad=numero;
}
void Carta::setHabilidad(int numero)
{
	this->habilidad=numero;
}
int Carta::getHabilidad()
{
	return this->habilidad;
}
Carta::~Carta()
{

}


