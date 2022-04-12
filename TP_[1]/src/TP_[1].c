/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Federico Lemos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"
#include "menu.h"

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int SubOpcion;
	int banderaKilometros = 0;
	int banderaPrecioAerolineas = 0;
	int banderaPrecioLatam = 0;
	float kilometros;
	float precioVueloAerolineas;
	float precioVueloLatam;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferencia;
	char desicionSalida;
	char desicionSalidaSeleccion;

	do
	{
		opcion=Menu(kilometros,precioVueloAerolineas,precioVueloLatam);
		switch (opcion)
		{
		case 1:
			//system("cls");
			printf("Ingresa kilometros: ");
			scanf("%f",&kilometros);
			banderaKilometros=1;
			break;
		case 2:
			if(banderaKilometros==0)
			{
				printf("ERROR,no se ingresaron kilometros,reintentar\n");
			}
			else
			{
				SubOpcion=SubMenu();
				switch(SubOpcion)
				{
				case 1:
					//system("cls");
					printf("Ingresar precio vuelo Aerolineas: \n");
					scanf("%f",&precioVueloAerolineas);
					banderaPrecioAerolineas=1;

					break;
				case 2:
					//system("cls");
					printf("Ingresar precio vuelo Latam: \n");
					scanf("%f",&precioVueloLatam);
					banderaPrecioLatam=1;

					break;

				case 3:

					printf("Estas seguro de salir ? (s o n): ");
					fflush(stdin);
					scanf("%c",&desicionSalidaSeleccion);
					desicionSalidaSeleccion=tolower(desicionSalidaSeleccion);

					while(desicionSalidaSeleccion!='s' && desicionSalidaSeleccion!='n')
					{
						printf("ERROR,ingresa : (s o n): ");
						fflush(stdin);
						scanf("%c",&desicionSalidaSeleccion);
						desicionSalidaSeleccion=tolower(desicionSalidaSeleccion);
					}

					if (desicionSalidaSeleccion=='s')
					{
						printf("Ha salido de la seleccion de ingresar precio vuelo\n\n");
					}
					else
					{
						opcion=1;
					}

					break;

				default:

					break;

				} // De aca para abajo continua el primer switch de opcion

			}

			break;

		case 3:

			if(banderaPrecioAerolineas==0)
			{
				printf("ERROR,Debe ingresar precio de aerolineas\n\n");
			}
			else if(banderaPrecioLatam==0)
			{
				printf("ERROR,Debe ingresar precio de Latam\n\n");
			}
			else
			{
				precioDebitoAerolineas = PrecioDebito(precioVueloAerolineas);
				precioDebitoLatam = PrecioDebito(precioVueloLatam);
				precioCreditoAerolineas = PrecioCredito(precioVueloAerolineas);
				precioCreditoLatam = PrecioCredito(precioVueloLatam);
				precioBitcoinAerolineas = PrecioBitcoin(precioVueloAerolineas);
				precioBitcoinLatam = PrecioBitcoin(precioVueloLatam);
				precioUnitarioAerolineas = PrecioPorKilometro(precioVueloAerolineas, kilometros);
				precioUnitarioLatam = PrecioPorKilometro(precioVueloLatam,kilometros);
				diferencia = PrecioDiferencia(precioVueloAerolineas,precioVueloLatam);

				printf("Se calcularon los costos\n\n");
			}

			break;

		case 4:

			if(banderaKilometros==0 && banderaPrecioAerolineas ==0 && banderaPrecioLatam ==0)
			{
				printf("ERROR,Debe ingresar kilometros, precio de aerolineas y precio de latam para poder informar los resultados\n\n");
			}
			else
			{
				MostrarResultados(precioDebitoAerolineas, precioDebitoLatam,
						precioCreditoAerolineas, precioCreditoLatam,
						precioBitcoinAerolineas, precioBitcoinLatam,
						precioUnitarioAerolineas, precioUnitarioLatam,
						diferencia);
			}

			break;

		case 5:

			kilometros = 7090;
			precioVueloAerolineas = 162965;
			precioVueloLatam = 159339;

			precioDebitoAerolineas = PrecioDebito(precioVueloAerolineas);
			precioDebitoLatam = PrecioDebito(precioVueloLatam);
			precioCreditoAerolineas = PrecioCredito(precioVueloAerolineas);
			precioCreditoLatam = PrecioCredito(precioVueloLatam);
			precioBitcoinAerolineas = PrecioBitcoin(precioVueloAerolineas);
			precioBitcoinLatam = PrecioBitcoin(precioVueloLatam);
			precioUnitarioAerolineas = PrecioPorKilometro(precioVueloAerolineas,kilometros);
			precioUnitarioLatam = PrecioPorKilometro(precioVueloLatam,kilometros);
			diferencia = PrecioDiferencia(precioVueloAerolineas,precioVueloLatam);

			MostrarResultadosHardCodeados(precioDebitoAerolineas,
					precioDebitoLatam, precioCreditoAerolineas,
					precioCreditoLatam, precioBitcoinAerolineas,
					precioBitcoinLatam, precioUnitarioAerolineas,
					precioUnitarioLatam, diferencia, kilometros,
					precioVueloAerolineas, precioVueloLatam);

			break;

		case 6:

			printf("Estas seguro de salir ? (s o n): ");
			fflush(stdin);
			scanf("%c",&desicionSalida);
			desicionSalida = tolower(desicionSalida);

			while (desicionSalida!='s' && desicionSalida!='n')
			{
				printf("ERROR,ingresa : (s o n): ");
				fflush(stdin);
				scanf("%c",&desicionSalida);
				desicionSalida = tolower(desicionSalida);
			}

			if(desicionSalida=='s')
			{
				printf("Gracias,vuelva pronto \n");
			}
			else
			{
				opcion=1;
			}

			break;

		default:

			break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
