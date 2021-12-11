#include <iostream>
#include <sstream>
#include "EasyBMP.h"
#include "graficos.h"
#include <string>
#include "Lista.h"

using namespace std;


/*Imprime en archivos del tipo BITMAPs el contenido del tablero.
Cada jugador vera representado su ID en el casillero que coloco una ficha.
*/

void imprimirTablero(Tateti * partidaDeJuego,size_t cantFilas,size_t cantColumnas,size_t cantProfundidad)
{
	Lista<BMP*> * capasTablero  = new Lista<BMP*> ;
	//solicita la memoria dinamica para los bitmaps
	for(size_t cantidadCapas = 0; cantidadCapas <cantProfundidad;cantidadCapas++)
	{
		BMP * nuevoBitmap = new BMP;
		capasTablero->agregar(nuevoBitmap);
	}
	
	//carga la imagen auxiliar que contiene el vector de numeros
	BMP auxNumeros;
	auxNumeros.ReadFromFile("numbers.bmp");

	//inicializa los bitmap, (luego debo crear una funcion que los inicialice de acuerdo a su largo y ancho)
	capasTablero->obtener(1)->ReadFromFile("tablero_vacio.bmp");
	capasTablero->obtener(2)->ReadFromFile("tablero_vacio.bmp");
	capasTablero->obtener(3)->ReadFromFile("tablero_vacio.bmp");

	//variables para posicionamiento dentro del bitmap
	int xnum,ynum;
	int xcasillero,ycasillero;

	Tablero * tableroDeJuego = partidaDeJuego->obtenerTableroDeJuego();
	Casillero * casilleroActual = NULL;
	int idJugadorActual = -1;
	//recorro el tablero dibujando las IDs de los jugadores donde colocaron una ficha
	for(size_t profundidad = 1 ;profundidad <=cantProfundidad;profundidad++)
	{		
		for(size_t col = 1; col <= cantColumnas; col++)
		{
			for(size_t fil = 1; fil <=cantFilas;fil++)
			{
				casilleroActual= tableroDeJuego->getCasillero(fil,col, profundidad);
				char fichaActual = casilleroActual->obtenerSimboloFichaDelCasillero();
				idJugadorActual = partidaDeJuego->obtenerIdJugadorPropietarioFicha(fichaActual);
				if(idJugadorActual <0)
				{
					//si la ficha no pertence a ningun jugador entonces no se encontro propietario -> no se grafica(ej:FICHA_VACIA)
					continue;
				}
				obtenerCoordenasNumeroEnBMP(xnum,ynum,idJugadorActual);
				obtenerCoordenasCasilleroEnBMP(xcasillero,ycasillero,fil,col);
				RangedPixelToPixelCopy( auxNumeros, xnum ,ynum, 53, 0,*capasTablero->obtener(profundidad), xcasillero, ycasillero);

			}
		}
		stringstream stringNumeroCapa;
		stringNumeroCapa << profundidad;
		string ruta = "Tablero_Profundidad["+stringNumeroCapa.str()+"].bmp";
		capasTablero->obtener(profundidad)->WriteToFile(ruta.c_str());

	}

	//libera la memoria dinamica de los bitmaps
	capasTablero->iniciarCursor();
	while(capasTablero->avanzarCursor())
	{
		delete capasTablero->obtenerCursor();
	}
	delete capasTablero;
}

/*setea las coordendas (x,y) en pixeles a partir de las cuales
debe empezar a pegarse  la  imagen ficha del jugador 
en el bitmap destino del tablero
de acuerdo a la fila y columa recibida.*/
void obtenerCoordenasCasilleroEnBMP(int &x,int &y, int fil,int col)
{
	x = 75 + 205*(col-1);
	y = 60+ 150*(fil-1);

}

/*setea las cordenadas (x,y) en pixeles desde 
donde comienza el numero elegido en la imagen del vector numeros
(ATENCION: solo funciona hasta el 6)*/
void obtenerCoordenasNumeroEnBMP(int &x,int &y, int numero)
{
	x =55*numero;
	y = 55+55*numero;

}

