/*
 * salones.c
 *
 *  Created on: 17 oct. 2021
 *      Author: caroo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "salones.h"


int inicializarSalones(eSalones* listaSalones,int tamSalones)
{
	int retorno = -1;
	int i;

	if(listaSalones != NULL && tamSalones > 0)
	{
		retorno = 0;
		for(i=0;i<tamSalones;i++)
		{
			listaSalones[i].isEmpty = VACIO;
		}
	}
	return retorno;
}

int buscarLugarVacioSalones(eSalones* listaSalones,int tamSalones)
{
	int retorno=-1;
	int i;

	if(listaSalones!= NULL && tamSalones>=0)
	{
		for(i=0;i<tamSalones;i++)
		{
			if(listaSalones[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int contadorSalones(void)
{
	static int contadorId=0;

	return contadorId++;
}

int altaSalones(eSalones* listaSalones,int tamSalones, int indiceVacio)
{
	int retorno=-1;
	char auxNombre[128];
	char auxDirec[128];
	int auxTipo;

	if(listaSalones!=NULL && tamSalones>0 && indiceVacio< tamSalones && indiceVacio>=0)
	{
		if(utn_getDescripcion(auxNombre,"Ingrese el nombre: ","Error",NOMBRE_LEN,3)==0)
		{
			if(utn_getDescripcion(auxDirec,"Ingrese la direccion: ", "Error",DIRECCION_LEN,3)==0)
			{
				if(utn_getNumeroInt(&auxTipo,"Ingrese el tipo de salon (SHOPPING:1 LOCAL:2)", "Error",1,2,3)==0)
				{
					strncpy(listaSalones[indiceVacio].nombre,auxNombre,sizeof(listaSalones->nombre));
					strncpy(listaSalones[indiceVacio].direccion,auxDirec,sizeof(listaSalones->direccion));
					listaSalones[indiceVacio].tipoDeSalon=auxTipo;
					listaSalones[indiceVacio].idSalon=contadorSalones();
					listaSalones[indiceVacio].isEmpty=OCUPADO;
					retorno=0;
				}
			}
		}
	}
	return retorno;
}

int forzarSalon(eSalones* listaSalones,int tamSalones, int indiceF,char nombreF[],char direccionF[],int tipoDeSalonF,int idSalonF,int isEmptyF)
{
	int retorno=-1;

	if(listaSalones!=NULL && tamSalones>0 && indiceF< tamSalones && indiceF>=0 && nombreF!=NULL && direccionF!=NULL && (tipoDeSalonF==1||tipoDeSalonF==2) && idSalonF>=0 && (isEmptyF==0||isEmptyF==1))
	{
		strncpy(listaSalones[indiceF].nombre,nombreF,NOMBRE_LEN);
		strncpy(listaSalones[indiceF].direccion,direccionF,DIRECCION_LEN);
		listaSalones[indiceF].tipoDeSalon=tipoDeSalonF;
		listaSalones[indiceF].idSalon=idSalonF;
		listaSalones[indiceF].isEmpty=isEmptyF;
		retorno=0;
	}
	return retorno;
}

int imprimirSalones(eSalones* listaSalones,int tamSalones, int tipoImpresion)
{
	int retorno = -1;
	int i;

	if(listaSalones != NULL && tamSalones > 0)
	{
		retorno = 0;
		for(i=0;i<tamSalones;i++)
		{
			switch(tipoImpresion)
			{
				case 1:
					if(listaSalones[i].isEmpty==0)
					{
						printf("\nId del salon: %d - Nombre: %s - Direccion: %s\n", listaSalones[i].idSalon,listaSalones[i].nombre,listaSalones[i].direccion);
					}
					break;
				case 2:
					if(listaSalones[i].isEmpty==0)
					{
						printf("\nNombre del salon: %s - Direccion: %s - Tipo del salon: %d\n", listaSalones[i].nombre,listaSalones[i].direccion,listaSalones[i].tipoDeSalon);
					}
					break;
			}
		}
	}
	return retorno;
}

int buscarPorIdSalon(eSalones* listaSalones,int tamSalones, int IdBuscado)
{
	int retorno=-1;
	int i;

	if(listaSalones!=NULL && tamSalones>=0 && IdBuscado>=0)
	{
		for(i=0;i<tamSalones;i++)
		{
			if(listaSalones[i].idSalon==IdBuscado && listaSalones[i].isEmpty==OCUPADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int pedirIdSalonAlUsuario(int* idSalon)
{
	int idAux;
	int estado=-1;

	if(utn_getNumeroInt(&idAux,"ingrese el ID del SALON a buscar\n","ERROR\n",0,100,3)==0)
	{
		estado=0;
		*idSalon=idAux;
	}
	return estado;
}

int bajaSalon(eSalones* listaSalones,int tamSalones, int indiceBuscadoSalon)
{
	int retorno = -1;

	if(listaSalones != NULL && tamSalones > 0 && indiceBuscadoSalon < tamSalones && indiceBuscadoSalon >= 0 && listaSalones[indiceBuscadoSalon].isEmpty == OCUPADO)
	{
		listaSalones[indiceBuscadoSalon].isEmpty = VACIO;
		retorno = 0;
	}
	return retorno;
}
