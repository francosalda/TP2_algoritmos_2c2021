
//Despues le pongo las pre y post.


#ifndef PILA_H_
#define PILA_H_
#include "Nodo.h"
template <class T>
class Pila {
private:
	Nodo<T>* p;
public:
	/*
	 * Pre:-
	 * Post: Inicializa la pila vacia para su uso
	 */
	Pila();
	/*
	 * Pre: el elemento no es vacio
	 * Post: agrega el elemento a la pila
	 */
	void push(T dato);
	/*
	 * Pre: que la pila no este vacía
	 * Post: retorna y elimina el último elemento de la pila
	 */
	int pop(T &dato);
	/*
	 * Pre:-
	 * Post: indica si la pila tiene algún elemento
	 */
	bool estaVacia();
	/*
	 * Pre:-
	 * Post: devuelve el contenido del último elemento de la pila
	 */
	T getTope();
	/*
	 * Pre:-
	 * Post: elimina la pila, no el contenido
	 */
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
		return dato;
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
	while(!this->estaVacia())
	{
		this->pop();
	}
}
#endif /* PILA_H_ */
