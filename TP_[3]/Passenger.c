/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

Passenger* Passenger_new()
{
	Passenger* unPasajero;

	unPasajero=(Passenger*)malloc(sizeof(Passenger));

	return unPasajero;
}

Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellido,char* codigo,char* precio,char* estado)
{
	Passenger* unPasajero;

	unPasajero=Passenger_new();

	if(unPasajero!=NULL)
	{
		Passenger_setId(unPasajero,atoi(idStr));
		Passenger_setNombre(unPasajero, nombreStr);
		Passenger_setTipoPasajero(unPasajero,tipoPasajeroStr);
		Passenger_setApellido(unPasajero,apellido);
		Passenger_setCodigoVuelo(unPasajero,codigo);
		Passenger_setPrecio(unPasajero,atof(precio));
		Passenger_setEstadoVuelo(unPasajero,estado);
	}
	else
	{
		printf("ERROR, en el newParametro");
	}

	return unPasajero;
}

void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && id>0)
	{
		this->id=id;
		todoOk=1;
	}

	return todoOk;
}

int Passenger_getId(Passenger* this,int* id)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre,nombre);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_getNombre(Passenger* this,char* nombre)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre,this->nombre);
		todoOk=1;
	}

	return todoOk;

}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido,apellido);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_getApellido(Passenger* this,char* apellido)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido,this->apellido);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo,this->codigoVuelo);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && tipoPasajero!=NULL)
		{
			strcpy(this->tipoPasajero,tipoPasajero);
			todoOk=1;
		}

	return todoOk;
}

int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		strcpy(tipoPasajero,this->tipoPasajero);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && precio>0)
	{
		this->precio=precio;
		todoOk=1;
	}

	return todoOk;
}

int Passenger_getPrecio(Passenger* this,float* precio)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		todoOk=1;
	}

	return todoOk;
}

int Passenger_setEstadoVuelo(Passenger* this,char* estado)
{
	int todoOk;

	todoOk=0;

	if(estado!=NULL && estado!=NULL)
	{
		strcpy(this->estadoVuelo,estado);
		todoOk=1;
	}

	return todoOk;
}

int Passenger_getEstadoVuelo(Passenger* this,char* estado)
{
	int todoOk;

	todoOk=0;

	if(this!=NULL && estado!=NULL)
	{
		strcpy(estado,this->estadoVuelo);
		todoOk=1;
	}

	return todoOk;
}

void Passenger_printOne(Passenger* unPasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[50];
	char estadoVuelo[50];

	Passenger_getId(unPasajero,&id);
	Passenger_getNombre(unPasajero,nombre);
	Passenger_getApellido(unPasajero,apellido);
	Passenger_getPrecio(unPasajero,&precio);
	Passenger_getTipoPasajero(unPasajero,tipoPasajero);
	Passenger_getCodigoVuelo(unPasajero,codigoVuelo);
	Passenger_getEstadoVuelo(unPasajero,estadoVuelo);

	if(unPasajero!=NULL)
	{

		printf("%4d  %15s  %15s  %10.2f  %17s  %10s  %13s\n ",id
												 	 	 ,nombre
														 ,apellido
														 ,precio
														 ,tipoPasajero
														 ,codigoVuelo
														 ,estadoVuelo);
	}

}

int Passenger_CompareByNombre(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char nombre1[50];
	char nombre2[50];
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getNombre(unPasajero,nombre1);
		Passenger_getNombre(otroPasajero,nombre2);
		retorno=strcmp(nombre1,nombre2);
	}

	return retorno;
}

int Passenger_CompareById(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	int id1;
	int id2;
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getId(unPasajero,&id1);
		Passenger_getId(otroPasajero,&id2);

		if(id1>id2)
		{
			retorno=1;
		}
		else
		{
			if(id1<id2)
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}

int Passenger_CompareByApellido(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char apellido1[50];
	char apellido2[50];
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getApellido(unPasajero,apellido1);
		Passenger_getApellido(otroPasajero,apellido2);

		retorno=strcmp(apellido1,apellido2);
	}

	return retorno;
}

int Passenger_CompareByprecio(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	float precio1;
	float precio2;
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getPrecio(unPasajero,&precio1);
		Passenger_getPrecio(otroPasajero,&precio2);

		if(precio1>precio2)
		{
			retorno=1;
		}
		else
		{
			if(precio1<precio2)
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}

int Passenger_CompareByTipoPasajero(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char tipoPasajero1[50];
	char tipoPasajero2[50];
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getTipoPasajero(unPasajero,tipoPasajero1);
		Passenger_getTipoPasajero(otroPasajero,tipoPasajero2);
		strlwr(tipoPasajero1);
		strlwr(tipoPasajero2);
		retorno=strcmp(tipoPasajero1,tipoPasajero2);
	}

	return retorno;
}

int Passenger_CompareByCodigoVuelo(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char codigoVuelo1[50];
	char codigoVuelo2[50];
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getCodigoVuelo(unPasajero,codigoVuelo1);
		Passenger_getCodigoVuelo(otroPasajero,codigoVuelo2);
		strlwr(codigoVuelo1);
		strlwr(codigoVuelo2);
		retorno=strcmp(codigoVuelo1,codigoVuelo2);
	}

	return retorno;
}

int Passenger_CompareByEstadoVuelo(void* p1,void* p2)
{
	Passenger* unPasajero;
	Passenger* otroPasajero;
	char estadoVuelo1[50];
	char estadoVuelo2[50];
	int retorno=0;

	if(p1!=NULL && p2!=NULL)
	{
		unPasajero=(Passenger*)p1;
		otroPasajero=(Passenger*)p2;
		Passenger_getEstadoVuelo(unPasajero,estadoVuelo1);
		Passenger_getEstadoVuelo(otroPasajero,estadoVuelo2);
		strlwr(estadoVuelo1);
		strlwr(estadoVuelo2);
		retorno=strcmp(estadoVuelo1,estadoVuelo2);
	}

	return retorno;
}
