/*
 * Pila.h
 *
 *  Created on: 26/11/2021
 *      Author: algo2
 */

#ifndef PILA_H_
#define PILA_H_

#include "Nodo.h"

template<class T> class Pila {

private:
	Nodo<T>* tope;
	unsigned int tamanio;

public:

    /**
     * pre:
     * post: inicializa la pila vacia para su uso
     */
	Pila();

    /**
     * pre:
     * post: elimina la pila, no el contenido
     */
	virtual ~Pila();

    /*
     * post: indica si la cola tiene algún elemento.
     */
	bool estaVacia();

    /*
     * pre: el elemento no es vacio
     * post: agrega el elemento a la pila
     */
	void apilar(const T& elemento);

    /*
     * pre :
     * post: devuelve el elemento en el tope de la pila
     */
	T& desapilar();

    /*
	* post: devuelve la cantidad de elementos que tiene la cola.
	*/
    unsigned int contarElementos();
};

template<class T> Pila<T>::Pila() {
    this->tope = NULL;
    this->tamanio = 0;
}

template<class T> Pila<T>::~Pila() {
    while (!this->estaVacia()) {
        this->desapilar();
    }
}

template<class T> bool Pila<T>::estaVacia() {
    return (this->tamanio == 0);
}

template<class T> void Pila<T>::apilar(const T& elemento) {
	Nodo<T>* nuevo = new Nodo<T>(elemento);
	nuevo->cambiarSiguiente(this->tope);
	this->tope = nuevo;
}

template<class T> unsigned int Pila<T>::contarElementos() {
    return this->tamanio;
}
template<class T> T& Pila<T>::desapilar() {
    T elemento;
    if (!this->estaVacia()) {
        elemento = this->tope->obtenerDato();
        Nodo<T>* aBorrar = this->tope;
        this->tope = this->tope->getSiguiente();
        delete aBorrar;
    }
    return elemento;
}

#endif /* PILA_H_ */
