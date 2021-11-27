#ifndef MAZO_H_
#define MAZO_H_
#include "Pila.h"
#include "Carta.h"
class Mazo {
private:
	Pila<Carta>* mazo;
public:
	Mazo();
	virtual ~Mazo();
	void agregarCarta(Carta dato);
	int sacarCarta(Carta &dato);
};
#endif /* MAZO_H_ */
