
#include "Controller.h"

static int idIncremental=1000;
static int GetId();
static int GetId()
{
	return idIncremental++;
}

void controller_GetPrimerId()
{
	FILE* pFile;
	char aux[20];

	pFile=fopen("IdMaximo.txt","r");

	if(pFile!=NULL)
	{
		fscanf(pFile,"%s",aux);
	}

	idIncremental=atoi(aux);

	fclose(pFile);
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)//Abre el archivo y si esta todo bien voy a llamar a parser_fromtext..
{
	FILE* pFile;
	int todoOk;

	pFile=fopen(path,"r");

	if(pArrayListPassenger!=NULL && pFile!=NULL)
	{
		todoOk=parser_PassengerFromText(pFile, pArrayListPassenger);
	}

	if(todoOk==1)
	{
		printf("Se cargo correctamente\n");
	}
	else
	{
		printf("ERROR,No se pudo cargar\n");
	}
	fclose(pFile);

    return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE* pFile;

	int todoOk;

	if(pArrayListPassenger!=NULL)
	{
		pFile = fopen(path,"rb");

		if(pFile!=NULL)
		{
			todoOk=parser_PassengerFromBinary(pFile, pArrayListPassenger);
		}
	}

	if(todoOk==1)
	{
		printf("Se cargo correctamente\n");
	}
	else
	{
		printf("ERROR,No se pudo cargar\n");
	}
	fclose(pFile);

    return todoOk;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)//
{
	int todoOk=0;
	Passenger* aux;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[50];
	char estadoVuelo[50];
	int opcionTipo;
	int opcionEstado;

	aux=Passenger_new();

	id=GetId();
	Passenger_setId(aux,id);

	PedirString("Ingrese nombre: ",nombre);
	strlwr(nombre);
	nombre[0]=toupper(nombre[0]);
	Passenger_setNombre(aux,nombre);

	PedirString("Ingrese apellido: ",apellido);
	strlwr(apellido);
	apellido[0]=toupper(apellido[0]);
	Passenger_setApellido(aux, apellido);

	precio=PedirFloat("Ingrese precio: ",0);
	Passenger_setPrecio(aux, precio);

	opcionTipo=SubmenuTipoPasajero();
	switch(opcionTipo)
	{
	case 1:
		strcpy(tipoPasajero,"EconomyClass");
		Passenger_setTipoPasajero(aux,tipoPasajero);
		break;

	case 2:
		strcpy(tipoPasajero,"ExecutiveClass");
		Passenger_setTipoPasajero(aux,tipoPasajero);
		break;

	case 3:
		strcpy(tipoPasajero,"FirstClass");
		Passenger_setTipoPasajero(aux,tipoPasajero);
		break;
	}

	PedirString("Ingrese codigo de vuelo alfanumerico: ",codigoVuelo);
	strupr(codigoVuelo);
	Passenger_setCodigoVuelo(aux,codigoVuelo);

	opcionEstado=SubMenuEstadoVuelo();
	switch(opcionEstado)
	{
	case 1:
		strcpy(estadoVuelo,"En Horario");
		Passenger_setEstadoVuelo(aux,estadoVuelo);
		break;

	case 2:
		strcpy(estadoVuelo,"Demorado");
		Passenger_setEstadoVuelo(aux,estadoVuelo);
		break;

	case 3:
		strcpy(estadoVuelo,"Aterrizado");
		Passenger_setEstadoVuelo(aux,estadoVuelo);
		break;
	}

	if(pArrayListPassenger!=NULL && aux!=NULL)
	{
		ll_add(pArrayListPassenger,aux);
		todoOk=1;
	}

    return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int idIngresado;
	int auxId;
	float auxPrecio;
	char auxCadena[50];
	Passenger* unPasajero;
	int len;
	int desicion;
	char decisionSalida;

	len=ll_len(pArrayListPassenger);
	controller_ListPassenger(pArrayListPassenger);
	idIngresado=PedirEntero("Ingresa ID que quiere modificar: ",0,5000);

	if(pArrayListPassenger!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			unPasajero=(Passenger*)ll_get(pArrayListPassenger,i);
			Passenger_getId(unPasajero,&auxId);
			if(auxId==idIngresado)
			{
				do
				{
					desicion=SubMenuModificar();
					switch(desicion)
					{
					case 1:
						PedirString(("Ingrese nombre nuevo: "),auxCadena);
						Passenger_setNombre(unPasajero, auxCadena);
						printf("El nombre se ha modificado con EXITO\n");
						break;

					case 2:
						PedirString(("Ingrese apellido nuevo: "),auxCadena);
						Passenger_setApellido(unPasajero, auxCadena);
						printf("El apellido se ha modificado con EXITO\n");
						break;

					case 3:
						auxPrecio=PedirFloat("Ingrese precio nuevo: ",0);
						Passenger_setPrecio(unPasajero,auxPrecio);
						printf("El importe se ha modificado con EXITO\n");
						break;

					case 4:
						PedirString(("Ingrese tipo de pasajero nuevo: "),auxCadena);
						Passenger_setTipoPasajero(unPasajero,auxCadena);
						printf("El tipo de pasajero se ha modificado con EXITO\n");
						break;

					case 5:
						PedirString(("Ingrese codigo de vuelo nuevo: "),auxCadena);
						Passenger_setCodigoVuelo(unPasajero,auxCadena);
						printf("El codigo de vuelo se ha modificado con EXITO\n");
						break;

					case 6:
						PedirString(("Ingrese estado de vuelo nuevo: "),auxCadena);
						Passenger_setEstadoVuelo(unPasajero, auxCadena);
						printf("El codigo de vuelo se ha modificado con EXITO\n");
						break;

					case 7:
						decisionSalida=MenuSalida();
						todoOk=0;
						break;
					}

				}while(decisionSalida!=1);
			}
		}
	}

	return todoOk;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int idIngresado;
	int auxId;
	int respuesta;
	Passenger* unPasajero;
	int len;

	len=ll_len(pArrayListPassenger);
	controller_ListPassenger(pArrayListPassenger);
	idIngresado=PedirEntero("\nIngresa ID que quiere eliminar: ",0,5000);
	printf("\n");

	if(pArrayListPassenger!=NULL)
	{
		for(int i=0;i<len;i++)
		{
			unPasajero=(Passenger*)ll_get(pArrayListPassenger,i);
			Passenger_getId(unPasajero,&auxId);
			if(auxId==idIngresado)
			{
				Passenger_printOne(unPasajero);
				respuesta=PedirEntero("\nSeguro que desea eliminar el pasajero (1-SI/2-NO): ",0,2);
				if(respuesta==1)
				{
					Passenger_delete(unPasajero);
					ll_remove(pArrayListPassenger, i);
					printf("\nSe elimino el pasajero con EXITO\n");
					break;
				}
				else
				{
					printf("No se puede eliminar el pasajero\n");
				}
			}

		}
	}

	return todoOk;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger*aux;
	int len;

	len=ll_len(pArrayListPassenger);

	printf("-------------------------------------LISTADO DE PASAJEROS------------------------------------------");
	puts("\n---------------------------------------------------------------------------------------------------");
	printf("ID     NOMBRE     APELIIDO    	PRECIO    TIPO DE PASAJERO 		CODIGO DE VUELO 	ESTADO DE VUELO");
	puts("\n---------------------------------------------------------------------------------------------------");
	for(int i=0;i<len;i++)
	{
		aux=(Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_printOne(aux);
	}
    return 1;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int todoOk=-1;
	int opcion;
	int orden;

	if(pArrayListPassenger!=NULL)
	{
		opcion=MenuOrden();
		orden=PedirEntero("1-Ascendente || 0-Descendente: ",-1,2);
		switch(opcion)
		{
		case 1:
			ll_sort(pArrayListPassenger, Passenger_CompareById,orden);
			break;

		case 2:
			ll_sort(pArrayListPassenger, Passenger_CompareByNombre,orden);
			break;

		case 3:
			ll_sort(pArrayListPassenger,Passenger_CompareByApellido,orden);
			break;

		case 4:
			ll_sort(pArrayListPassenger,Passenger_CompareByprecio,orden);
			break;

		case 5:
			ll_sort(pArrayListPassenger,Passenger_CompareByTipoPasajero,orden);
			break;

		case 6:
			ll_sort(pArrayListPassenger,Passenger_CompareByCodigoVuelo,orden);
			break;

		case 7:
			ll_sort(pArrayListPassenger, Passenger_CompareByEstadoVuelo,orden);
			break;
		case 8:

			break;

		}

	}



	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;
	FILE* pFile = fopen(path,"w");
	Passenger* unPasajeroASalvar;

	int auxId;
	char auxNombre[100];
	char auxApellido[100];
	float auxPrecio;
	char auxCodigo[100];
	char auxTipoPasajero[100];
	char auxEstadoVuelo[100];

	if(pFile!= NULL)
	{
		fprintf(pFile, "id, nombre, apellido, precio, codigoVuelo, TipoPasajero, EstadoVuelo\n");
		for(int i=0;i<ll_len(pArrayListPassenger);i++)
		{
			unPasajeroASalvar = ll_get(pArrayListPassenger, i);

			Passenger_getId(unPasajeroASalvar,&auxId);
			Passenger_getNombre(unPasajeroASalvar,auxNombre);
			Passenger_getApellido(unPasajeroASalvar,auxApellido);
			Passenger_getPrecio(unPasajeroASalvar,&auxPrecio);
			Passenger_getCodigoVuelo(unPasajeroASalvar,auxCodigo);
			Passenger_getTipoPasajero(unPasajeroASalvar,auxTipoPasajero);
			Passenger_getEstadoVuelo(unPasajeroASalvar,auxEstadoVuelo);


			fprintf(pFile, "%d, %s, %s, %f, %s, %s, %s\n", auxId, auxNombre, auxApellido, auxPrecio, auxCodigo, auxTipoPasajero, auxEstadoVuelo);
		}
		todoOk=1;
		fclose(pFile);
	}

	return todoOk;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int todoOk=0;//bandera
	FILE* pFile;
	Passenger* unPasajeroAGuardar;
	int len;

	len = ll_len(pArrayListPassenger);

	pFile=fopen(path,"wb");

	if(pFile!=NULL && pArrayListPassenger!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			unPasajeroAGuardar=(Passenger*)ll_get(pArrayListPassenger,i);
			if(unPasajeroAGuardar != NULL)
			{
				fwrite(unPasajeroAGuardar,sizeof(Passenger),1,pFile);
				todoOk=1;
			}
		}
		fclose(pFile);
	}

	return todoOk;
}

