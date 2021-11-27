#ifndef PILA_H_
#define PILA_H_
#include "Nodo.h"
template <class T>
class Pila {
private:
	Nodo<T>* p;
public:
	Pila();
	void push(T dato);
	int pop(T &dato);
	bool estaVacia();
	T getTope();
	virtual ~Pila();
};
template <class T>Pila<T>::Pila()
{
	this->p=NULL;
}
template <class T>void Pila<T>::push(T dato)
{
	Nodo<T>* aux=new Nodo<T>(dato);
	aux->cambiarSiguiente(this->p);
	this->p=aux;
}
template <class T>int Pila<T>::pop(T &dato)
{
	if(this->p)
	{
		Nodo<T>* aux=this->p;
		this->p=aux->obtenerSiguiente();
		dato=aux->obtenerDato();
		delete aux;
		return 1;
	}
	return -1;
}
template <class T>bool Pila<T>::estaVacia()
{
	return !this->p;
}
template <class T>T Pila<T>::getTope()
{
	return this->p->obtenerDato();
}
template <class T> Pila<T>::~Pila()
{
	//me falta definir el destructor de la pila
}
#endif /* PILA_H_ */
