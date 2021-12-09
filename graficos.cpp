#include "EasyBMP.h"
#include "graficos.h"
#include <string>
#include <iostream>


using namespace std;



void imprimirTablero(Tateti * partidaDeJuego)
{
	BMP  * nuevoBitmapTableroProfundidad1 =  new BMP;
	BMP  * nuevoBitmapTableroProfundidad2 =  new BMP;
	BMP  * nuevoBitmapTableroProfundidad3 =  new BMP;
	BMP auxNumeros;
	auxNumeros.ReadFromFile("numbers.bmp");


	nuevoBitmapTableroProfundidad1->ReadFromFile("tablero_vacio.bmp");
	nuevoBitmapTableroProfundidad2->ReadFromFile("tablero_vacio.bmp");
	nuevoBitmapTableroProfundidad3->ReadFromFile("tablero_vacio.bmp");



	int xnum,ynum;
	int xcasillero,ycasillero;

	Tablero * tableroDeJuego= partidaDeJuego->obtenerTableroDeJuego();
	Casillero * casilleroActual = NULL;
	int idJugadorActual = -1;

	

		for(int col = 1; col <=3; col++)
		{
			for(int fil = 1; fil <=3;fil++)
			{
				casilleroActual= tableroDeJuego->getCasillero(fil,col, 1);
				char fichaActual = casilleroActual->obtenerSimboloFichaDelCasillero();
				idJugadorActual=partidaDeJuego->obtenerIdJugadorPropietarioFicha(fichaActual);
				if(idJugadorActual <0)
				{
					continue;
				}
				obtenerCoordenasNumero(xnum,ynum,idJugadorActual);
				obtenerCoordenasCasillero(xcasillero,ycasillero,fil,col);
				RangedPixelToPixelCopy( auxNumeros, xnum ,ynum, 53, 0,*nuevoBitmapTableroProfundidad1, xcasillero, ycasillero);

			}
		}
		nuevoBitmapTableroProfundidad1->WriteToFile("tablero[1]");
	


	for(int col = 1; col <=3; col++)
		{
			for(int fil = 1; fil <=3;fil++)
			{

				casilleroActual= tableroDeJuego->getCasillero(fil,col, 2);
				char fichaActual = casilleroActual->obtenerSimboloFichaDelCasillero();
				idJugadorActual=partidaDeJuego->obtenerIdJugadorPropietarioFicha(fichaActual);
				if(idJugadorActual <0)
				{
					continue;
				}
				obtenerCoordenasNumero(xnum,ynum,idJugadorActual);
				obtenerCoordenasCasillero(xcasillero,ycasillero,fil,col);
				RangedPixelToPixelCopy( auxNumeros, xnum ,ynum, 53, 0,*nuevoBitmapTableroProfundidad2, xcasillero, ycasillero);

			}
		}
		nuevoBitmapTableroProfundidad2->WriteToFile("tablero[2]");


		for(int col = 1; col <=3; col++)
		{
			for(int fil = 1; fil <=3;fil++)
			{
				casilleroActual= tableroDeJuego->getCasillero(fil,col, 3);
				char fichaActual = casilleroActual->obtenerSimboloFichaDelCasillero();
				idJugadorActual=partidaDeJuego->obtenerIdJugadorPropietarioFicha(fichaActual);
				if(idJugadorActual <0)
				{
					continue;
				}
				obtenerCoordenasNumero(xnum,ynum,idJugadorActual);
				obtenerCoordenasCasillero(xcasillero,ycasillero,fil,col);
				RangedPixelToPixelCopy( auxNumeros, xnum ,ynum, 53, 0,*nuevoBitmapTableroProfundidad3, xcasillero, ycasillero);

			}
		}
		nuevoBitmapTableroProfundidad3->WriteToFile("tablero[3]");
	

	
	
	





	delete nuevoBitmapTableroProfundidad1;
	delete nuevoBitmapTableroProfundidad2;
	delete nuevoBitmapTableroProfundidad3;
}

/*retorna la coordendas x,y de donde
debe copiarse la ficha del jugador 
en el bitmap del tablero
de acuerdo a que fila y columa este la ficha.*/
void obtenerCoordenasCasillero(int &x,int &y, int fil,int col)
{

	x =75 + 205*(col-1);
	y = 60+ 150*(fil-1);

}

/*retorna las cordenadas x,y
donde comienza el numero elegido en la imagen de numeros
(ATENCION: solo funciona hasta el 6)*/
void obtenerCoordenasNumero(int &x,int &y, int numero)
{
	
	x =55*numero;
	y = 55+55*numero;

}

