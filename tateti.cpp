#include "tateti.h"
#include "Lista.h"
#include "graficos.h"
#include <iostream>
#include <string>

using namespace std;

/*POS : crea una partida de tateti para posteriormente
ser cargada su configuracion */

Tateti::Tateti()
{
	this->tableroDeJuego = NULL;
	this->cantidadJugadasRealizadas= 0;
	this->mazoPrincipal = NULL;
}

/*
Post crea un tablero de jueego
*/
void Tateti:: crearTablero(){
	this->tableroDeJuego = new Tablero(3,3,3);
}

/*POST: realiza la configuracion inicial de los parametros 
del Tateti mediante la interaccion con el usuario*/
void Tateti:: iniciarJuego()
{
	cout<<"--------------->Bienvenido a TATETI   Multiplayer<-----------------------\n";
	this->crearTablero();
	this->crearJugadores();
	this->imprimirJugadores();
	this->inicializarTurnosJugadores();
	this->crearMazoPrincipal();
	this->crearMazoJugadores();

	
}

/*Imprime la lista de jugadores actuales con sus fichas*/

void Tateti::imprimirJugadores()
{
	cout<<"-----------JUGADORES DE LA PARTIDA ------------------\n";
	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		cout<<"["<<(this->listaDeJugadores.obtenerCursor())->obtenerIdJugador()<<"]";
		cout<<(this->listaDeJugadores.obtenerCursor())->obtenerNombreJugador();
		cout<<" con la ficha : "<<this->listaDeJugadores.obtenerCursor()->obtenerSimboloFichaJugador()<<"\n";
	}

	cout<<"-------------------------------------------\n";
}

/*Post: libera la memoria de los jugadores*/
void Tateti::destruirJugadores()
{
	this->listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		(this->listaDeJugadores.obtenerCursor())->destruirFichaJugador(); //libera la memoria de la ficha del jugador
		delete (this->listaDeJugadores.obtenerCursor()); //libera la memoria del jugador
	}
}


/*POST: inicializa la lista de jugadores del tateti
con sus nombres y fichas*/
void Tateti::  crearJugadores()
{
	//se pide la cantidad de jugadores
	int inputCantidadJugadores = 0;
	cout<<"Ingrese la cantidad de jugadores: \n";
	cin>>(inputCantidadJugadores);
	//comprueba el rango de los jugadores
	while(inputCantidadJugadores < 2 )
	{
		cout<<"[Error]: Deben jugar almenos 2 jugadores, ingrese una nueva cantidad: ";
		cin>>(inputCantidadJugadores);
	}
	//se ingresan los datos de los jugadores
	string nombreJugador ;
	Jugador *nuevoJugador = NULL;
	char simboloFicha = ' ';
	for(size_t i = 0; i < (size_t)inputCantidadJugadores;i++)
	{
		cout<<"Ingrese el nombre del jugador "<<i<<":\n";
		cin>>nombreJugador;
		cout<<"Ingrese la ficha del jugador "<<i<<" (1 caracter):\n";
		cin >>simboloFicha;
		//comprueba que no se repitan fichas
		while(FichaYaOcupadaPorOtroJugador(simboloFicha))
		{
			cout<<"[Error]: La ficha elegida ya esta en uso por otro jugador, seleccione otra: ";
			cin >>simboloFicha;
	
		}
		nuevoJugador = new Jugador(nombreJugador,simboloFicha);
		nuevoJugador->setearIdJugador(i);
		this->listaDeJugadores.agregar(nuevoJugador);
	}
}
/*Post: devuelve true si el simbolo elegido para la ficha
ya la eligio otro jugador antes y por ende esta ocupado*/
bool Tateti::FichaYaOcupadaPorOtroJugador(char simboloFichaElegido)
{
	listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		if (this->listaDeJugadores.obtenerCursor()->obtenerSimboloFichaJugador() == simboloFichaElegido)
		{
			return true;
		}
	}
	return false;
}
/*Post: devuelve true si la ficha cuyo simbolo se corresponde
con el jugador actual, sino le pertenece a el,devuelve false
*/
bool Tateti::perteneceFichaAlJugador(char simboloFicha)
{
	listaDeJugadores.iniciarCursor();
	while(this->listaDeJugadores.avanzarCursor())
	{
		if (this->listaDeJugadores.obtenerCursor()->obtenerSimboloFichaJugador() == simboloFicha &&  this->listaDeJugadores.obtenerCursor()->obtenerIdJugador() == this->turnoActual->obtenerIdJugador())
		{
			return true;
		}
	}
	return false;
}


