/*
 * salones.h
 *
 *  Created on: 17 oct. 2021
 *      Author: caroo
 */

#ifndef SALONES_H_
#define SALONES_H_

#define NOMBRE_LEN 100
#define DIRECCION_LEN 100
#define TIPO_SHOPPING	1
#define TIPO_LOCAL	2

#define VACIO 1
#define OCUPADO 0

typedef struct {
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int tipoDeSalon;
	int idSalon;
	int isEmpty;
}eSalones;

int inicializarSalones(eSalones* listaSalones,int tamSalones);
int buscarLugarVacioSalones(eSalones* listaSalones,int tamSalones);
int contadorSalones(void);
int altaSalones(eSalones* listaSalones,int tamSalones, int indiceVacio);
int forzarSalon(eSalones* listaSalones,int tamSalones, int indiceF,char nombreF[],char direccionF[],int tipoDeSalonF,int idSalonF,int isEmptyF);
int pedirIdSalonAlUsuario(int* idSalon);
int imprimirSalones(eSalones* listaSalones,int tamSalones, int tipoImpresion);
int buscarPorIdSalon(eSalones* listaSalones,int tamSalones, int IdBuscado);
int bajaSalon(eSalones* listaSalones,int tamSalones, int indiceBuscadoSalon);

#endif /* SALONES_H_ */
