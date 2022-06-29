/*
 * arrayPassenger.c
 *
 *  Created on: 29 abr. 2022
 *      Author: feder
 */

#include "arrayPassenger.h"

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
	auxiliar.price=PedirFloatMinMax("Ingrese precio: ",1,999999);
	PedirCodigoVuelo(("Ingrese codigo de vuelo(alfanumerico): "),auxiliar.flycode);
	auxiliar.typePassenger=TipoPasajero();
	auxiliar.statusFly=EstadoVuelo();
	auxiliar.id=GetId();
	auxiliar.isEmpty=FALSE;

	retorno=addPassenger(list,len,auxiliar.id,auxiliar.name,auxiliar.lastName,auxiliar.price,auxiliar.typePassenger,auxiliar.flycode,auxiliar.statusFly);

	return retorno;
}

int addPassenger(ePassenger list[],int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFly)
{
	int retorno=-1;
	int indiceLibre;
	ePassenger auxiliar;

	if(list!=NULL && len>=0 && len<2000)
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
			auxiliar.statusFly=statusFly;
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
			 retorno=i;
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
	int decisionSalida;
	printPassengers(list,tam);
	idIngresado=PedirEnteroMinMax("Ingresa ID que quiere modificar: ", "ERROR,ID no valido", 1000, 2000);

	if(list!=NULL && tam>=0)
	{
		for(int i=0;i<tam;i++)
		{
			if(list[i].isEmpty!=TRUE && list[i].id==idIngresado)
			{
				do
				{
					desicion=ModificarPasajero();
					switch(desicion)
					{
					case 1:
						PedirString(("\nIngrese nombre nuevo: "),list[i].name);
						printf("\nEl nombre se ha modificado con EXITO\n");
						break;

					case 2:
						PedirString(("\nIngrese apellido nuevo: "),list[i].lastName);
						printf("\nEl apellido se ha modificado con EXITO\n");
						break;

					case 3:
						list[i].price=PedirFloatMinMax("\nIngrese precio nuevo: ", 1,999999);
						printf("\nEl importe se ha modificado con EXITO\n");
						break;

					case 4:
						list[i].typePassenger=TipoPasajero();
						printf("\nEl tipo de pasajero se ha modificado con EXITO\n");
						break;

					case 5:
						PedirCodigoVuelo("\nIngrese codigo de vuelo nuevo: ", list[i].flycode);
						printf("\nEl codigo de vuelo se ha modificado con EXITO\n");
						break;

					case 6:
						list[i].statusFly=EstadoVuelo();
						printf("\nEl estado de vuelo se ha modificado con EXITO\n");
						break;

					case 7:
						decisionSalida=MenuSalida();
						if(decisionSalida==1)
						{
							printf("Gracias,Vuelva pronto\n");
							retorno=0;
						}
						break;
					}

				}while(decisionSalida!=1);
			}
		}
	}

	return retorno;
}

int removePassenger(ePassenger list[], int len, int id)
{
	int retorno=-1;
	int seguridad;
	if(list!=NULL && len>=0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty!=TRUE && list[i].id==id)
			{
				PrintPassenger(list[i]);
				seguridad=PedirEnteroMinMax("\nSeguro desea eliminar al pasajero? (1-SI/2-NO): ", "ERROR,reintente", 1, 2);
				if(seguridad==1)
				{
					list[i].isEmpty=TRUE;
					retorno=0;
				}
				else
				{
					printf("\nSalio de eliminar\n");
				}
				break;
			}
		}
	}
	return retorno;
}

void PrintPassenger(ePassenger passenger)
{
	printf("%-10d %-15s %-15s %-15.2f %-8s",passenger.id,passenger.name,passenger.lastName,passenger.price,passenger.flycode);
	PrintTypePassenger(passenger);
	PrintEstadoVuelo(passenger);
	printf("\n");
}

int printPassengers(ePassenger list[], int length)
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
		printf("\n		-----------Lista de pasajeros-------------------\n\n");
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

