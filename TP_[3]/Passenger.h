/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[50];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellido,char* codigo,char* precio,char* estado);

void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estado);
int Passenger_getEstadoVuelo(Passenger* this,char* estado);

/// @brief recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y compara nombres
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar o la diferencia entre nombres
int Passenger_CompareByNombre(void* p1,void* p2);
/// @brief recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y compara ids
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar 1 si el p1 es mas grande que el p2 y -1 si p1 es mas chico que p2
int Passenger_CompareById(void* p1,void* p2);
/// @brief recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y compara apellidos
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar o la diferencia entre apellidos
int Passenger_CompareByApellido(void* p1,void* p2);
/// @brief recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y compara precios
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar 1 si el p1 es mas grande que el p2 y -1 si p1 es mas chico que p2
int Passenger_CompareByprecio(void* p1,void* p2);
/// @brief recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y compara tipo de pasajero
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar o la diferencia entre tipo de pasajero
int Passenger_CompareByTipoPasajero(void* p1,void* p2);
/// @brief recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y codigo de vuelo
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar o la diferencia entre codigo de vuelo
int Passenger_CompareByCodigoVuelo(void* p1,void* p2);
/// @brief  recibe como parametros dos punteros genericos que admiten cualquier tipo de elemento y estado de vuelo
///
/// @param p1 primer elemento a comparar
/// @param p2 segundo elemento a comparar
/// @return retorna 0 sino hay que cambiar o la diferencia entre estado de vuelo
int Passenger_CompareByEstadoVuelo(void* p1,void* p2);
/// @brief recibe como parametro un puntero a pasajero y lo imprime
///
/// @param unPasajero puntero a pasajero
void Passenger_printOne(Passenger* unPasajero);

#endif /* PASSENGER_H_ */
