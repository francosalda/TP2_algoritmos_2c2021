#ifndef CARTA_H
#define CARTA_H


/*tipos de efectos de las cartas disponibles*/
typedef enum 
{
	//imprimir con un switch
	CARTA_SIN_EFECTO, // carta sin efecto
	CARTA_PERDER_TURNO, //Hace perder el turno al siguiente jugador
	CARTA_BLOQUEAR_FICHA,//Bloquea la ficha de un jugador
	CARTA_ANULAR_CASILLERO,//Anula un casillero del tablero
	CARTA_VOLVER_JUGADA,//Vuelve atras una jugada del turno(deshacer el turno anterior).
	CARTA_ELIMINAR_CARTA,//Elimina una carta de un jugador.
	CARTA_ROBAR_CARTAS//Roba todas las cartas de otro jugador.
}
habilidadCarta_t; 

/*	[TDA CARTA]:
	.habilidadCarta: indica el tipo de efecto que  tiene la carta
*/

class Carta {
private:
habilidadCarta_t habilidadCarta;

public:
	Carta();
	Carta(habilidadCarta_t efectoCarta);
	void setHabilidad(habilidadCarta_t numero);
	habilidadCarta_t getHabilidad();
	habilidadCarta_t generarEfectoAleatorio();
	virtual ~Carta();
};

#endif /* CARTA_H_ */
