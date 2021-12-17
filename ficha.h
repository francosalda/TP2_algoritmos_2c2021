#ifndef FICHA_H
#define FICHA_H
#define SIMBOLO_FICHA_VACIA ' '

/*  [TDA FICHA]
    .simbolo : es el caracter representativo de la ficha
    .establoqueada: representa si la ficha puede moverse o no

*/
class Ficha{

private:
    char simbolo;
    bool estaBloqueada;
    unsigned int  turnosRestantesDesbloqueo;
public:
    Ficha();
    Ficha(char caracter);
    void setSimboloFicha(char nuevoSimbolo);
    char getSimboloFicha();
    bool estaBloqueadaFicha();
    void bloquearFicha();
    void desbloquearFicha();
    void setTurnosRestantesDesbloqueo(unsigned int cantidadTurnos);
    unsigned int getTurnosRestantesDesbloqueo();
    void decrementarTurnosRestantesDesbloqueo();
    virtual ~Ficha();
};
#endif 