/*POST: inicia la cola de turnos del tateti
con los jugadores presentes en el orden en el que se ingresaron por interfaz*/
void  Tateti::inicializarTurnosJugadores()
{

	this->listaDeJugadores.iniciarCursor();
	while(listaDeJugadores.avanzarCursor())
	{
		this->colaDeTurnos.acolar(listaDeJugadores.obtenerCursor()); 
	}
}

/*Post: crea el mazo principal del juego*/
void  Tateti:: crearMazoPrincipal()
{
	Mazo * nuevoMazo = NULL;
	nuevoMazo = new Mazo(CANTIDAD_CARTAS_MAZO_PRINCIPAL);
	nuevoMazo->barajarMazo();


	this->mazoPrincipal = nuevoMazo;

}

void  Tateti:: destruiMazoPrincipal()
{
	this->mazoPrincipal->destruirMazo();

	delete this->mazoPrincipal;
}



/*POST: devuelve true si algun jugador logro realizar
el tateti*/
bool Tateti::hayGanador()
{
	return false;
}




/*es el bucle principal del juego*/
void Tateti::jugarJuego()
{
	int filaIngresada,columnaIngresada,profundidadIngresada;
	size_t minimasJugadasAntesDeMover = (this->obtenerMinimaCantidadJugadasTateti()) * (this->obtenerCantidadJugadoresActuales());

	cout<<"[DEBUG]: (SOLO 6 rondas y corta ya que no tenemos hayGanador() aun)\n";

	while( this->cantidadJugadasRealizadas < 6) // seria while(!this->hayGanador())  pero no funciona aun el chequeo de ganador
	{	
		this->cantidadJugadasRealizadas++;
		this->turnoActual = colaDeTurnos.desacolar();
		cout<<"-> [Ronda: "<<this->cantidadJugadasRealizadas <<"] Es el turno del jugador ["<<this->turnoActual->obtenerIdJugador()<<"]: '"<<this->turnoActual->obtenerNombreJugador()<<"'\n";
	

		if(cantidadJugadasRealizadas <= minimasJugadasAntesDeMover)
		{
			cout<<"Debes colocar una ficha nueva.\n";
			//si fallo el ingreso de una ficha nueva por estar fuera de rango, pierde el turno
			if(!solicitarIngresoNuevaFicha(filaIngresada,columnaIngresada,profundidadIngresada))
			{
				cantidadJugadasRealizadas--;
				this->avanzarTurno();
				continue;
			}	
		
		//si esta en un rango valido guarda la ficha ingresada en el tablero
		this->tableroDeJuego->setCasilla(filaIngresada,columnaIngresada,profundidadIngresada,this->turnoActual->obtenerSimboloFichaJugador());
		}

		//si es hora de mover fichas
		else
		{
			//repartir carta jugador
			this->repartirCartaAlJugador();
			cout<<"Debes mover una ficha, por favor elige cual deseas mover:\n";
			if(!solicitarMoverFicha(filaIngresada,columnaIngresada,profundidadIngresada))
			{
				cantidadJugadasRealizadas--;
				this->avanzarTurno();
				continue;
			}
	
		}

		
		//dar una carta a cada jugador luego de su turno
		// si ya se colocaron todas las fichas moverlas
		//usar las cartas
		
		
		this->avanzarTurno();
	}
	imprimirTablero(this,this->tableroDeJuego->getCantFilasTablero(),this->tableroDeJuego->getCantColumnasTablero(),this->tableroDeJuego->getCantProfundidadTablero());
	

}



