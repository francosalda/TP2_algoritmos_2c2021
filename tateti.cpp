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
	this->turnoActual=NULL;
	this->graficarBitmap=false;
	this->largoLineaGanarTateti = 3;
}
/*POST: libera toda la memoria dinamic asociada al tateti*/
Tateti::~Tateti()
{
	destruirMazoJugadores();
	destruirJugadores();
	destruiMazoPrincipal();
	this->destruirMatrizResultadosGanador(3,3);
	delete this->tableroDeJuego;
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
void  Tateti:: destruiMazoPrincipal()
{
	this->mazoPrincipal->destruirMazo();
	delete this->mazoPrincipal;
}
/*Pre: existe la matriz de resultados
Post: libera la memoria dinamica de la matriz de resultados*/

void Tateti::destruirMatrizResultadosGanador(int cantFilas,int cantColumnas)
{


	for(int i =0; i < cantFilas;i++)
	{

		for(int j =0; j < cantColumnas;j++)
		{

			delete[] this->matrizResultadosChequeoGanador[i][j];
		}
		delete[] this->matrizResultadosChequeoGanador[i];
	}

	delete[] this->matrizResultadosChequeoGanador;

}


/*POST: realiza la configuracion inicial de los parametros 
del Tateti mediante la interaccion con el usuario*/
void Tateti:: iniciarJuego()
{
	cout<<"--------------->Bienvenido a TATETI   Multiplayer<-----------------------\n";
	this->crearTablero();
	this->crearJugadores();
	this->crearMatrizResultadosGanador(3,3,3);
	this->imprimirJugadores();
	this->crearMazoPrincipal();
	this->crearMazoJugadores();
	this->inicializarTurnosJugadores();
}

/*
Post crea un tablero de jueego
*/
void Tateti::crearTablero(){
	size_t fila,columna,profundidad;
	cout<<"ingresa las dimensiones del tablero"<<endl;
	cout<<"filas:"<<endl;;
	cin >> fila;
	cout<<"Columnas:"<<endl;
	cin >> columna;
	cout<<"profundidad:"<<endl;
	cin >> profundidad;
	this->tableroDeJuego = new Tablero(fila,columna,profundidad);
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
		cout<<"Ingrese el nombre del jugador "<<i+1<<":\n";
		cin>>nombreJugador;
		cout<<"Ingrese la ficha del jugador "<<i+1<<" (1 caracter):\n";
		cin >>simboloFicha;
		//comprueba que no se repitan fichas
		while(FichaYaOcupadaPorOtroJugador(simboloFicha))
		{
			cout<<"[Error]: La ficha elegida ya esta en uso por otro jugador, seleccione otra: ";
			cin >>simboloFicha;
		}
		nuevoJugador = new Jugador(nombreJugador,simboloFicha);
		nuevoJugador->setearIdJugador(i+1);
		this->listaDeJugadores.agregar(nuevoJugador);
	}
}

void Tateti::crearMatrizResultadosGanador(int cantFilas,int cantColumnas,int cantProfundidad)
{
	int ***  nuevaMatriz = new int **[cantFilas];

	for(int i =0; i < cantFilas;i++)
	{
		nuevaMatriz[i] = new int *[cantColumnas];
		for(int j =0; j < cantColumnas;j++)
		{
			nuevaMatriz[i][j] = new int [cantProfundidad];
			for(int k=0; k < cantProfundidad ; k++)
			{
				nuevaMatriz[i][j][k] = 0;
			}
		}
	}
	this->matrizResultadosChequeoGanador =nuevaMatriz;
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
	/*this->mazoPrincipal=new Mazo(CANTIDAD_CARTAS_MAZO_PRINCIPAL);
	this->mazoPrincipal->barajarMazo();*/
	Mazo * nuevoMazo = NULL;
	nuevoMazo = new Mazo(CANTIDAD_CARTAS_MAZO_PRINCIPAL);
	nuevoMazo->barajarMazo();
	this->mazoPrincipal = nuevoMazo;
}
/*Post: crea en memoria dinamica
el mazo de cartas de cada  jugadores*/
void Tateti::crearMazoJugadores()
{
	this->listaDeJugadores.iniciarCursor();
	while(listaDeJugadores.avanzarCursor())
	{
		Mazo * nuevoMazo = new Mazo();
		this->listaDeJugadores.obtenerCursor()->setMazoJugador(nuevoMazo);
	}
}













