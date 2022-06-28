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
	int banderaCalculos=0;
	float kilometros=0;
	float precioVueloAerolineas=0;
	float precioVueloLatam=0;
	float precioDebitoAerolineas;
	float precioDebitoLatam;
	float precioCreditoAerolineas;
	float precioCreditoLatam;
	float precioBitcoinAerolineas;
	float precioBitcoinLatam;
	float precioUnitarioAerolineas;
	float precioUnitarioLatam;
	float diferencia;
	int decisionSalida;
	int decisionSalidaSeleccion;

	do
	{
		opcion=Menu(kilometros,precioVueloAerolineas,precioVueloLatam);
		switch (opcion)
		{
		case 1:
			do
			{
				kilometros=PedirFloatMinMax("Ingrese un valor mayor a 0 para los kilometros: ", 1, 999999);
			}while(kilometros<0);
			banderaKilometros=1;

			break;
		case 2:
			if(banderaKilometros==0)
			{
				printf("\nERROR,no se ingresaron kilometros,reintentar\n");
			}
			else
			{
				SubOpcion=SubMenu();
				switch(SubOpcion)
				{
				case 1:
					do
					{
						precioVueloAerolineas=PedirFloatMinMax("\nIngrese un valor mayor a 0 como precio de vuelo de aerolineas: ",1,9999999);
					}while(precioVueloAerolineas<0);
					banderaPrecioAerolineas=1;

					break;

				case 2:
					do
					{
						precioVueloLatam=PedirFloatMinMax("\nIngrese un valor mayor a 0 como precio de vuelo de Latam: ",1,9999999);
					}while(precioVueloLatam<0);
					banderaPrecioLatam=1;

					break;
				case 3:

					decisionSalidaSeleccion=MenuSalida();
					if(decisionSalidaSeleccion==1)
					{
						printf("Gracias vuelva pronto\n");
					}
					else
					{
						SubOpcion=SubMenu();
					}
					break;
				}
			}

			break;

		case 3:
			if(banderaPrecioAerolineas==0 || banderaPrecioLatam==0)
			{
				printf("\nERROR,Debe ingresar ambos precios para realizar los calculos\n\n");
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
				banderaCalculos=1;

				printf("Se calcularon los costos\n\n");
			}

			break;

		case 4:

			if(banderaCalculos==0)
			{
				printf("\nERROR,Debe ingresar kilometros, ambos precios y calcularlos para poder informar los resultados\n\n");
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
			decisionSalida=MenuSalida();
			if((decisionSalida)==1)
			{
				printf("\nGracias,vuelva pronto\n");
			}

			break;
		}

	}while(decisionSalida!=1);

	return EXIT_SUCCESS;
}