/*Post: avanza el turno actual al siguiente jugador
en la cola de turnos */
void Tateti:: avanzarTurno()
{
	//pone el jugador actual al final de la cola
	this->colaDeTurnos.acolar(this->turnoActual);
	

}

/*POST: libera toda la memoria dinamic asociada al tateti*/
Tateti::~Tateti()
{
	destruirMazoJugadores();
	destruirJugadores();
	destruiMazoPrincipal();
	
	delete this->tableroDeJuego;
}


/*Pre: el tablero y el casillero existen
Post: devuelve true si el casillero contiene la ficha VACIA
false si contiene cualquier otra ficha*/
bool Tateti::estaCasilleroLibre(size_t fila,size_t columna,size_t profundidad)
{
	return (this->tableroDeJuego->getCasillero(fila,columna,profundidad)->estaCasilleroVacio());
}

/*Pre: el tablero existe
Post: devuelve true la fila,columna y profundidad recibidas
son validas en el tablero actual*/
bool  Tateti::estaEnRangoValido(int fila,int columna,int profundidad)
{
	int maxFilas = this->tableroDeJuego->getCantFilasTablero();
	int maxColumnas = this->tableroDeJuego->getCantColumnasTablero();
	int maxProfundidad = this->tableroDeJuego->getCantProfundidadTablero();
	if(fila < 1|| fila > maxFilas || columna <1 || columna >maxColumnas ||profundidad<1 || profundidad> maxProfundidad)

	{
		return false;
	}
	return true;
}
/*Post: pide al usuario ingresar la fila columna y profundidad ,
y almacena lo ingresado en las variables por referencia*/
void Tateti::solicitarIngresoDeCordenadas(int &filas, int &columnas,int & profundidad)
{
		cout<<"Ingrese la fila  de su ficha : \n";
		cin >> filas;
		cout<<"Ingrese la Columna de su ficha : \n";
		cin >> columnas;
		cout<<"Ingrese la profundidad de su ficha : \n";
		cin >> profundidad;
}
/*Post: Devuelve la minima cantidad
de jugadas que  deben pasar antes
de  que alguien pueda lograr TATETI 
lo que se corresponde con la menor dimension del tablero*/
size_t Tateti:: obtenerMinimaCantidadJugadasTateti()
{
	size_t cantFilas = this->tableroDeJuego->getCantFilasTablero();
	size_t cantColumnas = this->tableroDeJuego->getCantColumnasTablero();
	size_t cantProfundidad = this->tableroDeJuego->getCantProfundidadTablero();

	size_t aux = ((cantFilas < cantColumnas)? cantFilas:cantColumnas);
	return ((aux < cantProfundidad)? aux : cantProfundidad);
}

