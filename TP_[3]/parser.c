#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	char id[100];
	char nombre[100];
	char apellido[100];
	char estado[100];
	char tipo[100];
	char precio[100];
	char codigo[100];
	int todoOk=0;
	Passenger* unPasajero;

	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,estado,tipo);

	while(!feof(pFile))
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,estado,tipo);
		unPasajero=Passenger_newParametros(id, nombre, tipo, apellido, codigo, precio, estado);
		if(unPasajero!=NULL)
		{
			ll_add(pArrayListPassenger,unPasajero);
			todoOk=1;
		}
		else
		{
			printf("ERROR,en el parser\n");
		}
	}

    return todoOk;
}


int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int todoOk=0;

	Passenger* unPasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			unPasajero = Passenger_new();

			if(unPasajero!=NULL && fread(unPasajero, sizeof(Passenger), 1, pFile))
			{
				ll_add(pArrayListPassenger, unPasajero);
				todoOk=1;
			}
		}
	}

	return todoOk;
}
