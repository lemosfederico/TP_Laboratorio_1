/*
 ============================================================================
 Name        : TP_[2].c
 Author      : Federico Lemos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "menu.h"
#include "arrayPassenger.h"
#define TAM 5

int main(void)
{
	setbuf(stdout,NULL);

	ePassenger list[TAM];

	int opcion;
	int opcionListar;
	char decisionSalida;
	char decisionSalidaListar;
	int flagSeguridad=0;

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
						if(sortPassengers(list,TAM,1)==0)
						{
							printf("\n      *** Lista de pasajeros ***    \n\n");
							if(printPassenger(list,TAM)==0)
							{
								printf("\n");
							}
						}
						break;

					case 2:
						informarTotalYPromedioPasajes(list,TAM);
						break;

					case 3:

						break;

					case 4:
						printf("Desea salir? (s/n): ");
						fflush(stdin);
						scanf("%c",&decisionSalidaListar);
						decisionSalidaListar=tolower(decisionSalidaListar);

						while (decisionSalidaListar!='s' && decisionSalidaListar!='n')
						{
							printf("ERROR,ingresa : (s o n): ");
							fflush(stdin);
							scanf("%c",&decisionSalidaListar);
							decisionSalidaListar = tolower(decisionSalidaListar);
						}

						if(decisionSalidaListar=='s')
						{
							printf("Gracias,vuelva pronto \n");
						}

						break;

					default:

						printf("OPCION INCORRECTA,por favor ingrese opciones numericas entre 1 y 4\n");

						break;
					}

				}while(decisionSalidaListar!='s');
			}
			break;

		case 5:
			flagSeguridad=1;
			hardcodearEstructura(list,TAM);

			break;

		case 6:

			printf("Desea salir? (s/n): ");
			fflush(stdin);
			scanf("%c",&decisionSalida);
			decisionSalida=tolower(decisionSalida);

			while (decisionSalida!='s' && decisionSalida!='n')
			{
				printf("ERROR,ingresa : (s o n): ");
				fflush(stdin);
				scanf("%c",&decisionSalida);
				decisionSalida = tolower(decisionSalida);
			}

			if(decisionSalida=='s')
			{
				printf("Gracias,vuelva pronto \n");
			}

			break;

		default:

			printf("OPCION INCORRECTA,por favor ingrese opciones numericas entre 1 y 6\n");
			break;
		}


	}while(decisionSalida!='s');


	return EXIT_SUCCESS;
}
