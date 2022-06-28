/*
 * menu.c
 *
 *  Created on: 12 abr. 2022
 *      Author: feder
 */


#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int Menu(float kilometros,float precioVueloAerolineas,float precioVueloLatam)
{
	int opcion;

	printf("--------------------------------------------------------------\n");
	printf("1.Ingresar Kilometros: (km= %.2f)\n",kilometros);
	printf("2.Ingresar precio de vuelos: (Aerolineas= %.2f , Latam= %.2f)\n",precioVueloAerolineas,precioVueloLatam);
	printf("3.Calcular todos los costos: \n");
	printf("a) Tarjeta de debito (descuento 10%%)\n");
	printf("b) Tarjeta de credito (interes 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
	printf("4.Informar resultados\n");
	printf("5.Carga forzada de datos\n");
	printf("6.Salir\n");
	opcion=PedirEnteroMinMax("Ingrese una opcion (1,2,3,4,5,6): ", 1, 6);

	return opcion;
}

int SubMenu()
{
	int opcion;

	printf("--------------------------------------------------------------\n");
	printf("1.Precio vuelo Aerolineas: \n");
	printf("2.Precio vuelo Latam: \n");
	printf("3.Salir\n");
	opcion=PedirEnteroMinMax("Ingrese una opcion (1,2,3): ", 1, 3);


	return opcion;
}

int MenuSalida()
{
	int opcion;

	printf("--------------------------------------------------------------\n");
	printf("Ingreso en la opcion de SALIR.\n");
	printf("1.Para salir\n");
	printf("Cualquier tecla para continuar\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION: ",1,9999);

	return opcion;

}
