/*
 * funciones.h
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief Pide entero, lo valida y lo devuelve
///
/// @param mensaje muestra un mensaje para pedir el numero
/// @param max es una variable que uso para poner un limite en el maximo ingresado
/// @param min es una variable que uso para poner un limite en el minimo ingresado
/// @return retorna el numero validado
int PedirEntero(char mensaje[],int max,int min);
/// @brief Pide float, lo valida y lo devuelve
///
/// @param mensaje muestra un mensaje para pedir el numero
/// @param min es una variable que uso para poner un limite en el minimo ingresado
/// @return retorna el numero validado
float PedirFloat(char mensaje[],int min);
/// @brief Pide un string, lo valida y lo devuelve
///
/// @param mensaje muestra un mensaje para pedir el string
/// @param stringIngresado es el string ingresado que uso para validar
void PedirString(char mensaje[],char stringIngresado[]);
/// @brief Valida que el numero sea realmente un numero y no sean letras
///
/// @param aux lo uso para recibir lo ingresado como char y de esta forma lo puedo controlar y validar que sean solo numeros
/// @return retorna 1 si se pudo validar y -1 si se ingresaron letras en vez de numeros
int ValidarEntero(char aux[]);

#endif /* FUNCIONES_H_ */
