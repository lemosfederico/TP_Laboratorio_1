/*
 * funciones.c
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#include "funciones.h"

int PedirEntero(char mensaje[])
{
	char num[50];
	int validar;

	printf("%s",mensaje);
	scanf("%s",num);

	while(ValidarNumero(num)==FALSE)
	{
		printf("ERROR,numero incorrecto \n%s",mensaje);
		scanf("%s",num);
	}

	validar=atoi(num);

	return validar;
}

int PedirEnteroMinMax(char mensaje[],char mensajeError[],int min,int max)
{
	int num;
	int validar;

	do
	{
		num=PedirEntero(mensaje);
		if(num<min || num>max)
		{
			printf(mensajeError);
			validar=FALSE;
		}
		else
		{
			validar=TRUE;
		}

	}while(validar==FALSE);

	return num;
}


float PedirFloat(char mensaje[])
{
	char num[50];
	float validar;

	printf("%s",mensaje);
	scanf("%s",num);

	while(ValidarNumero(num)==FALSE)
	{
		printf("ERROR,numero incorrecto %s",mensaje);
		scanf("%s",num);
	}

	validar=atof(num);

	return validar;
}

float PedirFloatMinMax(char mensaje[],int min,int max)
{
	float num;
	float validar;

	do
	{
		num=PedirFloat(mensaje);
		if(num<min || num>max)
		{
			printf("ERROR,numero no valido\n");
			validar=FALSE;
		}
		else
		{
			validar=TRUE;
		}
	}while(validar==FALSE);


	return num;
}


int ValidarNumero(char string[])
{
	int todoOk=TRUE;
	int tam;

	tam=strlen(string);

	for(int i=0;i<tam;i++)
	{
		if(!isdigit(string[i]))
		{
			todoOk=FALSE;
			break;
		}
	}

	return todoOk;
}


int validarChar(char texto[])
{
	int retorno=0;

	for(int i=0;i<strlen(texto);i++)
	{
		if(!isalpha(texto[i]))
		{
			retorno=-1;
			break;
		}
	}
	return retorno;
}

void PedirString(char mensaje[],char stringIngresado[])
{
	int validar;

	do
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

		validar=validarChar(stringIngresado);

	}while(validar==-1);

	EmprolijarString(stringIngresado);
}

void PedirCodigoVuelo(char mensaje[],char stringIngresado[])
{

	int retorno=-1;

	do
	{
		printf("Ingrese codigo Alfa Numerico: ");
		fflush(stdin);
		scanf("%[^\n]",stringIngresado);

		if(strlen(stringIngresado)>0 && strlen(stringIngresado)<LEN)
		{
			for(int i=0;i<strlen(stringIngresado);i++)
			{
				if(isdigit(stringIngresado[i]) || isalpha(stringIngresado[i]))
				{
					retorno=0;
				}
				else
				{
					retorno=-1;
					break;
				}
			}
		}
	}while(retorno==-1);

}

char PedirLetra(char mensaje[])
{
	char letra;

	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&letra);

	return letra;
}


int Salida()
{
	int opcion;

	printf("Presione 1 para salir\n");
	printf("Presione cualquier tecla para volver a ver el menu: ");
	scanf("%d",&opcion);

	return opcion;
}

void EmprolijarString(char string[])
{
	for(int i=0;i<strlen(string);i++)
	{
		string[i]=tolower(string[i]);
	}

	string[0]=toupper(string[0]);
}

