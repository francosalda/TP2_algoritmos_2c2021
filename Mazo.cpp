#include "Mazo.h"
#include "Carta.h"
Mazo::Mazo() {
	this->p=NULL;
}
int Mazo::getTope()
{
	if(this->p)
	{
		return this->p->habilidad;
	}
	else return 0;
}
bool Mazo::estaVacia()
{
	return !this->p;
}
void Mazo::push(int numero)
{
	Carta* aux=new Carta;
	aux->setSig(this->p);
	this->p=aux;
}
void Mazo::pop(int &x)
{
	if(this->p)
	{
		Carta* aux=this->p;
		x=this->p->getHabilidad();
		this->p=aux->getSig();
		delete aux;
	}
}
Mazo::~Mazo(){

}