int sortPassengersByCode(ePassenger list[], int len, int order)
{
	int retorno=-1;

	ePassenger aux;

	if(list!=NULL && len>0)
	{
		retorno=0;
		printf("\n		-----------Lista de pasajeros-------------------\n\n");
		if(order==0)
		{
			for (int i=0;i<len-1;i++)
			{
				for(int j=i+1;j<len;j++)
				{
					if(strcmpi(list[i].flycode,list[j].flycode)<0
					|| (strcmpi(list[i].flycode,list[j].flycode)==0 && list[i].statusFly>list[j].statusFly))
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
					if(strcmpi(list[i].flycode,list[j].flycode)>0
					|| (strcmpi(list[i].flycode,list[j].flycode)==0 && list[i].statusFly>list[j].statusFly))
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


int removerPasajero(ePassenger list[],int len)
{
	int retorno=-1;
	int idIngresado;
	printPassengers(list,len);
	idIngresado=PedirEnteroMinMax("\nIngresa ID que quiere eliminar: ", "ERROR,ID no valido", 1000, 2000);
	if(list!=NULL && len>0)
	{
		retorno=removePassenger(list,len,idIngresado);
	}

	return retorno;
}

int hardcodearEstructura(ePassenger list[],int len)
{
	int retorno=-1;

	if(list!=NULL)
	{
		addPassenger(list,len,GetId(), "Fede", "Lemos", 150.50, 1, "C002", 1 );
		addPassenger(list,len,GetId(), "Leo", "Ledesma", 120.50, 3, "D400",2);
		addPassenger(list,len,GetId(), "Ana", "Zapallo", 111.50, 2, "F598",3);
		addPassenger(list,len,GetId(), "Martina", "Garbin", 145.50, 1, "A878",1);
		addPassenger(list,len,GetId(), "Sebastian", "Lemos", 160.50, 2, "J645",2);
		retorno=1;
	}

	for(int i=0;i<len;i++)
	{
		PrintPassenger(list[i]);
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

	printf("El total de precios de los pasajes es: %.2f\nEl promedio es todos los precios es: %.2f\nla cantidad de pasajeros que el precio supera el promedio es: %d\n"
			,acumuladorPrecio,promedioPrecios,pasajerosMayorAPromedio);

}

int ModificarPasajero()
{
	int opcion;

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Ingrese que desea modificar\n");
	printf("1.Nombre\n");
	printf("2.Apellido\n");
	printf("3.Precio\n");
	printf("4.Tipo de pasajero\n");
	printf("5.Codigo de vuelo\n");
	printf("6.Estado de vuelo\n");
	printf("7.Salir\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION(1,2,3,4,5,6,7): ","ERROR,opcion no valida",1,7);

	return opcion;
}

int TipoPasajero()
{
	int opcion;

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Ingrese tipo de pasajero\n");
	printf("1.ECONOMICO\n");
	printf("2.EJECUTIVO\n");
	printf("3.PRIMERA CLASE\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION(1,2,3): ","ERROR,opcion no valida",1,3);

	return opcion;
}

void PrintTypePassenger(ePassenger list)
{
	switch(list.typePassenger)
	{
	case 1:
		printf("%-15s","ECONOMICO");
		break;
	case 2:
		printf("%-15s","EJECUTIVO");
		break;
	case 3:
		printf("%-15s","PRIMERA CLASE");
		break;
	}
}

int EstadoVuelo()
{
	int opcion;

	printf("-------------------------------------------------------------------------------------------------\n");
	printf("Ingrese estado de vuelo\n");
	printf("1.ACTIVO\n");
	printf("2.CANCELADO\n");
	printf("3.DEMORADO\n");
	opcion=PedirEnteroMinMax("INGRESE UNA OPCION(1,2,3): ","ERROR,opcion no valida",1,3);

	return opcion;
}

void PrintEstadoVuelo(ePassenger list)
{
	switch(list.statusFly)
	{
	case 1:
		printf("%-15s","ACTIVO");
		break;
	case 2:
		printf("%-15s","CANCELADO");
		break;
	case 3:
		printf("%-15s","DEMORADO");
		break;
	}
}
