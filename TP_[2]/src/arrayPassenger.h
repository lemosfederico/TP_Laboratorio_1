/*
 * arrayPassenger.h
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
}ePassenger;

/**
 * @brief Inicializo todo en 0
 *
 * @param passenger passenger le paso la estructura de pasajeros
 * @param len tamaño la estructura
 * @return retorno 0 si salio todo bien
 */
int initPassengers(ePassenger passenger[],int len);
/**
 * @brief Buscar un lugar libre

 * @param passenger le paso la estructura de pasajeros
 * @param len tamaño la estructura
 * @return retorno 0 si salio todo bien
 */

int SearchFree(ePassenger passenger[],int tam);
/**
 *
 * @param list le paso la lista de pasajeros para cargar uno
 * @param len tamaño la estructura
 * @return retorno 0 si salio todo bien
 */
int LoadOne(ePassenger list[],int len);
/**
 * @brief Carga un pasajero en el lugar libre que haya disponible
 *
 * @param list le paso la lista de pasajeros para agregar uno
 * @param len tamaño la estructura
 * @param id llamo a la funcion GetId() que autoincrementa de 1 en 1
 * @param name pido el nombre
 * @param lastName pido el apellido
 * @param price pido el precio
 * @param typePassenger pido el tipo de pasajero
 * @param flycode pido el codigo de vuelo
 * @return retorno 0 si salio todo bien
 */
int addPassenger(ePassenger list[],int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/**
 * @brief Busca un pasajero por ID que le pido al usuario
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
 * @param id pido un id para buscar
 * @return retorno 0 si salio todo bien
 */
int findPassengerById(ePassenger list[],int len,int id);
/**
 * @brief Modifico un pasajero que coincida con el ID que me ingresa el usuario
 *
 * @param list le paso la lista de pasajeros
 * @param tam tamaño la estructura
 * @return retorno 0 si salio todo bien
 */
int modifyPassenger(ePassenger list[],int tam);
/**
 * @brief Pido un ID y le paso el valor en esa posicion a VACIO cuando lo encuentro
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
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
 * @param length tamaño la estructura
 * @return retorno 0 si salio todo bien
 */
int printPassenger(ePassenger list[], int length);
/**
 * @brief Ordeno los pasajeros por Apellido y Tipo de pasajero
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
 * @param order esta variable me da la consigna de como ordenarlos
 * @return retorno 0 si salio todo bien
 */
int sortPassengers(ePassenger list[], int len, int order);
/**
 * @brief Pido un Id para poder remover
 *
 * @return retorno 0 si salio todo bien
 */
int pedirIdPasajero();
/**
 * @brief Remuevo un pasajero
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
 * @return retorno 0 si salio todo bien
 */
int removerPasajero(ePassenger list[],int len);
/**
 * @brief Hardcodeo la estructura para usarla en el case 5
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
 * @return retorno 0 si salio todo bien
 */
int hardcodearEstructura(ePassenger list[],int len);
/**
 * @brief Busco el precio total de pasajeros y el promedio
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
 * @param cantidadPasajeros es la cantidad total de pasajeros
 * @return retorno 0 si salio todo bien
 */
int getTotalPrecioPasajeros(ePassenger list[],int len,int* cantidadPasajeros);
/**
 * @brief Informa el total y promedio de los precios de los pasajes
 *
 * @param list le paso la lista de pasajeros
 * @param len tamaño la estructura
 */
void informarTotalYPromedioPasajes(ePassenger list[],int len);


#endif /* ARRAYPASSENGER_H_ */
