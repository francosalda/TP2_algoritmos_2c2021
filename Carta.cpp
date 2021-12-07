#include "Carta.h"

#include <cstdlib> 
#include <ctime> 
#include <iostream>


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
     
    int efectoRandom = (rand()%6)+1;
	return (habilidadCarta_t)efectoRandom;
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

void Carta::imprimirHabilidadCarta(){
	switch (this->habilidadCarta)
	{
	case 0:
		std::cout<<"CARTA_SIN_EFECTO = 0"<<std::endl;
		break;
	case 1:
		std::cout<<"CARTA_PERDER_TURNO = 1"<<std::endl;
		break;
	
	case 2:
		std::cout<<"CARTA_BLOQUEAR_FICHA = 2"<<std::endl;
		break;
	
	case 3:
		std::cout<<"CARTA_ANULAR_CASILLERO = 3"<<std::endl;
		break;
	
	case 4:
		std::cout<<"CARTA_VOLVER_JUGADA = 4"<<std::endl;
		break;
	
	case 5:
		std::cout<<"CARTA_ELIMINAR_CARTA = 5"<<std::endl;
		break;
	
	case 6:
		std::cout<<"CARTA_ROBAR_CARTAS = 6"<<std::endl;
		break;
	default:
		break;
	}
}