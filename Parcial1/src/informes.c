/*
 * informes.c
 *
 *  Created on: 20 oct. 2021
 *      Author: caroo
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#include "salones.h"
#include "arcade.h"
#include "juego.h"
#include "informes.h"

int generarListaDeJuegos(eJuegos* listaJuegos,int tamJuegos,eArcade* listaArcades,int tamArcade)
{
	int i;
	int indiceListaJuegos=0;
	int retorno=0;

	inicializarJuegos(listaJuegos,tamJuegos);

	for(i=0;i<tamArcade;i++)
	{
		if(listaArcades[i].isEmpty==0 && juegoListado(listaJuegos,tamJuegos,listaArcades[i].nombreJuego)==0 )
		{
			strncpy(listaJuegos[indiceListaJuegos].nombreJuego,listaArcades[i].nombreJuego,JUEGO_LEN);
			listaJuegos[indiceListaJuegos].isEmpty=0;
			indiceListaJuegos++;
		}
	}  
	return retorno;
}

int imprimirJuegos(eArcade* listaArcades,int tamArcade)
{
	int retorno = -1;
	int i;
	eJuegos listaDeJuegosAInformar[1000];

	generarListaDeJuegos(listaDeJuegosAInformar,1000,listaArcades,tamArcade);

	if(listaDeJuegosAInformar[0].isEmpty==0)
	{
		if(listaArcades != NULL && tamArcade > 0)
		{
			retorno = 0;
			printf("\nLista de juegos cargados en el sistema\n\n");

			for(i=0;i<1000;i++)
			{
				if(listaDeJuegosAInformar[i].isEmpty==0)
				{
					printf("%s\n",listaDeJuegosAInformar[i].nombreJuego);
				}
			}
		}
	}
	else
	{
		printf("No hay juegos cargados");
	}
	return retorno;
}

int mostrarArcadeSalon(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones)
{
	int retorno = -1;
	int i;
	int indiceArraySalones;

	if(listaArcades != NULL && tamArcade > 0 && listaSalones != NULL && tamSalones > 0)
	{
		imprimirArcades(listaArcades,tamArcade);
		for(i=0;i<tamArcade;i++)
		{
			if(listaArcades[i].isEmpty == 0)
			{
				indiceArraySalones=buscarPorIdSalon(listaSalones,tamSalones, listaArcades[i].idArcade);
				printf("\nNombre del salon: %s - Direccion: %s - Tipo de salon: %d\n", listaSalones[indiceArraySalones].nombre,listaSalones[indiceArraySalones].direccion,listaSalones[indiceArraySalones].tipoDeSalon);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int salonListado(eSalones* listaSalones,int tamSalones,int idAComparar)
{
	int retorno = 0;
	int i;

	if(listaSalones != NULL && tamSalones > 0 && idAComparar >= 0)
	{
		for(i=0;i<tamSalones;i++)
		{
			if(listaSalones[i].isEmpty==0)
			{
				if(listaSalones[i].idSalon==idAComparar)
				{
					retorno = 1;
					break;
				}
			}
		}
	}
	return retorno;
}

int generarListaDeSalones(eSalones* listaSalones,int tamSalones,eArcade* listaArcades,int tamArcade)
{
	int i;
	int indiceListaSalones=0;
	int retorno=0;

	inicializarSalones(listaSalones,tamSalones);

	for(i=0;i<tamArcade;i++)
	{
		if(listaArcades[i].isEmpty==0 && salonListado(listaSalones,tamSalones,listaArcades[i].idSalon)==0 )
		{
			listaSalones[indiceListaSalones].idSalon=listaArcades[i].idSalon;
			listaSalones[indiceListaSalones].isEmpty=0;
			indiceListaSalones++;
		}
	}
	return retorno;
}

int arcadesPorSalon(eArcade* listaArcades,int tamArcade,int idSalonBuscado)
{
	int contadorArcades;
	int i;

	contadorArcades=0;

	if(listaArcades != NULL && tamArcade > 0 && idSalonBuscado >= 0)
	{
		for(i=0;i<tamArcade;i++)
		{
			if(listaArcades[i].idSalon == idSalonBuscado && listaArcades[i].isEmpty == 0)
			{
				contadorArcades++;
			}
		}
	}
	return contadorArcades;
}

int informeSalonesMasdeCuatroArcades(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones)
{
	int retorno = -1;
	int i;
	int cantArcades;
	int auxiliarIndiceSalon;
	eSalones listaIrrepetibleSalones[1000];

	generarListaDeSalones(listaIrrepetibleSalones,1000,listaArcades,tamArcade);


	if(listaIrrepetibleSalones[0].isEmpty==0)
	{
		if(listaArcades != NULL && tamArcade >=0 && listaSalones != NULL && tamSalones >=0)
		{
			for(i=0;i<1000;i++)
			{
				cantArcades=arcadesPorSalon(listaArcades,tamArcade,listaIrrepetibleSalones[i].idSalon);
				auxiliarIndiceSalon=buscarPorIdSalon(listaSalones,tamSalones, listaIrrepetibleSalones[i].idSalon);
				if(cantArcades>4)
				{
					printf("\nId del salon: %d - Nombre: %s Direccion: %s Tipo de salon: %d\n", listaIrrepetibleSalones[i].idSalon,listaSalones[auxiliarIndiceSalon].nombre,listaSalones[auxiliarIndiceSalon].direccion,listaSalones[auxiliarIndiceSalon].tipoDeSalon);
				}
			}
		}

	}
	else
	{
		printf("No hay salones cargados");
	}
	return retorno;
}

int informeArcadeParaMasdeDosJugadores(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones)
{
	int retorno = -1;
	int i;
	int auxiliarIndiceSalonAinformar;

	if(listaArcades != NULL && tamArcade > 0 && listaSalones != NULL && tamSalones > 0)
	{
		printf("\nListado de arcades para mas de 2 jugadores\n\n");
		for(i=0;i<tamArcade;i++)
		{
			if(listaArcades[i].isEmpty == 0 && listaArcades[i].cantidadDeJugadores > 2)
			{
				retorno = 0;
				auxiliarIndiceSalonAinformar=buscarPorIdSalon(listaSalones,tamSalones, listaArcades[i].idSalon);
				printf("\nID Arcade: %d - Cantidad de jugadores: %d - Nombre del juego: %s - Nombre del salón: %s\n",listaArcades[i].idArcade,listaArcades[i].cantidadDeJugadores,listaArcades[i].nombreJuego,listaSalones[auxiliarIndiceSalonAinformar].nombre);
			}
		}
	}
	return retorno;
}

int informeSalonConMasArcades(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones)
{
	int estado = 0;
	int i;
	int e;
	int idConMasArcades;
	int contadorArcades;
	int contadorConMasArcades;
	int flag = 0;

	if(listaArcades != NULL && tamArcade > 0 && listaSalones != NULL && tamSalones > 0)
	{
		estado = 0;

		for(i = 0; i < tamSalones; i++)
		{
			if(listaSalones[i].isEmpty == 0)
			{
				contadorArcades = 0;
				for(e = 0; e < tamArcade; e++)
				{
					if(listaArcades[e].isEmpty == 0 && listaArcades[e].idSalon == listaSalones[i].idSalon)
					{
						contadorArcades++;
					}
				}
				if(flag == 0 || contadorArcades > contadorConMasArcades)
				{
					idConMasArcades = i;
					contadorConMasArcades = contadorArcades;
					flag = -1;
				}
			}
		}
			printf("\n ID del salon: %d  -  Nombre del salon: %s  -  Direccion del salon: %s  -  tipo: %d  -  cantidad de ARCADES que tiene el salon: %d \n",listaSalones[idConMasArcades].idSalon, listaSalones[idConMasArcades].nombre,listaSalones[idConMasArcades].direccion, listaSalones[idConMasArcades].tipoDeSalon,contadorConMasArcades);
		}

	return estado;
}

int informeRecaudacionMaximaPorSalon(eArcade* listaArcades,int tamArcade,int idSalonBuscado, float precioFicha)
{
	int i;
	int acumuladorFichas;
	float recaudacionTotal;
	int retorno=-1;

	acumuladorFichas=0;

	if(listaArcades != NULL && tamArcade > 0 && idSalonBuscado >= 0 && precioFicha > 0)
	{
		for(i=0;i<tamArcade;i++)
		{
			if(listaArcades[i].idSalon == idSalonBuscado && listaArcades[i].isEmpty == 0)
			{
				acumuladorFichas=acumuladorFichas+listaArcades[i].capacidadMaximaFichas;
			}
		}
		recaudacionTotal=acumuladorFichas*precioFicha;
		printf("\nEl ingreso maximo que puede recaudar el salon id %d es: %.2f\n\n",idSalonBuscado,recaudacionTotal);
		retorno=0;
	}
	return retorno;
}

int informeCantArcadesPorJuego(eArcade* listaArcades,int tamArcade,char nombreJuegoABuscar[])
{
	int retorno=-1;
	int contadorArcades;
	int i;

	contadorArcades=0;

	if(listaArcades != NULL && tamArcade > 0 && nombreJuegoABuscar != NULL)
	{
		for(i=0;i<tamArcade;i++)
		{
			if(strncmp(listaArcades[i].nombreJuego,nombreJuegoABuscar,JUEGO_LEN) == 0 && listaArcades[i].isEmpty == 0)
			{
				contadorArcades++;
			}
		}
		printf("\nLa cantidad de arcades que contienen el juego %s son: %d\n\n",nombreJuegoABuscar,contadorArcades);
		retorno=0;
	}
	return retorno;
}

int informeArcadesPorSalon(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones,int idSalonAInformar)
{
	int retorno = -1;
	int i;
	int auxiliarIndiceSalonAinformar;

	if(listaArcades != NULL && tamArcade>=0 && listaSalones != NULL && idSalonAInformar>=0 && idSalonAInformar>=0)
	{
		auxiliarIndiceSalonAinformar=buscarPorIdSalon(listaSalones,tamSalones,idSalonAInformar);
		printf("\nID del salon: %d - Nombre:  %s - Tipo: %d \n\n", listaSalones[auxiliarIndiceSalonAinformar].idSalon,listaSalones[auxiliarIndiceSalonAinformar].nombre,listaSalones[auxiliarIndiceSalonAinformar].tipoDeSalon);
		printf("Listado de arcades del salon\n");
		for(i=0;i<tamArcade;i++)
		{
			if(listaArcades[i].isEmpty == 0 && listaArcades[i].idSalon == idSalonAInformar)
			{
				retorno = 0;
				printf("\nID del arcade: %d - Tipo de sonido: %d - Cantidad de jugadores: %d - Capacidad máxima de fichas: %d - Nombre del juego: %s\n", listaArcades[i].idArcade,listaArcades[i].tipoDeSonido,listaArcades[i].cantidadDeJugadores,listaArcades[i].capacidadMaximaFichas,listaArcades[i].nombreJuego);
			}

		}
	}
	return retorno;
}
int informeSalonCompleto(eArcade *listArcade, int tamArcade, eSalones *listSalon, int tamSalones)
{
	int estado=-1;
	int i;
	int e;
	int contador=0;

		if(listArcade != NULL && tamArcade>=0)
		{
			for(i=0;i<tamSalones; i++)
			{
				if(listSalon[i].isEmpty==0)
				{
					contador=0; //lo reinicio por vuelta
					for(e=0; e<tamArcade; e++)
					{
						if(listArcade[e].isEmpty==0 && listArcade[e].idSalon == listSalon[i].idSalon && listArcade[e].cantidadDeJugadores>2 )
						{
							contador++;
						}
					}
					if(contador > 8)
					{
						printf("id salon: %d -  cantidad de arcades es de: %d \n",listSalon[i].idSalon,contador);
						estado=0;
					}
				}
			}
		}
		return estado;
	}




int informarPromedioArcadePorSalon(eSalones* listaSalon, int tamSalon, eArcade* listArcade, int tamArcade)
{
	int estado= -1;
	int i;
	int e;
	int contadorSalon=0;
	int contadorArcade=0;
	float promedio=0;

	if(listaSalon != NULL && tamSalon > 0 && listArcade!=NULL && tamArcade >0)
	{
		estado=0;

		for(i=0;i<tamSalon;i++)
		{
			if(listaSalon[i].isEmpty==0)
			{
				contadorSalon++;
			}
		}
		for(e=0; e<tamArcade;e++)
		{
			if(listArcade[e].isEmpty==0)
			{
				contadorArcade++;
			}
		}

		promedio = (float)contadorArcade / contadorSalon;

		printf("El promedio de arcades por salon es de: %f  -", promedio);
	}
	return estado;
}
