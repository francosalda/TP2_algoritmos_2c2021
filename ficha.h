#ifndef FICHA_H
#define FICHA_H
#define SIMBOLO_VACIO ' '
/*                 */
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


/*

    
    • void desbloquearFicha(ficha *): desbloquea la ficha
    • ~FICHA() : nada

*/



#endif 