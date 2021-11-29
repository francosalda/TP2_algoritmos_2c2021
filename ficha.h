#ifndef FICHA_H
#define FICHA_H
#define SIMBOLO_VACIO ' '

/*  [TDA FICHA]
    .simbolo : es el caracter representativo de la ficha
    .establoqueada: representa si la ficha puede moverse o no

*/
class Ficha{

private:
    char simbolo;
    bool estaBloqueada;
public:
    Ficha();
    Ficha(char caracter);
    char getSimboloFicha();
    bool estaBloqueadaFicha();
    void bloquearFicha();
    void desbloquearFicha();
    virtual ~Ficha();


};
#endif 