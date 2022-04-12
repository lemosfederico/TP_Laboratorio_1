/*
 * header.h
 *
 *  Created on: 11 abr. 2022
 *      Author: feder
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/**
 * \brief Esta funcion hace la cuenta del precio pagando con debito
 *
 * \param precio, Es el precio que le paso por parametro para hacer la cuenta
 * \return retorna un float que es el precio con el 10% de descuento
 */
float PrecioDebito(float precio);
/**
 * \brief Esta funcion hace la cuenta del precio pagando con credito
 *
 * \param precio, Es el precio que le paso por parametro para hacer la cuenta
 * \return retorna un float que es el precio con el 25% de interes
 */
float PrecioCredito(float precio);
/**
 * \brief Esta funcion hace la cuenta del precio pagando con Bitcoin
 *
 * \param precio, Es el precio que le paso por parametro para hacer la cuenta
 * \return retorna un float que es el precio pagando con Bitcoin, 1 BTC > 4606954.55 pesos argentinos
 */
float PrecioBitcoin(float precio);
/**
 * \brief Esta funcion hace la cuenta del precio que se paga por kilometro
 *
 * \param precio, Es el precio que le paso por parametro para hacer la cuenta
 * \param kilometros, Son los kilometros ingresados que le paso por parametro para hacer la cuenta
 * \return retorna un float que es el precio que se paga por kilometro
 */
float PrecioPorKilometro(float precio,float kilometros);
/**
 * \brief Esta funcion hace la cuenta de la diferencia entre el precio de vuelos aerolineas y el precio de vuelos latam
 *
 * \param precioAerolineas, Es el precio que le paso por parametro para hacer la cuenta
 * \param precioLatam, Es el precio que le paso por parametro para hacer la cuenta
 * \return retorna un float que es la diferencia entre el precio de vuelos aerolineas y el precio de vuelos latam
 */
float PrecioDiferencia(float precioAerolineas,float precioLatam);
/**
 * \brief Esta funcion muestra los resultados de todas las operaciones realizadas anteriormente
 *
 * \param precioDebitoAerolineas, Es el precio que le paso para mostrar
 * \param precioDebitoLatam, Es el precio que le paso para mostrar
 * \param precioCreditoAerolineas, Es el precio que le paso para mostrar
 * \param precioCreditoLatam, Es el precio que le paso para mostrar
 * \param precioBitcoinAerolineas, Es el precio que le paso para mostrar
 * \param precioBitcoinLatam, Es el precio que le paso para mostrar
 * \param precioUnitarioAerolineas, Es el precio que le paso para mostrar
 * \param precioUnitarioLatam, Es el precio que le paso para mostrar
 * \param diferencia, Es la diferencia que le paso para mostrar
 */
void MostrarResultados(float precioDebitoAerolineas,float precioDebitoLatam
						,float precioCreditoAerolineas,float precioCreditoLatam,float precioBitcoinAerolineas,float precioBitcoinLatam
						,float precioUnitarioAerolineas,float precioUnitarioLatam,float diferencia);
/**
 * \brief Esta funcion muestra los resultados hardcodeados que pide el menu en la opcion 5
 *
 * \param precioDebitoAerolineas, Es el precio que le paso para mostrar
 * \param precioDebitoLatam, Es el precio que le paso para mostrar
 * \param precioCreditoAerolineas, Es el precio que le paso para mostrar
 * \param precioCreditoLatam, Es el precio que le paso para mostrar
 * \param precioBitcoinAerolineas, Es el precio que le paso para mostrar
 * \param precioBitcoinLatam, Es el precio que le paso para mostrar
 * \param precioUnitarioAerolineas, Es el precio que le paso para mostrar
 * \param precioUnitarioLatam, Es el precio que le paso para mostrar
 * \param diferencia, Es la diferencia que le paso para mostrar
 * \param kilometros, Estos son los kilometros (7090) que pide la consigna que hardcodee para que haga las cuentas en base a esos KM
 * \param precioVueloAerolineas, Es el precio de vuelos aerolineas (162965) que pide la consigna que hardcodee para que haga las cuentas
 * \param precioVueloLatam, Es el precio de vuelos latam (159339) que pide la consigna que hardcodee para que haga las cuentas
 */

void MostrarResultadosHardCodeados(float precioDebitoAerolineas,float precioDebitoLatam
						,float precioCreditoAerolineas,float precioCreditoLatam,float precioBitcoinAerolineas,float precioBitcoinLatam
						,float precioUnitarioAerolineas,float precioUnitarioLatam,float diferencia,float kilometros
						,float precioVueloAerolineas,float precioVueloLatam);


#endif /* FUNCIONES_H_ */