/*es el bucle principal del juego*/
void Tateti::jugarJuego()
{
	bool hayTateti = false;
	int filaIngresada,columnaIngresada,profundidadIngresada;
	size_t minimasJugadasAntesDeMover = (this->obtenerMinimaCantidadJugadasTateti()) * (this->obtenerCantidadJugadoresActuales());

	while(!hayTateti)
	{
		this->cantidadJugadasRealizadas++;
		this->turnoActual = colaDeTurnos.desacolar();




		cout<<"-> [Ronda: "<<this->cantidadJugadasRealizadas <<"] Es el turno del jugador ["<<this->turnoActual->obtenerIdJugador()<<"]: '"<<this->turnoActual->obtenerNombreJugador()<<"'\n";
		
		if(this->cantidadJugadasRealizadas <= minimasJugadasAntesDeMover)
		{
			cout<<"Debes colocar una ficha nueva."<<endl;
			this->solicitarIngresoDeCordenadas(filaIngresada,columnaIngresada,profundidadIngresada);
			while(!(this->esFichaValida(filaIngresada,columnaIngresada,profundidadIngresada)))
			{
				this->solicitarIngresoDeCordenadas(filaIngresada,columnaIngresada,profundidadIngresada);
			}
			this->tableroDeJuego->setCasilla(filaIngresada,columnaIngresada,profundidadIngresada,this->turnoActual->obtenerSimboloFichaJugador());
			this->tableroDeJuego->llenarMatrizAdyacentes(filaIngresada, columnaIngresada,profundidadIngresada);
			hayTateti = this->hayGanador(filaIngresada,columnaIngresada,profundidadIngresada);
		}
		else
		{
			if((this->mazoPrincipal->getCantidadCartas()>0) && (this->turnoActual->getMazoJugador()->getCantidadCartas()<CANTIDAD_CARTAS_MAZO_JUGADORES))
			{
				this->repartirCartaAlJugador();
			}
			this->decrementarTurnosCasillerosYFichas();
			this->desbloquearCasilleroYficha();
			this->imprimirCordenadasFichaJugador(this->turnoActual->obtenerSimboloFichaJugador());
			char respuesta;
			unsigned int numero;
			this->turnoActual->getMazoJugador()->imprimirMazo();
			cout<<"desea usar una carta?Ingrese 's' para escoger una carta o cualquiera otra en caso contrario"<<endl;
			cin>>respuesta;
			if(respuesta=='s')
			{
				cout<<"que carta quiere usar?Ingrese el numero de la carta"<<endl;
				cin>>numero;
				this->usarCarta(numero);
			}
			cout<<"Debes mover una ficha, por favor elige cual deseas mover:"<<endl;
			this->solicitarIngresoDeCordenadas(filaIngresada,columnaIngresada,profundidadIngresada);
			this->solicitarMoverFicha(filaIngresada,columnaIngresada,profundidadIngresada);
		}
		this->tableroDeJuego->llenarMatrizAdyacentes(filaIngresada, columnaIngresada,profundidadIngresada);
		hayTateti = this->hayGanador(filaIngresada,columnaIngresada,profundidadIngresada);
		this->avanzarTurno();
	}
	cout<<"--------->>>Felicidades Jugador ["<<this->turnoActual->obtenerIdJugador()<<"] ";
	cout<<this->turnoActual->obtenerNombreJugador()<<"<<<-------------"<<endl;
	cout<<"Ganaste la partida"<<endl;
	//imprimirTablero(this,this->tableroDeJuego->getCantFilasTablero(),this->tableroDeJuego->getCantColumnasTablero(),this->tableroDeJuego->getCantProfundidadTablero());
	
	
}
/*Post: pide al usuario ingresar la fila columna y profundidad ,
y almacena lo ingresado en las variables por referencia*/
void Tateti::solicitarIngresoDeCordenadas(int &filas, int &columnas,int & profundidad)
{
		cout<<"Ingrese una fila :"<<endl;
		cin >> filas;
		cout<<"Ingrese una columna :"<<endl;
		cin >> columnas;
		cout<<"Ingrese una profundidad : "<<endl;
		cin >> profundidad;
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
/*Post: avanza el turno actual al siguiente jugador
en la cola de turnos */
void Tateti:: avanzarTurno()
{
	//pone el jugador actual al final de la cola
	this->colaDeTurnos.acolar(this->turnoActual);
}
/*
 * Pre:
 * Post:valida el casillero.
 */
void Tateti::validarCasillero(Casillero* &casilleroOrigen,int &filas,int &columnas,int &profundidad)
{
	while(casilleroOrigen==NULL)
	{
		cout<<"este casillero esta fuera del rango,por favor ingrese otro"<<endl;
		this->solicitarIngresoDeCordenadas(filas,columnas,profundidad);
		casilleroOrigen= this->tableroDeJuego->getCasillero(filas,columnas,profundidad);
	}
}
/*pre
 * post:usa la carta elegida por el usuario y la borra de su mazo
 */
void Tateti::usarCarta(unsigned int numero)
{
	Carta * carta;
	if(this->turnoActual->getMazoJugador()->getCantidadCartas()>=numero)
	{
		habilidadCarta_t habilidad=this->turnoActual->getMazoJugador()->getMazoCartas().obtener(numero)->getHabilidad();
		if(habilidad==CARTA_PERDER_TURNO)
		{
			//PIERDE TURNO EL SIGUIENTE JUGADOR SINO ES MUY COMPLICADO
		}
		else if(habilidad==CARTA_BLOQUEAR_FICHA)
		{
			this->bloquearFicha();
		}
		else if(habilidad==CARTA_ANULAR_CASILLERO)
		{
			this->anularCasillero();
		}
		else if(habilidad==CARTA_VOLVER_JUGADA)
		{

		}
		else if(habilidad==CARTA_ELIMINAR_CARTA)
		{
			this->eliminarCartaJugador();
		}
		else if(habilidad==CARTA_ROBAR_CARTAS)
		{
			this->robarCartaJugador();
		}
		carta=this->turnoActual->getMazoJugador()->getMazoCartas().obtener(numero);
		this->turnoActual->getMazoJugador()->eliminarCarta(numero);
		delete carta;
	}
}
void Tateti::bloquearFicha()
{
	unsigned int id;
	int fila,columna,profundidad;
	Jugador* jugadorAux;
	cout<<"a que jugador desea bloquearle una ficha?"<<endl;
	cin>>id;
	while(id==this->turnoActual->obtenerIdJugador())
	{
		cout<<"el numero ingresado no es un jugador disponible,por favor ingrese otro"<<endl;
		cin>>id;
	}
	jugadorAux=this->listaDeJugadores.obtener(id);
	imprimirCordenadasFichaJugador(jugadorAux->obtenerSimboloFichaJugador());
	cout<<"cual ficha quiere bloquear?"<<endl;
	this->solicitarIngresoDeCordenadas(fila,columna,profundidad);
	while(!(this->estaEnRangoValido(fila,columna,profundidad)) || jugadorAux->obtenerSimboloFichaJugador()!=this->tableroDeJuego->getCasillero((size_t)fila,(size_t)columna,(size_t)profundidad)->obtenerSimboloFichaDelCasillero())
	{
		cout<<"esta ficha no pertenece al jugador que quiere bloquear"<<endl;
		this->solicitarIngresoDeCordenadas(fila,columna,profundidad);
	}
	this->tableroDeJuego->getCasillero((size_t)fila,(size_t)columna,(size_t)profundidad)->bloquearFichaDelCasillero();
	this->tableroDeJuego->getCasillero((size_t)fila,(size_t)columna,(size_t)profundidad)->setTurnosRestantesDesbloqueo(3);
}
/*
 * POST:anula un casillero elegido por el jugador
 */
void Tateti::anularCasillero()
{
	int fila;
	int columna;
	int profundidad;
	cout<<"indique que casillero quiere anular"<<endl;
	solicitarIngresoDeCordenadas(fila,columna,profundidad);
	while(!estaEnRangoValido(fila,columna,profundidad) || (!estaCasilleroLibre(fila,columna,profundidad)))
	{
		cout<<"las coordenadas ingresadas son incorrectas,por favor ingrese denuevo"<<endl;
		solicitarIngresoDeCordenadas(fila,columna,profundidad);
	}
	this->tableroDeJuego->getCasillero((unsigned int)fila,(unsigned int)columna,(unsigned int)profundidad)->anularCasillero();
	this->tableroDeJuego->getCasillero((unsigned int)fila,(unsigned int)columna,(unsigned int)profundidad)->setTurnosRestantesDesbloqueo(3);
}
/*
 * POST: elimina una carta del mazo de cartas de un jugador
 */
void Tateti::eliminarCartaJugador()
{
	unsigned int id;
	unsigned int numeroCarta;
	Jugador* jugadorAux;
	Carta* carta;
	cout<<"a que jugador desea eliminarle una carta?"<<endl;
	cin>>id;
	while(id==this->turnoActual->obtenerIdJugador())
	{
		cout<<"el numero ingresado no es un jugador disponible,por favor ingrese otro"<<endl;
		cin>>id;
	}
	jugadorAux=this->listaDeJugadores.obtener(id);
	cout<<jugadorAux->obtenerNombreJugador()<<" tiene "<<jugadorAux->getMazoJugador()->getCantidadCartas()<<" carta/s";
	cout<<"elija un numero de carta que quiera eliminar"<<endl;
	cin>>numeroCarta;
	carta=jugadorAux->getMazoJugador()->getMazoCartas().obtener(numeroCarta);
	delete carta;
	this->listaDeJugadores.obtener(id)->getMazoJugador()->eliminarCarta(numeroCarta);
}
/*
 * POST:roba una carta del mazo de cartas de un jugador y la asigna al jugador invocador de la carta.
 */
void Tateti::robarCartaJugador()
{
	unsigned int id;
	unsigned int numeroCarta;
	Jugador* jugadorAux;
	Carta* carta;
	cout<<"a que jugador desea robarle una carta?"<<endl;
	cin>>id;
	while(id==this->turnoActual->obtenerIdJugador())
	{
		cout<<"el numero ingresado no es un jugador disponible,por favor ingrese otro"<<endl;
		cin>>id;
	}
	jugadorAux=this->listaDeJugadores.obtener(id);
	cout<<jugadorAux->obtenerNombreJugador()<<" tiene "<<jugadorAux->getMazoJugador()->getCantidadCartas()<<" carta/s";
	cout<<"elija un numero de carta que quiera robar"<<endl;
	cin>>numeroCarta;
	carta=jugadorAux->getMazoJugador()->getMazoCartas().obtener(numeroCarta);
	this->turnoActual->getMazoJugador()->agregarCarta(carta);
	this->listaDeJugadores.obtener(id)->getMazoJugador()->eliminarCarta(numeroCarta);
}
void Tateti::decrementarTurnosCasillerosYFichas()
{
	size_t i;
	size_t j;
	size_t k;
	for(i=1;i<=this->tableroDeJuego->getCantFilasTablero();i++)
	{
		for(j=1;j<=this->tableroDeJuego->getCantColumnasTablero();j++)
		{
			for(k=1;k<=this->tableroDeJuego->getCantProfundidadTablero();k++)
			{
				Casillero* casillero=this->tableroDeJuego->getCasillero(i,j,k);
				if(casillero->estaCasilleroAnulado())
				{
					casillero->decrementarTurnosRestantesDesbloqueo();
				}
				if(casillero->obtenerContenidoCasillero()->estaBloqueadaFicha())
				{
					casillero->obtenerContenidoCasillero()->decrementarTurnosRestantesDesbloqueo();
				}
			}
		}
	}
}
void Tateti::desbloquearCasilleroYficha()
{
	size_t i;
	size_t j;
	size_t k;
	for(i=1;i<=this->tableroDeJuego->getCantFilasTablero();i++)
	{
		for(j=1;j<=this->tableroDeJuego->getCantColumnasTablero();j++)
		{
			for(k=1;k<=this->tableroDeJuego->getCantProfundidadTablero();k++)
			{
				Casillero* casillero=this->tableroDeJuego->getCasillero(i,j,k);
				if(casillero->estaCasilleroAnulado() && casillero->getTurnosRestantesDesbloqueo()==0)
				{
					casillero->desbloquearCasillero();
				}
				if(casillero->obtenerContenidoCasillero()->estaBloqueadaFicha() && casillero->obtenerContenidoCasillero()->getTurnosRestantesDesbloqueo()==0)
				{
					casillero->obtenerContenidoCasillero()->desbloquearFicha();
				}
			}
		}
	}
}

void Tateti::imprimirCordenadasFichaJugador(char ficha)
{
	size_t i;
	size_t j;
	size_t k;
	int l=1;
	for(i=1;i<=this->tableroDeJuego->getCantFilasTablero();i++)
	{
		for(j=1;j<=this->tableroDeJuego->getCantColumnasTablero();j++)
		{
			for(k=1;k<=this->tableroDeJuego->getCantProfundidadTablero();k++)
			{
				if(this->tableroDeJuego->getCasillero(i,j,k)->obtenerSimboloFichaDelCasillero()==ficha)
				{
					cout<<"FICHA "<<l<<": FILA:"<<i<<" ,COLUMNA:"<<j<<" ,PROFUNDIDAD:"<<k<<endl;
					l++;
				}
			}
		}
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
		






/*Post devuelve TRUE si la ficha ingresada en las coordenadas es valido o FALSE en caso contrario
 *
 */
bool Tateti::esFichaValida(int &filas, int &columnas,int & profundidad)
{
	bool esValido=true;
	//chequea si esta en un rango valido
	if(!estaEnRangoValido(filas,columnas,profundidad))
	{
		cout<<"->[Error]: ingresante un rango invalido, recuerda que va desde 1 al maximo,por favor ingrese devuelta"<<endl;
		esValido=false;
	}
	//chequea si el casillero elegido no esta ocupado
	else if(!estaCasilleroLibre(filas,columnas,profundidad))
	{
		cout<<"->[Error]: La casilla ya se encuentra ocupada,por favor elige otra :\n";
		esValido=false;
	}
	return esValido;
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
/*Post devuelve true en caso de poder realizar el movimiento de la ficha o false en caso contrario
 *
 */
bool Tateti::solicitarMoverFicha(int &filas, int &columnas,int & profundidad)
{
	Casillero * casilleroOrigen=this->tableroDeJuego->getCasillero(filas,columnas,profundidad);
	this->validarCasillero(casilleroOrigen,filas,columnas,profundidad);
	char fichaActualEnEseCasillero = casilleroOrigen->obtenerSimboloFichaDelCasillero();
	while(!(this->perteneceFichaAlJugador(fichaActualEnEseCasillero)) || (this->estaFichaBloqueada(casilleroOrigen)))
	{
		cout<<"->[Error]: La casilla elegida no contiene ninguna ficha que te pernezca o esta bloqueada,elige otra:"<<endl;
		this->solicitarIngresoDeCordenadas(filas,columnas,profundidad);
		casilleroOrigen = this->tableroDeJuego->getCasillero(filas,columnas,profundidad);
		this->validarCasillero(casilleroOrigen,filas,columnas,profundidad);
		fichaActualEnEseCasillero = casilleroOrigen->obtenerSimboloFichaDelCasillero();
	}
	int nuevaFila,nuevaCol,nuevaProfundidad;
	cout<<"Elige la posicion a la cual deseas mover tu ficha:"<<endl;
	solicitarIngresoDeCordenadas(nuevaFila,nuevaCol,nuevaProfundidad);
	if((!estaEnRangoValido(nuevaFila,nuevaCol,nuevaProfundidad)) || (!estaCasilleroLibre(nuevaFila,nuevaCol,nuevaProfundidad)) || (estaCasilleroAnulado((size_t)nuevaFila,(size_t)nuevaCol,(size_t)nuevaProfundidad)))
	{
		cout<<"->[Error] El casillero destino esta en un rango invalido o ya esta ocupado, PIERDES EL TURNO"<<endl;
		return false;
	}
	Casillero * casilleroDestino = this->tableroDeJuego->getCasillero(nuevaFila,nuevaCol,nuevaProfundidad);
	casilleroOrigen->copiarCasillero(casilleroDestino);
	return true;
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
bool Tateti::perteneceFichaAlJugador(char simboloFichaElegido)
{
	return this->turnoActual->obtenerSimboloFichaJugador()==simboloFichaElegido;
}

/*Pre: el tablero y el casillero existen
Post: devuelve true si el casillero contiene la ficha VACIA
false si contiene cualquier otra ficha*/
bool Tateti::estaCasilleroLibre(size_t fila,size_t columna,size_t profundidad)
{
	return (this->tableroDeJuego->getCasillero(fila,columna,profundidad)->estaCasilleroVacio());
}
bool Tateti::estaCasilleroAnulado(size_t fila,size_t columna,size_t profundidad)
{
	return (this->tableroDeJuego->getCasillero(fila,columna,profundidad)->estaCasilleroAnulado());
}
bool Tateti::estaFichaBloqueada(Casillero * casilleroOrigen)
{
	return casilleroOrigen->obtenerContenidoCasillero()->estaBloqueadaFicha();
}

bool Tateti::chequearMatrizGanadorTateti()
{

	 if((this->matrizResultadosChequeoGanador[0][0][0] +1 +this->matrizResultadosChequeoGanador[2][2][2]) == this->largoLineaGanarTateti){
		return true;
	} //1
	if((this->matrizResultadosChequeoGanador[0][1][0] +1 +this->matrizResultadosChequeoGanador[2][1][2]) == this->largoLineaGanarTateti){
		return true;
	} //2
	if((this->matrizResultadosChequeoGanador[0][2][0] +1 +this->matrizResultadosChequeoGanador[2][0][2]) == this->largoLineaGanarTateti){
		return true;
	} //3
	if((this->matrizResultadosChequeoGanador[0][0][2] +1 +this->matrizResultadosChequeoGanador[2][2][0]) == this->largoLineaGanarTateti){
		return true;
	} //4
	if((this->matrizResultadosChequeoGanador[0][1][2] +1 +this->matrizResultadosChequeoGanador[2][1][0]) == this->largoLineaGanarTateti){
		return true;
	} //5
	if((this->matrizResultadosChequeoGanador[0][2][2] +1 +this->matrizResultadosChequeoGanador[2][0][0]) == this->largoLineaGanarTateti){
		return true;
	} //6
	if((this->matrizResultadosChequeoGanador[0][0][1] +1 +this->matrizResultadosChequeoGanador[2][2][1]) == this->largoLineaGanarTateti){
		return true;
	} //7
	if((this->matrizResultadosChequeoGanador[0][2][1] +1 +this->matrizResultadosChequeoGanador[2][0][1]) == this->largoLineaGanarTateti){
		return true;
	} //8
	if((this->matrizResultadosChequeoGanador[0][1][1] +1 +this->matrizResultadosChequeoGanador[2][1][1]) == this->largoLineaGanarTateti){
		return true;
	} //9
	if((this->matrizResultadosChequeoGanador[1][0][2] +1 +this->matrizResultadosChequeoGanador[1][2][0]) == this->largoLineaGanarTateti){
		return true;
	} //10
	if((this->matrizResultadosChequeoGanador[1][1][2] +1 +this->matrizResultadosChequeoGanador[1][1][0]) ==this->largoLineaGanarTateti){

		return true;
	} //11
	if((this->matrizResultadosChequeoGanador[1][2][2] +1 +this->matrizResultadosChequeoGanador[1][0][0]) == this->largoLineaGanarTateti){
		return true;
	} //12
	if((this->matrizResultadosChequeoGanador[1][0][1] +1 +this->matrizResultadosChequeoGanador[1][2][1]) == this->largoLineaGanarTateti){
		return true;
	} //13
	return false;
} 

/*POST: devuelve true si algun jugador logro realizar
el tateti*/
bool Tateti::hayGanador(int fil,int col,int prof)
{
	
	for(int i = 0 ; i < 3; i++)
		{
			for(int j = 0 ; j < 3; j++)
			{
				for(int k = 0 ; k < 3; k++)
				{
					this->matrizResultadosChequeoGanador[i][j][k]= 0;
				}
			}
		}
		//matrizResultadosChequeoGanador[0][0][0] = 2;
	

	
		Casillero * casilleroOrigen = this->tableroDeJuego->getCasillero(fil,col,prof);

		for(int i = 1 ; i <= 3; i++)
		{
			for(int j = 1 ; j <= 3; j++)
			{
				for(int k = 1 ; k <= 3; k++)
				{
					//salteo el centro
					if(i == 2 && j == 2 && k ==2)
					{
					
						this->matrizResultadosChequeoGanador[i-1][j-1][k-1] = 1;
						//matrizResultados[i-1][j-1][k-1] = 1;
						continue;
					}
					
					if(casilleroOrigen->getLongitud(i,j,k,casilleroOrigen) == 1)
					{
						
					}
						this->matrizResultadosChequeoGanador[i-1][j-1][k-1]= casilleroOrigen->getLongitud(i,j,k,casilleroOrigen);
					//matrizResultados[i-1][j-1][k-1]= casilleroOrigen->getLongitud(i,j,k,casilleroOrigen);
					
					
				}
			}

		}
		/*cout<<"imprimiendo matriz de resultado :\n";
		for(int k = 0 ; k < 3; k++)
		{
			for(int i = 0 ; i < 3; i++)
			{
				for(int j = 0 ; j < 3; j++)
				{
				
					cout<<(this->matrizResultadosChequeoGanador[i][j][k])<<",";
			}cout<<endl;

		}cout<<endl;

}

*/
	return chequearMatrizGanadorTateti();



}



void Tateti::activarGraficarBmp()
{
	this->graficarBitmap = true;
}
void Tateti::desactivarGraficarBmp()
{
	this->graficarBitmap = false;
}