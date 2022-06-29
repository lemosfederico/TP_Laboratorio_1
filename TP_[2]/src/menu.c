/*
 * menu.c
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#include "menu.h"

int Menu()
{
	int opcion;

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("1.Alta de pasajero\n");
	printf("2.Modificar pasajero\n");
	printf("3.Baja de pasajero\n");
	printf("4.Informar pasajeros\n");
	printf("5.Alta forzada de pasajeros\n");
	printf("6.SALIR\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION(1,2,3,4,5,6): ","ERROR,opcion no valida\n",1,6);

	return opcion;
}

int SubMenuListar()
{
	int opcion;

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Ingrese una opcion para listar\n");
	printf("1.Listado de los pasajeros ordenados alfabaticamente por Apellido y Tipo de pasajero\n");
	printf("2.Total y promedio de los precios de los pasajes, y cu�ntos pasajeros superan el precio promedio\n");
	printf("3.Listado de los pasajeros por Codigo de vuelo y estados de vuelos ACTIVO\n");
	printf("4.Salir\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION(1,2,3,4): ","ERROR,opcion no valida\n",1,4);

	return opcion;
}

int MenuSalida()
{
	int opcion;

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Ingreso en la opcion de SALIR.\n");
	printf("1.Para salir\n");
	printf("Cualquier tecla para continuar\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION: ","ERROR,opcion no valida\n",1,INT_MAX);

	return opcion;

}
