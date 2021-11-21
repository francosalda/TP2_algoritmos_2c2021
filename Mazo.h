#ifndef MAZO_H_
#define MAZO_H_
class Mazo {
private:
	Carta * p;
public:
	/*
	 * Pre:-
	 * post:crea un mazo
	 */
	Mazo();
	/*
	 * Pre:-
	 * Post:Inserta una carta en el tope del mazo
	 */
	void push(int numero);
	/*
	 * Pre:-
	 * Post:Elimina una carta en el tope del mazo y guarda la habilidad de la carta.
	 */
	void pop(int & x);
	/*
	 * Pre:-
	 * Post:devuelve false si el mazo tiene elementos o true si esta vacio.
	 */
	bool estaVacia();
	/*
	 * Pre:-
	 * Post:Devuelve el valor del ultimo elemento del mazo o 0 si no hay tope
	 */
	int getTope();
	/*
	 * Pre:-
	 * Post:Destruye el mazo
	*/
	virtual ~Mazo();
};

#endif /* MAZO_H_ */
