/*
 * arrayPassenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#include "funciones.h"

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFly;
	int isEmpty;
}ePassenger;

/**
 * @brief Inicializo todo en 0
 *
 * @param passenger passenger le paso la estructura de pasajeros
 * @param len tamanio la estructura
 * @return retorno 0 si salio todo bien
 */
int initPassengers(ePassenger passenger[],int len);
/**
 * @brief Buscar un lugar libre

 * @param passenger le paso la estructura de pasajeros
 * @param len tamanio la estructura
 * @return retorno 0 si salio todo bien
 */

int SearchFree(ePassenger passenger[],int tam);
/**
 *
 * @param list le paso la lista de pasajeros para cargar uno
 * @param len tamanio la estructura
 * @return retorno 0 si salio todo bien
 */
int LoadOne(ePassenger list[],int len);
/**
 * @brief Carga un pasajero en el lugar libre que haya disponible
 *
 * @param list le paso la lista de pasajeros para agregar uno
 * @param len tamanio la estructura
 * @param id llamo a la funcion GetId() que autoincrementa de 1 en 1
 * @param name pido el nombre
 * @param lastName pido el apellido
 * @param price pido el precio
 * @param typePassenger pido el tipo de pasajero
 * @param flycode pido el codigo de vuelo
 * @return retorno 0 si salio todo bien
 */
int addPassenger(ePassenger list[],int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[],int statusFly);
/**
 * @brief Busca un pasajero por ID que le pido al usuario
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 * @param id pido un id para buscar
 * @return retorno 0 si salio todo bien
 */
int findPassengerById(ePassenger list[],int len,int id);
/**
 * @brief Modifico un pasajero que coincida con el ID que me ingresa el usuario
 *
 * @param list le paso la lista de pasajeros
 * @param tam tamanio la estructura
 * @return retorno 0 si salio todo bien
 */
int modifyPassenger(ePassenger list[],int tam);
/**
 * @brief Pido un ID y le paso el valor en esa posicion a VACIO cuando lo encuentro
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 * @param id pido un id para remover
 * @return retorno 0 si salio todo bien
 */
int removePassenger(ePassenger list[],int len,int id);
/**
 * @brief Muestro un pasajero
 *
 * @param passenger le paso la lista de pasajeros
 */
void PrintPassenger(ePassenger passenger);
/**
 * @brief Muestra todos los pasajeros que esten cargados
 *
 * @param list le paso la lista de pasajeros
 * @param length tamanio la estructura
 * @return retorno 0 si salio todo bien
 */
int printPassengers(ePassenger list[], int length);
/**
 * @brief Ordeno los pasajeros por Apellido y Tipo de pasajero
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 * @param order esta variable me da la consigna de como ordenarlos
 * @return retorno 0 si salio todo bien
 */
int sortPassengers(ePassenger list[], int len, int order);

int sortPassengersByCode(ePassenger list[], int len, int order);

/**
 * @brief Remuevo un pasajero
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 * @return retorno 0 si salio todo bien
 */
int removerPasajero(ePassenger list[],int len);
/**
 * @brief Hardcodeo la estructura para usarla en el case 5
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 * @return retorno 0 si salio todo bien
 */
int hardcodearEstructura(ePassenger list[],int len);
/**
 * @brief Busco el precio total de pasajeros y el promedio
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 * @param cantidadPasajeros es la cantidad total de pasajeros
 * @return retorno 0 si salio todo bien
 */
int getTotalPrecioPasajeros(ePassenger list[],int len,int* cantidadPasajeros);
/**
 * @brief Informa el total y promedio de los precios de los pasajes
 *
 * @param list le paso la lista de pasajeros
 * @param len tamanio la estructura
 */
void informarTotalYPromedioPasajes(ePassenger list[],int len);

/// @brief Es un menu para modificar al pasajero
///
/// @return retorna la opcion elegida
int ModificarPasajero();

/// @brief Es un menu para elegir el tipo de  pasajero
///
/// @return retorna la opcion elegida
int TipoPasajero();

/// @brief printea el tipo de pasajero reemplazando el int por el string que corresponda
///
/// @param list es la estructura para printear
void PrintTypePassenger(ePassenger list);

/// @brief Es un menu para elegir el estado de vuelo
///
/// @return retorna la opcion elegida
int EstadoVuelo();

/// @brief printea el estado de vuelo reemplazando el int por el string que corresponda
///
/// @param list es la estructura para printear
void PrintEstadoVuelo(ePassenger list);

#endif /* ARRAYPASSENGER_H_ */
