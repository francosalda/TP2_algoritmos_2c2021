#ifndef CARTA_H_
#define CARTA_H_
#ifndef NULL
#define NULL 0
#endif
class Carta {
private:
Carta* sig;
int habilidad;
public:
	/*
	 * Pre:-
	 * Post:Crea una carta.
	 */
	Carta(int numero);
	/*
	 * Pre:-
	 * Post:Devuelve el valor del puntero de una carta.
	 */
	Carta* getSig();
	/*
	 * Pre:-
	 * Post:Devuelve el valor de habilidad de una carta.
	 * 1)Hace perder el turno a un jugador
	 * 2)Bloquea la ficha de un jugador
	 * 3)Anula un casillero del tablero
	 * 4)vuelve atras una jugada del turno.
	 * 5)Elimina una carta de un jugador.
	 * 6)Roba todas las cartas de otro jugador.
	 */
	int getHabilidad();
	/*
	 * Pre:-
	 * Post:Inserta un puntero a una carta
	 */
	void setSig(Carta* carta);
	/*
	 * Pre:-
	 * Post:Inserta el valor de habilidad de una carta
	 */
	void setHabilidad(int numero);
	/*
	 * Pre:-
	 * Post:Destruye una carta.
	 */
	virtual ~Carta();
};

#endif /* CARTA_H_ */