/*
Pre: existe la lista de jugadores
Post: deuvelve la cantida de jugadores actuales que posee la partida*/
size_t Tateti::  obtenerCantidadJugadoresActuales()
{
	return this->listaDeJugadores.contarElementos();
}
/*Post carga la variable fila,columna y profundidad recibidas por referencia
con los valores ingresados por el usuario si estan en un rango valido.
caso contrario devuelve false*/
bool Tateti::solicitarIngresoNuevaFicha(int &filas, int &columnas,int & profundidad)
{
	solicitarIngresoDeCordenadas(filas,columnas,profundidad);
	//chequea si esta en un rango valdio
	if(estaEnRangoValido(filas,columnas,profundidad))
	{
		//chequea si el casillero elegido no esta ocupado
		while(!estaCasilleroLibre(filas,columnas,profundidad))
		{
			cout<<"->[Error]: La casilla ya se encuentra ocupada, elige otra :\n";
			if(!solicitarIngresoNuevaFicha(filas,columnas,profundidad))
			{
				return false;
			}
		}
		return true;
	}
	cout<<"->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo, PIERDES EL TURNO\n";
	return false;
}
/*Post carga la variable fila,columna y profundidad recibidas por referencia
con los valores ingresados por el usuario si estan en un rango valido.
caso contrario devuelve false*/
bool Tateti::solicitarMoverFicha(int &filas, int &columnas,int & profundidad)
{
	solicitarIngresoDeCordenadas(filas,columnas,profundidad);
	if(estaEnRangoValido(filas,columnas,profundidad))
	{
		Casillero * casilleroOrigen = this->tableroDeJuego->getCasillero(filas,columnas,profundidad);
		char fichaActualEnEseCasillero = casilleroOrigen->obtenerSimboloFichaDelCasillero();
		while(estaCasilleroLibre(filas,columnas,profundidad) || !perteneceFichaAlJugador(fichaActualEnEseCasillero))
		{
			cout<<"->[Error]: La casilla elegida no contiene ninguna ficha que te pernezca,elige otra:\n";
			if(!solicitarMoverFicha(filas,columnas,profundidad))
			{
				return false;
			}
		}
		int nuevaFila,nuevaCol,nuevaProfundidad;
		cout<<"Elige la posicion a la cual deseas mover tu ficha:\n";
		solicitarIngresoDeCordenadas(nuevaFila,nuevaCol,nuevaProfundidad);
		if(!estaEnRangoValido(nuevaFila,nuevaCol,nuevaProfundidad) || !estaCasilleroLibre(nuevaFila,nuevaCol,nuevaProfundidad))
		{
			cout<<"->[Error] El casillero destino esta en un rango invalido o ya esta ocupado, PIERDES EL TURNO\n";
			return false;
		}
		Casillero * casilleroDestino = this->tableroDeJuego->getCasillero(nuevaFila,nuevaCol,nuevaProfundidad);
		casilleroOrigen->copiarCasillero(casilleroDestino);
		return true;
	}
	cout<<"->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo, PIERDES EL TURNO\n";
	return false;

}


/*le asigna al jugador del turno actual
la ultima carta del mazo*/
void Tateti::repartirCartaAlJugador()
{
	//saco la carta superior del mazo
	Carta * cartaDelMazo = this->mazoPrincipal->obtenerCartaSuperior();
	this->turnoActual->getMazoJugador()->agregarCarta(cartaDelMazo);

	cout<<"->Jugador["<<this->turnoActual->obtenerIdJugador()<<"] ";
	cout<<"'"<<this->turnoActual->obtenerNombreJugador()<<"'' Obtuviste la carta: ";
	cartaDelMazo->imprimirHabilidadCarta();
}






/*Post: crea en memoria dinamica
el mazo de cartas de cada  jugadores*/
void Tateti::crearMazoJugadores()
{
	this->listaDeJugadores.iniciarCursor();
	while(listaDeJugadores.avanzarCursor())
	{
		Mazo * nuevoMazo = new Mazo(CANTIDAD_CARTAS_MAZO_JUGADORES);
		this->listaDeJugadores.obtenerCursor()->setMazoJugador(nuevoMazo);
	}


}


/*Post: elimina la memoria dinamica
del mazo de todos los jugadores*/
void Tateti::destruirMazoJugadores()
{
	this->listaDeJugadores.iniciarCursor();
	while(listaDeJugadores.avanzarCursor())
	{
		(this->listaDeJugadores.obtenerCursor()->getMazoJugador())->destruirMazo();
		delete (this->listaDeJugadores.obtenerCursor()->getMazoJugador());
	}


}

/*Pre: la ficha buscada le pertenece a un jugador ya creado
Post: devuelve la id del jugador que es propietario de dicah ficha
o -1 si la ficha no pertenece a ningun jugador*/
int Tateti::obtenerIdJugadorPropietarioFicha(char fichaBuscada)
{
	int idPropietario = -1;
	this->listaDeJugadores.iniciarCursor();
	{
		while(this->listaDeJugadores.avanzarCursor())
		{
			if(this->listaDeJugadores.obtenerCursor()->obtenerSimboloFichaJugador() == fichaBuscada)
			{
				idPropietario = this->listaDeJugadores.obtenerCursor()->obtenerIdJugador();
			}
		}

	}
	return idPropietario;
}

/*
Post: devuelve el tablero de juego actual*/
Tablero * Tateti::obtenerTableroDeJuego()
{
	return this ->tableroDeJuego;
}