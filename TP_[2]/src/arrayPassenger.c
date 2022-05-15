/*
 * arrayPassenger.c
 *
 *  Created on: 29 abr. 2022
 *      Author: feder
 */
#define TRUE 0
#define FALSE 1

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "arrayPassenger.h"
#include "funciones.h"
#include "menu.h"

static int idIncremental=1000;
static int GetId();
static int GetId()
{
	return idIncremental++;
}

int initPassengers(ePassenger passenger[],int len)
{
	int retorno=-1;
	if(passenger!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			passenger[i].isEmpty=TRUE;
			retorno=0;
		}
	}
	return retorno;
}

int SearchFree(ePassenger passenger[],int tam)
{
	int retorno=-1;

	if(passenger!=NULL && tam>=0)
	{
		for(int i=0;i<tam;i++)
		{
			if(passenger[i].isEmpty==TRUE)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int LoadOne(ePassenger list[],int len)
{
	int retorno=-1;
	ePassenger auxiliar;

	PedirString(("Ingrese nombre del pasajero: "),auxiliar.name);
	PedirString(("Ingrese apellido del pasajero: "),auxiliar.lastName);
	auxiliar.price=PedirFloat("Ingrese precio: ");
	PedirString(("Ingrese codigo de vuelo(alfanumerico): "),auxiliar.flycode);
	auxiliar.typePassenger=PedirEntero("Ingrese tipo de pasajero:\n1.ECONOMICO\n2.EJECUTIVO\n3.PRIMERA CLASE\n ");
	auxiliar.id=GetId();
	auxiliar.isEmpty=FALSE;

	retorno=addPassenger(list,len,auxiliar.id,auxiliar.name,auxiliar.lastName,auxiliar.price,auxiliar.typePassenger,auxiliar.flycode);

	return retorno;
}

int addPassenger(ePassenger list[],int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno=-1;
	int indiceLibre;
	ePassenger auxiliar;

	if(list!=NULL && len>=0)
	{
		indiceLibre=SearchFree(list,len);
		if(indiceLibre>=0)
		{
			auxiliar.id=id;
			strcpy(auxiliar.name,name);
			strcpy(auxiliar.lastName,lastName);
			auxiliar.price=price;
			auxiliar.typePassenger=typePassenger;
			strcpy(auxiliar.flycode,flycode);
			auxiliar.isEmpty=FALSE;
			list[indiceLibre]=auxiliar;
			retorno=0;
		}
	}
	return retorno;
}

int findPassengerById(ePassenger list[],int len,int id)
{
	int retorno=-1;

	 for(int i=0;i<len;i++)
	 {
		 if(list!=NULL && list[i].isEmpty!=TRUE && list[i].id == id)
		 {
			 retorno=0;
			 break;
		 }
	 }
	return retorno;
}

int modifyPassenger(ePassenger list[],int tam)
{
	int retorno=-1;
	int idIngresado;
	int desicion;
	char decisionSalida;
	printPassenger(list,tam);
	idIngresado=PedirEntero("Ingresa ID que quiere modificar: ");

	if(list!=NULL && tam>=0)
	{
		for(int i=0;i<tam;i++)
		{
			if(list[i].isEmpty!=TRUE && list[i].id==idIngresado)
			{
				do
				{
					desicion=SubMenuModificar();
					switch(desicion)
					{
					case 1:
						PedirString(("Ingrese nombre nuevo: "),list[i].name);
						printf("El nombre se ha modificado con EXITO\n");
						break;

					case 2:
						PedirString(("Ingrese apellido nuevo: "),list[i].name);
						printf("El apellido se ha modificado con EXITO\n");
						break;

					case 3:
						list[i].price=PedirFloat("Ingrese precio nuevo: ");
						printf("El importe se ha modificado con EXITO\n");
						break;

					case 4:
						list[i].typePassenger=PedirEntero("Ingrese tipo de pasajero nuevo: ");
						printf("El tipo de pasajero se ha modificado con EXITO\n");
						break;

					case 5:
						PedirString(("Ingrese codigo de vuelo nuevo: "),list[i].flycode);
						printf("El codigo de vuelo se ha modificado con EXITO\n");
						break;

					case 6:
						printf("Desea salir? s/n: ");
						fflush(stdin);
						scanf("%c",&decisionSalida);
						decisionSalida=tolower(decisionSalida);
						retorno=0;
						break;
					}

				}while(decisionSalida!='s');
			}
		}
	}

	return retorno;
}

int removePassenger(ePassenger list[], int len, int id)
{
	int retorno=-1;
	printPassenger(list,len);

	if(list!=NULL && len>=0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty!=TRUE && list[i].id==id)
			{
				list[i].isEmpty=TRUE;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

void PrintPassenger(ePassenger passenger)
{
	printf("%4d %10s %10s %.2f %10s %d\n",passenger.id,passenger.name,passenger.lastName,passenger.price,passenger.flycode,passenger.typePassenger);
}

int printPassenger(ePassenger list[], int length)
{
	int retorno=-1;
	if(list!=NULL && length>0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty!=TRUE)
			{
				PrintPassenger(list[i]);
			}
		}
		retorno=0;
	}
	return retorno;
}

int sortPassengers(ePassenger list[], int len, int order)
{
	int retorno=-1;

	ePassenger aux;

	if(list!=NULL && len>0)
	{
		retorno=0;
		if(order==0)
		{
			for (int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmpi(list[i].lastName,list[j].lastName)<0
					|| (strcmpi(list[i].lastName,list[j].lastName)==0 && list[i].typePassenger>list[j].typePassenger))
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
		else
		{
			for (int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmpi(list[i].lastName,list[j].lastName)>0
					|| (strcmpi(list[i].lastName,list[j].lastName)==0 && list[i].typePassenger>list[j].typePassenger))
					{
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}

	}

	return retorno;
}

int pedirIdPasajero()
{
	int id;

	id=PedirEntero("Ingrese el id del pasajero: ");

	return id;
}

int removerPasajero(ePassenger list[],int len)
{
	int retorno=-1;
	int id;

	if(list!=NULL && len>0)
	{
		id=pedirIdPasajero();
		retorno=removePassenger(list,len,id);
	}

	return retorno;
}

int hardcodearEstructura(ePassenger list[],int len)
{
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		addPassenger(list,len,GetId(), "Fede", "Lemos", 150.50, 1, "C002");
		addPassenger(list,len,GetId(), "Leo", "Ledesma", 120.50, 1, "D400");
		addPassenger(list,len,GetId(), "Ana", "Zapallo", 111.50, 1, "F598");
		addPassenger(list,len,GetId(), "Martina", "Garbin", 145.50, 1, "A878");
		addPassenger(list,len,GetId(), "Sebastian", "Lemos", 160.50, 2, "J645");
	}

	return retorno;
}

int getTotalPrecioPasajeros(ePassenger list[],int len,int* cantidadPasajeros)
{
	float acumuladorPrecio=0;
	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty!=TRUE)
			{
				acumuladorPrecio=list[i].price;
				cantidadPasajeros++;
			}
		}
	}
	return acumuladorPrecio;
}

void informarTotalYPromedioPasajes(ePassenger list[],int len)
{
	int cantidadPasajeros=0;
	float acumuladorPrecio=0;
	float promedioPrecios;
	int pasajerosMayorAPromedio=0;

	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty!=TRUE)
			{
				acumuladorPrecio+=list[i].price;
				cantidadPasajeros++;
			}
		}

	promedioPrecios=acumuladorPrecio/cantidadPasajeros;

	for(int i=0;i<len;i++)
	{
		if(list[i].price>promedioPrecios)
		{
			pasajerosMayorAPromedio++;
		}
	}

	}

	printf("El total de precios de los pasajes es: %.2f\nEl promedio es todos los precios es: %.2f\nY la cantidad de pasajeros que el precio supera el promedio es: %d\n"
			,acumuladorPrecio,promedioPrecios,pasajerosMayorAPromedio);

}

