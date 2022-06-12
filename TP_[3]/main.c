#include "Controller.h"
#define ARCHIVO_TXT "data.csv"
#define ARCHIVO "data.bin"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

	int opcion;
	int decisionSalida;
	int flagSeguridad=0;
	LinkedList* listaPasajeros=ll_newLinkedList();

	controller_GetPrimerId();
	do
	{
		opcion=Menu();
		switch(opcion)
		{
		case 1:
			if(flagSeguridad==0)
			{
				controller_loadFromText(ARCHIVO_TXT, listaPasajeros);
				flagSeguridad=1;
			}
			else
				printf("Los datos ya se han cargado\n");

			break;

		case 2:
			if(flagSeguridad==0)
			{
				controller_loadFromBinary(ARCHIVO,listaPasajeros);
				flagSeguridad=1;
			}
			else
				printf("Los datos ya se han cargado\n");

			break;

		case 3:
				controller_addPassenger(listaPasajeros);

			break;
		case 4:
			if(ll_isEmpty(listaPasajeros)==0)
			{
				controller_editPassenger(listaPasajeros);
			}
			else
				printf("No se puede modificar sin antes dar alta o cargar\n");

			break;

		case 5:
			if(ll_isEmpty(listaPasajeros)==0)
			{
				controller_removePassenger(listaPasajeros);
			}
			else
				printf("No se puede eliminar sin antes dar alta o cargar\n");

			break;

		case 6:
			if(ll_isEmpty(listaPasajeros)==0)
			{
				controller_ListPassenger(listaPasajeros);
			}
			else
				printf("No se puede mostrar sin antes dar alta o cargar\n");

			break;

		case 7:
			if(ll_isEmpty(listaPasajeros)==0)
			{
				controller_sortPassenger(listaPasajeros);
			}
			else
				printf("No se puede ordenar sin antes dar alta o cargar\n");

			break;

		case 8:
			if(ll_isEmpty(listaPasajeros)==0)
			{
				controller_saveAsText("data.csv",listaPasajeros);
			}
			else
				printf("No se puede guardar sino se cargo nada\n");

			break;

		case 9:
			if(ll_isEmpty(listaPasajeros)==0)
			{
				controller_saveAsBinary("data.bin",listaPasajeros);
			}
			else
				printf("No se puede guardar sino se cargo nada\n");

			break;

		case 10:
			decisionSalida=MenuSalida();
			if(decisionSalida==1)
			{
				printf("Gracias, vuelva pronto");
			}
			else
			{
				printf("Gracias por quedarte");
			}
			break;

		default:
			printf("ERROR,ingrese una opcion valida (1,2,3,4,5,6,7,8,9,10");
			break;
		}

	}while(decisionSalida!=1);

}

