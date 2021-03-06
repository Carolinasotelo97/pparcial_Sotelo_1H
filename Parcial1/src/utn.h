/*
 * utn.h
 *
 *  Created on: 17 oct. 2021
 *      Author: caroo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef UTN_H_
#define UTN_H_




int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getNumeroInt(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, int longitud, int reintentos);

int utn_getDescripcion(char* pResultado,char* mensaje, char* mensajeError, int longitud, int reintentos);
int utn_getDni(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos);


#endif /* UTN_H_ */
