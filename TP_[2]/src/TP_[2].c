/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Federico Lemos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "menu.h"


int main(void)
{
	setbuf(stdout,NULL);

	ePassenger list[TAM];

	int opcion;
	int opcionListar;
	int decisionSalida;
	int decisionSalidaListar;
	int flagSeguridad=0;
	int orden;

	initPassengers(list,TAM);

	do
	{
		opcion=Menu();
		switch(opcion)
		{
		case 1:
			if(LoadOne(list,TAM)==0)
			{
				flagSeguridad=1;
				printf("\nSe dio de alta un pasajero con EXITO\n");
			}
			else
			{
				printf("ERROR, no se pudo dar de alta\n");
			}

			break;

		case 2:
			if(flagSeguridad==0)
			{
				printf("ERROR, no se puede modificar sin haber ingresado al menos uno\n");
			}
			else if(modifyPassenger(list,TAM)==0)
			{
				printf("\nSe modifico un pasajero con EXITO\n");
			}
			break;

		case 3:
			if(flagSeguridad==0)
			{
				printf("ERROR, no se puede dar de baja sin haber ingresado al menos uno\n");
			}
			else if(removerPasajero(list,TAM)==0)
			{
				printf("\nSe dio de baja un pasajero con EXITO\n");
			}
			break;

		case 4:
			if(flagSeguridad==0)
			{
				printf("ERROR, no se puede mostrar sin haber ingresado al menos uno\n");
			}
			else
			{
				do
				{
					opcionListar=SubMenuListar();
					switch(opcionListar)
					{
					case 1:
						orden=PedirEnteroMinMax("Como lo quiere ordenar? (1-ASCENDENTE / 0-DESCENDENTE): ", "ERROR,reintente", 0, 1);
						if(sortPassengers(list,TAM,orden)==0)
						{
							printf("\nSe ordeno con el criterio seleccionado\n");
							printPassengers(list,TAM);
						}
						else
						{
							printf("ERROR,no se pudo ordenar\n");
						}
						break;

					case 2:
						informarTotalYPromedioPasajes(list,TAM);
						break;

					case 3:
						orden=PedirEnteroMinMax("Como lo quiere ordenar? (1-ASCENDENTE / 0-DESCENDENTE): ", "ERROR,reintente", 0, 1);
						if(sortPassengersByCode(list, TAM, orden)==0)
						{
							printf("\nSe ordeno con el criterio seleccionado\n");
							printPassengers(list,TAM);
						}
						else
						{
							printf("ERROR,no se pudo ordenar\n");
						}
						break;

					case 4:
						decisionSalidaListar=MenuSalida();
						if(decisionSalidaListar==1)
						{
							printf("Gracias, Vuelva pronto\n");
						}
						break;

					default:
						printf("OPCION INCORRECTA,por favor ingrese opciones numericas entre 1 y 4\n");

						break;
					}

				}while(decisionSalidaListar!=1);
			}
			break;

		case 5:
			hardcodearEstructura(list,TAM);
			flagSeguridad=1;

			break;

		case 6:
			decisionSalida=MenuSalida();
			if(decisionSalida==1)
			{
				printf("Gracias, Vuelva pronto\n");
			}

			break;

		default:

			printf("OPCION INCORRECTA,por favor ingrese opciones numericas entre 1 y 6\n");
			break;
		}

	}while(decisionSalida!=1);


	return EXIT_SUCCESS;
}
