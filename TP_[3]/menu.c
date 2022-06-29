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

	printf("\n-------------------------------------\n");
	printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n");
	printf("10. Salir\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3,4,5,6,7,8,9,10): ",1,10);
	printf("\n-------------------------------------\n");

	return opcion;
}

int MenuSalida()
{
	int opcion;

	printf("\n-------------------------------------\n");
	printf("Ingreso en la opcion de SALIR.\n");
	printf("1.Para salir\n");
	printf("Cualquier tecla para continuar\n");
	opcion=PedirEntero("INGRESE UNA OPCION: ",0,9999);
	printf("\n-------------------------------------\n");
	return opcion;

}

int SubmenuTipoPasajero()
{
	int opcion;

	printf("\n-------------------------------------\n");
	printf("Ingrese tipo de pasajero: \n");
	printf("1.EconomyClass\n");
	printf("2.ExecutiveClass\n");
	printf("3.FirstClass");
	printf("\n-------------------------------------\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3): ",1,3);
	printf("\n-------------------------------------\n");
	return opcion;
}

int SubMenuEstadoVuelo()
{
	int opcion;

	printf("\n-------------------------------------\n");
	printf("Ingrese estado de vuelo:\n");
	printf("1.En Horario \n");
	printf("2.Demorado\n");
	printf("3.Aterrizado\n");
	printf("\n-------------------------------------\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3): ",1,3);
	printf("\n-------------------------------------\n");
	return opcion;
}

int SubMenuModificar()
{
	int opcion;

	printf("\n-------------------------------------\n");
	printf("Ingrese que desea modificar\n");
	printf("1.Nombre\n");
	printf("2.Apellido\n");
	printf("3.Precio\n");
	printf("4.Tipo de pasajero\n");
	printf("5.Codigo de vuelo\n");
	printf("6.Ingrese estado de vuelo nuevo\n");
	printf("7.SALIR\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3,4,5,6): ",1,7);
	printf("\n-------------------------------------\n");

	return opcion;
}

int MenuOrden()
{
	int opcion;

	printf("\n-------------------------------------\n");
	printf("Ingrese una opcion para ordenar\n");
	printf("1.ID\n");
	printf("2.Nombre\n");
	printf("3.Apellido\n");
	printf("4.Precio\n");
	printf("5.Tipo de pasajero\n");
	printf("6.Codigo de vuelo\n");
	printf("7.Estado de vuelo\n");
	printf("8.SALIR\n");
	opcion=PedirEntero("INGRESE UNA OPCION(1,2,3,4,5,6,7,8): ",1,8);
	printf("\n-------------------------------------\n");

	return opcion;
}
