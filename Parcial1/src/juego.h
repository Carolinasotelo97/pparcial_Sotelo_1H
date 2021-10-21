/*
 * juego.h
 *
 *  Created on: 20 oct. 2021
 *      Author: caroo
 */

#ifndef JUEGO_H_
#define JUEGO_H_


#define JUEGO_LEN 63

typedef struct {
	char nombreJuego[JUEGO_LEN];
	int isEmpty;
}eJuegos;

int inicializarJuegos(eJuegos* listaJuegos,int tamJuegos);
int juegoListado(eJuegos* listaJuegos,int tamJuegos,char juegoAEvaluar[]);


#endif /* JUEGO_H_ */
