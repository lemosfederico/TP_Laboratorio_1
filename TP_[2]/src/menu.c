/*
 * menu.c
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"


int Menu()
{
	int opcion;

	printf("\n***********************************\n");
	printf("1.Alta de pasajero\n");
	printf("2.Modificar pasajero\n");
	printf("3.Baja de pasajero\n");
	printf("4.Informar pasajeros\n");
	printf("5.Alta forzada de pasajeros\n");
	printf("6.SALIR\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3,4,5): ");
	printf("***********************************\n");

	return opcion;
}

int SubMenuModificar()
{
	int opcion;

	printf("\n***********************************\n");
	printf("Ingrese que desea modificar\n");
	printf("1.Nombre\n");
	printf("2.Apellido\n");
	printf("3.Precio\n");
	printf("4.Tipo de pasajero\n");
	printf("5.Codigo de vuelo\n");
	printf("6.Salir\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3,4,5,6): ");
	printf("***********************************\n");

	return opcion;
}

int SubMenuListar()
{
	int opcion;

	printf("\n***********************************\n");
	printf("Ingrese una opcion para listar\n");
	printf("1.Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n");
	printf("2.Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n");
	printf("3.Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n");
	printf("4.Salir\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3,4): ");
	printf("***********************************\n");

	return opcion;
}
