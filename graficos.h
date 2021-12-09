#ifndef GRAFICOS_H
#define GRAFICOS_H
#include "EasyBMP.h"
#include "tateti.h"




void obtenerCoordenasNumero(int &x,int &y, int numero);
void obtenerCoordenasCasillero(int &x,int &y, int fil,int col);
void imprimirTablero(Tateti * partidaDeJuego);
#endif