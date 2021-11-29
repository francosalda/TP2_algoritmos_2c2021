#include "Carta.h"


/*
Post:Crea una carta sin ninguna habilidad/efecto asociado.
*/
Carta::Carta()
{
	this->habilidadCarta= CARTA_SIN_EFECTO;
}
/*
Post:Crea una carta con la habilidad 'efecto'
*/
Carta::Carta(habilidadCarta_t efecto)
{
	this->habilidadCarta=efecto;
}
/*
Post: devuelve un efecto aleatorio de los disponibles
*/
 habilidadCarta_t Carta:: generarEfectoAleatorio()
{
	// se debe generar un ramdom .....
	return CARTA_SIN_EFECTO;
}
/*
Pre: la carta existe
Post:asigna a una carta la habilidad 'efecto'
*/
void Carta::setHabilidad(habilidadCarta_t efecto)
{
	this->habilidadCarta=efecto;
}
/*
Pre: la carta existe
Post:devuelve el efecto asociado a la carta
*/
habilidadCarta_t Carta::getHabilidad()
{
	return this->habilidadCarta;
}
Carta::~Carta()
{

}


