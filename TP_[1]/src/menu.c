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

	printf("1.Ingresar Kilometros: ( km= %.2f)\n",kilometros);
	printf("2.Ingresar precio de vuelos: (Aerolineas= %.2f , Latam= %.2f)\n",precioVueloAerolineas,precioVueloLatam);
	printf("3.Calcular todos los costos: \n");
	printf("a) Tarjeta de débito (descuento 10%%)\n");
	printf("b) Tarjeta de crédito (interés 25%%)\n");
	printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
	printf("d) Mostrar precio por km (precio unitario)\n");
	printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");
	printf("4.Informar resultados\n");
	printf("5.Carga forzada de datos\n");
	printf("6.Salir\n");
	scanf("%d",&opcion);

	return opcion;
}

int SubMenu()
{
	int opcion;

	printf(" 1- Precio vuelo Aerolineas: \n");
	printf(" 2- Precio vuelo Latam: \n");
	printf(" 3- Salir\n");
	scanf("%d",&opcion);

	return opcion;
}
