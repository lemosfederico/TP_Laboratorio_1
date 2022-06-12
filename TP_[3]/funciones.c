/*
 * funciones.c
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */
#include "funciones.h"

int PedirEntero(char mensaje[],int min,int max)
{
	int num;
	int validar=0;
	char aux[51];

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",aux);

	validar=ValidarEntero(aux);
	while(validar==-1)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",aux);
		validar=ValidarEntero(aux);
	}
	num=atoi(aux);

	while(num<min || num>max)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",aux);
		validar=ValidarEntero(aux);

		if(validar==1)
		{
			num=atoi(aux);
		}
	}

	return num;
}

float PedirFloat(char mensaje[],int min)
{
	float num;
	int validar=0;
	char aux[51];

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%s",aux);

	validar=ValidarEntero(aux);
	while(validar==-1)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",aux);
		validar=ValidarEntero(aux);
	}
	num=atoi(aux);

	while(num<min)
	{
		printf("%s",mensaje);
		fflush(stdin);
		scanf("%s",aux);
		validar=ValidarEntero(aux);

		if(validar==1)
		{
			num=atoi(aux);
		}
	}

	return num;
}

void PedirString(char mensaje[],char stringIngresado[])
{
	puts(mensaje);
	fflush(stdin);
	gets(stringIngresado);

	while(strlen(stringIngresado)>51)
	{
		printf("ERROR,%s",mensaje);
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);
	}
}

int ValidarEntero(char aux[])
{
	int todoOk=0;

	for(int i=0;i<strlen(aux);i++)
	{
		if(isdigit(aux[i])==0)
		{
			todoOk=-1;
			break;
		}
		else
			todoOk=1;
	}

	return todoOk;

}
