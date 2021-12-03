#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"

template<class T>
class Lista
{
private:
    Nodo<T>* primero;
    unsigned int tamanio;
    Nodo<T>* cursor;

public:
    /*post: Lista vacía*/
    Lista();

/*post: Lista  identica a la Lista pasadapor argumento  */
    Lista(Lista<T> &otraLista);

/*post: indica si la Lista tiene algún elemento  */
    bool estaVacia();

/*post: devuelve la cantidad de elementos que tiene la Lista*/
    unsigned int contarElementos();
    /* post: agrega elemento al final de Lista, posición contarElementos() + 1  */
    void agregar(T elemento);


/*pre : posición pertenece al intervalo: [1, contarElementos() + 1]
    post: agrega el elemento en la posición indicada */
    void agregar(T elemento, unsigned int posicion);



/* post: agrega todos los elementos de otraLista  a partir de la posición contarElementos() + 1  */
    void agregar(Lista<T> &otraLista);



/* pre : posición pertenece al intervalo: [1, contarElementos()]
     post: devuelve el elemento en la posición indicada   */
    T obtener(unsigned int posicion);



    /*  pre :posición pertenece al intervalo: [1, contarElementos()]
          post: cambia elemento de posición indicada por elemento pasado  */
    void asignar(T elemento, unsigned int posicion);



    /* pre : posición pertenece al intervalo: [1, contarElementos()]
         post: remueve de la Lista el elemento en la posición indicada  */
    void remover(unsigned int posicion);
/* post: deja cursor de Lista preparado para hacer nuevo recorrido  */

    void iniciarCursor();


    /*
   El método avanzar cursor permite el movimiento de un nodo al siguiente usando el cursor

   pre : se ha iniciado un recorrido (invocando el método iniciarCursor())
   y desde entonces no se han agregado o  removido elementos de la Lista.
    post: mueve cursor; lo posiciona en siguiente elemento del recorrido
   El valor de retorno indica si el cursor quedó posicionado sobre un  elemento o no (en caso de que la Lista esté vacía o no existan más elementos por recorrer.)
   */
    bool avanzarCursor();
/*  pre : el cursor está posicionado sobre un elemento de la Lista (fue invocado el método     avanzarCursor() y devolvió true)
       post: devuelve el elemento en la posición del cursor. */
    T obtenerCursor();



/* post: libera los recursos asociados a la Lista. */
    ~Lista();



private:

/* pre : posición pertenece al intervalo: [1, contarElementos()]
     post: devuelve el nodo en la posición indicada. */

    Nodo<T>* obtenerNodo (unsigned int posicion);

};

template<class T> Lista<T>::Lista()
{
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}



template<class T> Lista<T>::Lista(Lista<T>&otraLista)
{
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

/* copia los elementos de otraLista */
    this->agregar(otraLista);
}
template<class T>bool Lista<T>::estaVacia()
{
    if(this->tamanio == 0)
    {
        return true;
    }
    return false;
}



template<class T>unsigned int Lista<T>::contarElementos()
{
    return this->tamanio;
}

template<class T>void Lista<T>::agregar(T elemento)
{
    this->agregar(elemento, this->tamanio + 1);
}

template<class T>void Lista<T>::agregar (T elemento, unsigned int  posicion)
{
    if ((posicion> 0) && (posicion<= this->tamanio + 1))
    {
        Nodo<T>* nuevo = new Nodo<T> (elemento);
        if (posicion == 1)
        {
            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;
        }
        else
        {
            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);
        }



        this->tamanio++;

        /* cualquier recorrido actual queda invalidado */

        this->iniciarCursor();
    }
}

template<class T>
void Lista<T>::agregar(Lista<T>&otraLista)
{
    otraLista.iniciarCursor();
    while (otraLista.avanzarCursor())
    {
        this->agregar(otraLista.obtenerCursor());
    }
}


template<class T>
T Lista<T>::obtener(unsigned int posicion)
{
    T elemento;
    if ((posicion> 0) && (posicion<= this->tamanio))
    {
        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }
    return elemento;
}


template<class T>
void Lista<T>::asignar(T elemento, unsigned int posicion)
{
    if ((posicion> 0) && (posicion<= this->tamanio))
    {
        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}

template<class T>
void Lista<T>::remover(unsigned int posicion)
{
    if ((posicion> 0) && (posicion<= this->tamanio))
    {
        Nodo<T>* removido;
        if (posicion == 1)
        {
            removido = this->primero;
            this->primero = removido->obtenerSiguiente();
        }
        else
        {
            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(removido->obtenerSiguiente());
        }
        delete removido;
        this->tamanio--;

        /* cualquier recorrido actual quedará invalidado */
        this->iniciarCursor();
    }
}



template<class T>
void Lista<T>::iniciarCursor()
{
    this->cursor = NULL;
}

template<class T>
bool Lista<T>::avanzarCursor()
{
    if (this->cursor == NULL)
    {
        this->cursor = this->primero;
    }
    else
    {
        this->cursor = this->cursor->obtenerSiguiente();
    }


    return (this->cursor != NULL);
}


template<class T>
T Lista<T>::obtenerCursor()
{
    T elemento;
    if (this->cursor != NULL)
    {
        elemento = this->cursor->obtenerDato();
    }
    return elemento;
}
template<class T>
Lista<T>::~Lista()
{
    while (this->primero != NULL)
    {
        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();
        delete aBorrar;
    }
}

template<class T>
Nodo<T>* Lista<T>::obtenerNodo(unsigned int posicion)
{
    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i <posicion; i++)
    {
        actual = actual->obtenerSiguiente();
    }
    return actual;
}

#endif //LISTA_H
