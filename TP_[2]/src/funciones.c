/*
 * funciones.c
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

int PedirEntero(char mensaje[])
{
	int num;

	printf("%s",mensaje);
	scanf("%d",&num);

	while(num<0)
	{
		printf("ERROR,%s",mensaje);
		scanf("%d",&num);
	}

	return num;
}


float PedirFloat(char mensaje[])
{
	float num;

	printf("%s",mensaje);
	scanf("%f",&num);

	while(num<0)
	{
		printf("ERROR,%s",mensaje);
		scanf("%f",&num);
	}

	return num;
}

void PedirString(char mensaje[],char stringIngresado[])
{
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%[^\n]",stringIngresado);

	while(strlen(stringIngresado)>51)
	{
		printf("ERROR,%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
	}
}
