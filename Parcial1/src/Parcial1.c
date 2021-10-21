/*
 ============================================================================
 Name        : Parcial1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "salones.h"
#include "arcade.h"
#include "juego.h"
#include "informes.h"
#include "utn.h"

#define TAM_SAL 100
#define TAM_ARC 1000


int main(void)
{

	eSalones arraySalones[TAM_SAL];
	eArcade arrayArcades[TAM_ARC];

	int opcion;
	int auxiliarIndiceSalon;
	int auxiliarIdSalon;
	int auxiliarIndiceArcade;
	int auxiliarIdArcade;
	int opcionCampoAModificar;
	char respuesta;
	char informeAMostrar;
	char juegoSeleccionado[JUEGO_LEN];
	float valorFicha;
	int contadorSalones= 0;

	setbuf(stdout, NULL);



	if(inicializarSalones(arraySalones,TAM_SAL)==0)
	{
		printf("\nArray de salones inicializado correctamente\n");
	}

	if(inicializarArcades(arrayArcades,TAM_ARC)==0)
	{
		printf("Array de arcades inicializado correctamente\n");
	}

	forzarSalon(arraySalones,TAM_SAL,1,"Cady Crush","Cordoba 567",1,1,0);
	forzarSalon(arraySalones,TAM_SAL,2,"Digitex","Mexico 200",2,2,0);
	forzarSalon(arraySalones,TAM_SAL,3,"Palacio digital","Esmeralda 233",1,3,0);
	forzarSalon(arraySalones,TAM_SAL,4,"Juegatron","Santa Fe 234",2,4,0);
	forzarSalon(arraySalones,TAM_SAL,5,"Matrix","Corrientes 123",1,5,0);
	forzarSalon(arraySalones,TAM_SAL,6,"Digiplace","Medrano 123",2,6,0);
	forzarSalon(arraySalones,TAM_SAL,7,"Juego Center","Tacuari 234",1,7,0);
	forzarSalon(arraySalones,TAM_SAL,8,"Speed","Diaz Velez 234",2,8,0);
	forzarSalon(arraySalones,TAM_SAL,9,"Destruction","Cordoba 342",1,9,0);
	forzarSalon(arraySalones,TAM_SAL,10,"Mad games","Mitre 344",2,10,0);

	forzarArcade(arrayArcades,TAM_ARC, 0,"Argentina",1,9,100,0,"Pacman",0,0);
	forzarArcade(arrayArcades,TAM_ARC, 1,"Argentina",1,5,100,0,"Street fighters",1,0);
	forzarArcade(arrayArcades,TAM_ARC, 2,"Brasil",2,1,200,1,"Galaga",2,0);
	forzarArcade(arrayArcades,TAM_ARC, 3,"Chile",1,4,150,1,"Wonderboy",3,0);
	forzarArcade(arrayArcades,TAM_ARC, 4,"Argentina",2,2,150,1,"Mario Bros",4,0);
	forzarArcade(arrayArcades,TAM_ARC, 5,"Japon",1,3,100,1,"Pacman",5,0);
	forzarArcade(arrayArcades,TAM_ARC, 6,"China",2,2,200,2,"Galaga",6,0);
	forzarArcade(arrayArcades,TAM_ARC, 7,"Mexico",2,4,100,2,"Mario Bros",7,0);
	forzarArcade(arrayArcades,TAM_ARC, 8,"Argentina",1,2,500,2,"Centipede",8,0);
	forzarArcade(arrayArcades,TAM_ARC, 9,"Mexico",2,4,100,2,"Snowbros",9,0);
	forzarArcade(arrayArcades,TAM_ARC, 10,"Argentina",1,2,500,2,"Sunset Riders",10,0);
	forzarArcade(arrayArcades,TAM_ARC, 11,"Mexico",2,4,100,3,"Gi Joe",11,0);
	forzarArcade(arrayArcades,TAM_ARC, 12,"Argentina",1,2,500,3,"Pacman",12,0);
	forzarArcade(arrayArcades,TAM_ARC, 13,"Chile",1,4,150,1,"Wonderboy",13,0);
	forzarArcade(arrayArcades,TAM_ARC, 14,"Argentina",2,3,150,1,"Mario Bros",14,0);
	forzarArcade(arrayArcades,TAM_ARC, 15,"Japon",1,5,100,1,"Pacman",15,0);
	forzarArcade(arrayArcades,TAM_ARC, 16,"China",2,5,200,1,"Galaga",16,0);
	forzarArcade(arrayArcades,TAM_ARC, 17,"Mexico",2,4,100,1,"Mario Bros",17,0);
	forzarArcade(arrayArcades,TAM_ARC, 18,"Argentina",1,5,500,1,"Centipede",18,0);
	forzarArcade(arrayArcades,TAM_ARC, 19,"Mexico",2,4,100,1,"Snowbros",19,0);
	forzarArcade(arrayArcades,TAM_ARC, 20,"Argentina",1,5,500,1,"Sunset Riders",20,0);
	forzarArcade(arrayArcades,TAM_ARC, 21,"Mexico",2,4,100,1,"Gi Joe",21,0);
	forzarArcade(arrayArcades,TAM_ARC, 22,"Argentina",1,5,500,1,"Pacman",22,0);
	forzarArcade(arrayArcades,TAM_ARC, 23,"Argentina",1,5,500,1,"Pacman",23,0);
	forzarArcade(arrayArcades,TAM_ARC, 24,"Argentina",1,5,500,1,"Pacman",24,0);
	forzarArcade(arrayArcades,TAM_ARC, 25,"Argentina",1,5,500,1,"Pacman",25,0);
	forzarArcade(arrayArcades,TAM_ARC, 26,"Argentina",1,5,500,1,"Pacman",26,0);
	forzarArcade(arrayArcades,TAM_ARC, 27,"Argentina",1,5,500,1,"Pacman",27,0);

	do{
		printf("1) Alta de salon\n");
		printf("2) Eliminar salon\n");
		printf("3) Imprimir salones\n");
		printf("4) Incorporar arcade\n");
		printf("5) Modificar arcade\n");
		printf("6) Eliminar arcade\n");
		printf("7) Imprimir arcades\n");
		printf("8) Imprimir juegos\n");
		printf("9) Informes\n");
		printf("10) Salir\n");

		if(utn_getNumeroInt(&opcion,"\nIngrese la opción\n","\nOpción inválida\n",0,10,4)==0)
		{
			switch(opcion)
			{
				case 1:
						auxiliarIndiceSalon=buscarLugarVacioSalones(arraySalones,TAM_SAL);
						if(auxiliarIndiceSalon >= 0)
						{
							if(altaSalones(arraySalones,TAM_SAL,auxiliarIndiceSalon)==0)
							{
								printf("\nCarga realizada con éxito\n\n");
								contadorSalones++;
							}
						}
						else
						{
							printf("\nNo hay salones vacios\n\n");
						}
					break;
				case 2:
						imprimirSalones(arraySalones,TAM_SAL,1);
						if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el ID del salon a eliminar","\nId inválido",0,100000000,3)==0)
						{
							auxiliarIndiceSalon =buscarPorIdSalon(arraySalones,TAM_SAL, auxiliarIdSalon);

							if(auxiliarIndiceSalon >= 0 && bajaSalon(arraySalones,TAM_SAL,auxiliarIndiceSalon)== 0)
							{
								if(bajaArcadePorSalon(arrayArcades,TAM_ARC,auxiliarIdSalon)== 0)
								{
									printf("\nBaja de arcades del salon realizada con éxito\n");

								}
								else
								{
									printf("\nNo hay arcades del salon a dar de baja\n");
								}
							}
							else
							{
								printf("\nNo se pudo dar de baja al salon.Verifique el Id\n");
							}
						}
						else
						{
							printf("\nNo se encontró el ID\n");
						}
					break;
				case 3:

					imprimirSalones(arraySalones,TAM_SAL,2);

					break;
				case 4:
						auxiliarIndiceArcade = buscarLugarVacioArcades(arrayArcades,TAM_ARC);
						if(auxiliarIndiceArcade >= 0)
						{
							imprimirSalones(arraySalones,TAM_SAL,1);
							if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el Id del salón: ","\nError",0,100000,3) == 0 &&
									buscarPorIdSalon(arraySalones,TAM_SAL,auxiliarIdSalon) != -1)
							{
								if(altaArcade(arrayArcades,TAM_ARC,auxiliarIndiceArcade,auxiliarIdSalon)==0)
								{
									printf("\nArcade cargado exitosamente\n");
								}
							}
							else
							{
								printf("\nNo se encontró el ID de salón ingresado\n");
							}
						}

					break;
				case 5:
						imprimirArcades(arrayArcades,TAM_ARC);
						if(utn_getNumeroInt(&auxiliarIndiceArcade,"\nIngrese el ID de arcade a modificar","\nERROR",0,100000,3)==0)
						{
							auxiliarIndiceArcade = buscarIdArcade(arrayArcades,TAM_ARC,auxiliarIndiceArcade);
							if(auxiliarIndiceArcade >=0)
							{
								do{
									printf("**************************************************\n");
									printf("¿Cual campo desea modificar?\n");
									printf("11) Cantidad de jugadores\n");
									printf("12) Juego que contiene\n");
									printf("13) Ninguno, volver al menu principal\n");
									printf("**************************************************\n");

									utn_getNumeroInt(&opcionCampoAModificar,"\nIngrese la opción","\nOpción inválida",11,13,3);

									switch(opcionCampoAModificar)
									{
										case 11:
											modificarArcade(arrayArcades,TAM_ARC,auxiliarIndiceArcade,opcionCampoAModificar);
											printf("\nModificación de arcade exitosa\n");
											break;
										case 12:
											imprimirJuegos(arrayArcades,TAM_ARC);
											modificarArcade(arrayArcades,TAM_ARC,auxiliarIndiceArcade,opcionCampoAModificar);
											printf("\nModificación de arcade exitosa\n");
											break;
									}
								}while(opcionCampoAModificar!=13);
							}
							else
							{
								printf("\nId no encontrado");
							}
						}

					break;
				case 6:
					informeArcadesPorSalon(arrayArcades,TAM_ARC,arraySalones,TAM_SAL, auxiliarIdArcade);


						if(utn_getNumeroInt(&auxiliarIdArcade,"\nID de arcade a dar de baja? ","\nERROR",0,100000,3)==0)
						{
							auxiliarIndiceArcade = buscarIdArcade(arrayArcades,TAM_ARC,auxiliarIdArcade);
							if(auxiliarIndiceArcade >= 0)
							{
								printf("\nArcade a eliminar:");
								imprimirUnArcade(arrayArcades,auxiliarIndiceArcade);
								utn_getChar(&respuesta,"\nEsta seguro que desea eliminar el arcade?(s=SI n=NO)\n","\nOpción invalida",2,3);

								if(respuesta=='s')
								{
									bajaArcade(arrayArcades,TAM_ARC,auxiliarIndiceArcade);
									printf("\nBaja realizada con éxito\n");
								}
								else
								{
									printf("\nBaja cancelada\n");
								}
							}
							else
							{
								printf("\nId no encontrado\n");
							}
						}
					break;
				case 7:
						imprimirArcades(arrayArcades,TAM_ARC);
					break;
				case 8:

					imprimirJuegos(arrayArcades,TAM_ARC);

					break;
				case 9:
					do{

						printf("**********SUBMENU DE INFORMES*******************\n");

						printf("A) Salones con mas de 4 arcades\n");
						printf("B) Arcades para mas de 2 jugadores\n");
						printf("C) Informacion de un salon especifico\n");
						printf("D) Todos los arcades de un salon\n");
						printf("E) Salon con mas cantidad de arcades\n");
						printf("F) Maximo de recaudacion de un salon\n");
						printf("G) Juegos que contienen un determinado arcade\n");
						printf("H) Imprimir salones que contengan mas de 8 arcades de 3 o mas jugadores disponibles para jugarlo. \n");
						printf("I) informar el promedio de arcades funcionando que hay en base a la cantidad de salones disponibles.\n");
						printf("Z) Salir\n");

						utn_getChar(&informeAMostrar,"\nSeleccione el informe que desea","\nInforme invalido",2, 2);

						switch(informeAMostrar)
						{
							case 'A':
								informeSalonesMasdeCuatroArcades(arrayArcades,TAM_ARC,arraySalones,TAM_SAL);
								break;
							case 'B':
								informeArcadeParaMasdeDosJugadores(arrayArcades,TAM_ARC,arraySalones,TAM_SAL);
								break;
							case 'C':
								if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el Id del Salón: ","\nError",0,100000,3) ==0)
								{
									informeSalonCompleto(arrayArcades,TAM_ARC,arraySalones,TAM_SAL);
								}
								break;
							case 'D':
								if(utn_getNumeroInt(&auxiliarIdSalon,"\nIngrese el Id del Salón: ","\nError",0,100000,3) ==0)
								{
									informeArcadesPorSalon(arrayArcades,TAM_ARC,arraySalones,TAM_SAL, contadorSalones);
								}
								break;
							case 'E':
								informeSalonConMasArcades(arrayArcades,TAM_ARC,arraySalones,TAM_SAL);
								break;
							case 'F':
								if(utn_getNumeroInt(&auxiliarIdSalon,"\nId Salón: ","\nError",0,100000,3) ==0 &&
								   utn_getNumeroFlotante(&valorFicha, "\nIngrese el valor de la ficha: ","\nError",1,100000,3)==0)
								{
									informeRecaudacionMaximaPorSalon(arrayArcades,TAM_ARC,auxiliarIdSalon,valorFicha);
								}
								break;
							case 'G':
								if(utn_getDescripcion(juegoSeleccionado,"\nSeleccione el juego a informar","\nJuego invalido",JUEGO_LEN,3)==0)
								{
									informeCantArcadesPorJuego(arrayArcades,TAM_ARC,juegoSeleccionado);
								}
								break;
							case 'H':
								if(informeSalonCompleto(arrayArcades,TAM_ARC,arraySalones,TAM_SAL) != 0)
								{
									printf("error al informar promedio, chekee que haya algun salon de alta y vuelva a intentarlo");
								}
								break;
							case 'I':
								if(informarPromedioArcadePorSalon(arraySalones, TAM_SAL, arrayArcades, TAM_ARC)== 0){
									printf("error");
								}
								break;
							}
					}while(informeAMostrar!='Z');

					break;
				default:
					printf("\nerror al informar promedio, chekee que haya algun salon de alta y vuelva a intentarlo\n");
					break;
			}
		}

	}while(opcion!=10);

	return EXIT_SUCCESS;
}
