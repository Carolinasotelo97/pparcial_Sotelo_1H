/*
 * arcade.h
 *
 *  Created on: 17 oct. 2021
 *      Author: caroo
 */

#ifndef ARCADE_H_
#define ARCADE_H_

#define NACIONALIDAD_LEN 100
#define TIPO_MONO	1
#define TIPO_ESTEREO 2
#define JUEGO_LEN 63

typedef struct {
	char nacionalidad[NACIONALIDAD_LEN];
	int tipoDeSonido;
	int cantidadDeJugadores;
	int capacidadMaximaFichas;
	int idSalon;
	char nombreJuego[JUEGO_LEN];
	int idArcade;
	int isEmpty;
}eArcade;

int inicializarArcades(eArcade* listaArcades,int tamArcades);
int buscarLugarVacioArcades(eArcade* listaArcades,int tamArcades);
int generadorDeIDArcade(void);
int altaArcade(eArcade* listaArcades,int tamArcades, int indiceVacio, int idDeSalonACargar);
int forzarArcade(eArcade* listaArcades,int tamArcades, int indiceF, char nacionalidadF[], int tipoDeSonidoF,int cantidadDeJugadoresF,int capacidadMaximaFichasF,int idSalonF,char nombreJuegoF[],int idArcadeF,int isEmptyF);

int buscarIdArcade(eArcade* listaArcades,int tamArcades, int idBuscado);
int modificarArcade(eArcade* listaArcades,int tamArcades, int indiceAModificar, int opcionElegida);

int imprimirArcades(eArcade* listaArcades,int tamArcades);
int imprimirUnArcade(eArcade* listaArcades,int indiceArcadeAImprimir);
int bajaArcade(eArcade* listaArcades,int tamArcades, int indiceBuscadoArcade);
int bajaArcadePorSalon(eArcade* listaArcades,int tamArcades, int idSalonAEliminar);
#endif /* ARCADE_H_ */
