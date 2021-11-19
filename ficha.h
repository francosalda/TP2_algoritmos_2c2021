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
    char getSimboloFicha(Ficha *inputFicha);



    ~Ficha();


};


/*
    • getSimboloFicha(ficha *): devuelve el símbolo de la ficha
    • estaBloqueadaFicha(ficha *): devuelve true si la ficha se encuentra bloqueada
    • void bloquearFicha(ficha *) : bloquea la ficha
    • void desbloquearFicha(ficha *): desbloquea la ficha
    • ~FICHA() : nada

*/



#endif 