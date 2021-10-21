/*
 * juego.c
 *
 *  Created on: 20 oct. 2021
 *      Author: caroo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "juego.h"

int inicializarJuegos(eJuegos* listaJuegos,int tamJuegos)
{
	int retorno = -1;
	int i;

	if(listaJuegos != NULL && tamJuegos > 0)
	{
		retorno = 0;
		for(i=0;i<tamJuegos;i++)
		{
			listaJuegos[i].isEmpty = 1;
		}
	}
	return retorno;
}

int juegoListado(eJuegos* listaJuegos,int tamJuegos,char juegoAEvaluar[])
{
	int retorno = 0;
	int i;

	if(listaJuegos != NULL && tamJuegos > 0 && juegoAEvaluar != NULL)
	{
		for(i=0;i<tamJuegos;i++)
		{
			if(listaJuegos[i].isEmpty==0)
			{
				if(strncmp(listaJuegos[i].nombreJuego,juegoAEvaluar,JUEGO_LEN)==0)
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}
