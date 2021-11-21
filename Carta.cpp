#include "Carta.h"
Carta::Carta(int numero) {
	this->sig=NULL;
	this->habilidad=numero;
}
int Carta::getHabilidad()
{
	return this->habilidad;
}
Carta* Carta::getSig()
{
	return this->sig;
}
void Carta::setHabilidad(int numero)
{
	this->habilidad=numero;
}
void Carta::setSig(Carta* carta)
{
	this->sig=carta;
}
Carta::~Carta() {

}

