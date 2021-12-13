#ifndef GRAFICOS_H
#define GRAFICOS_H
#include "EasyBMP.h"
#include "tateti.h"

void obtenerCoordenasNumeroEnBMP(int &x,int &y, int numero);
void obtenerCoordenasCasilleroEnBMP(int &x,int &y, int fil,int col);
void imprimirTablero(Tateti * partidaDeJuego,size_t cantFilas,size_t cantColumnas,size_t cantProfundidad);
void dibujarcapasVacias( Lista<BMP*> * capasTablero,size_t cantFilas,size_t cantColumnas,size_t cantProfundidad);
#endif