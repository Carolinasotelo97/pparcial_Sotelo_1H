/*
 * informes.h
 *
 *  Created on: 20 oct. 2021
 *      Author: caroo
 */

#ifndef INFORMES_H_
#define INFORMES_H_


int generarListaDeJuegos(eJuegos* listaJuegos,int tamJuegos,eArcade* listaArcades,int tamArcade);
int imprimirJuegos(eArcade* listaArcades,int tamArcade);

int mostrarArcadeSalon(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones);
int salonListado(eSalones* listaSalones,int tamSalones,int idAComparar);
int generarListaDeSalones(eSalones* listaSalones,int tamSalones,eArcade* listaArcades,int tamArcade);
int arcadesPorSalon(eArcade* listaArcades,int tamArcade,int idSalonBuscado);
int informeSalonesMasdeCuatroArcades(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones);
int informeArcadesPorSalon(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones,int idSalonAInformar);
int informeRecaudacionMaximaPorSalon(eArcade* listaArcades,int tamArcade,int idSalonBuscado, float precioFicha);
int informeCantArcadesPorJuego(eArcade* listaArcades,int tamArcade,char nombreJuegoABuscar[]);
int informeSalonCompleto(eArcade *listArcade, int tamArcade, eSalones *listSalon, int tamSalones);
int informeSalonConMasArcades(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones);
int informeArcadeParaMasdeDosJugadores(eArcade* listaArcades,int tamArcade,eSalones* listaSalones,int tamSalones);
int informarPromedioArcadePorSalon(eSalones* listaSalon, int tamSalon, eArcade* listArcade, int tamArcade);
#endif /* INFORMES_H_ */
