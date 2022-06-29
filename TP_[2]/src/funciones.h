/*
 * funciones.h
 *
 *  Created on: 1 may. 2022
 *      Author: feder
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#define TRUE 0//LIBRE
#define FALSE -1//OCUPADO
#define LEN 51
#define TAM 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "menu.h"

/// @brief Pide un entero al usuario
///
/// @param mensaje es el que uso para pedir el entero al usuario
/// @return retorna el numero ingresado
int PedirEntero(char mensaje[]);

/// @brief Pide un entero al usuario con un limite minimo y maximo
///
/// @param mensaje es el que uso para pedir el entero al usuario
/// @param min limite minimo que el usuario puede ingresar
/// @param max limite maximo que el usuario puede ingresar
/// @return retorna el numero ingresado
int PedirEnteroMinMax(char mensaje[],char mensajeError[],int min,int max);

/// @brief Pide un float al usuario
///
/// @param mensaje es el que uso para pedir el float al usuario
/// @return retorna el numero ingresado
float PedirFloat(char mensaje[]);

/// @brief Pide un float al usuario con un limite minimo y maximo
///
/// @param mensaje es el que uso para pedir el float al usuario
/// @param min limite minimo que el usuario puede ingresar
/// @param max limite maximo que el usuario puede ingresar
/// @return retorna el numero ingresado
float PedirFloatMinMax(char mensaje[],int min,int max);

/// @brief Valida que lo que se ingresa sea realmente un numero y no otra cosa
///
/// @param string uso esta variable para validar que sea un numero
/// @return TRUE si salio bien
int ValidarNumero(char string[]);

/// @brief Valida que lo que se ingresa sean realmente letras y no otra cosa
///
/// @param texto uso esta variable para validar que sean solo letras
/// @return TRUE si salio bien
int validarChar(char texto[]);

/// @brief Pide un string al usuario
///
/// @param mensaje es el que uso para pedir el string al usuario
/// @param stringIngresado uso esta variable para validar que el tamaño no sea mayor a 51
void PedirString(char mensaje[],char stringIngresado[]);

/// @brief Pide un string al usuario que sea con numeros y letras pero sin nada mas
///
/// @param mensaje es el que uso para pedir el string al usuario
/// @param stringIngresado uso esta variable para validar que el tamaño no sea mayor a 51
void PedirCodigoVuelo(char mensaje[],char stringIngresado[]);

/// @brief Pide una letra al usuario
///
/// @param mensaje es el que uso para pedir el entero al usuario
/// @return retorna la letra ingresada
char PedirLetra(char mensaje[]);

/// @brief Pide que el usuario elija una opcion para salir o no
///
/// @return retorna la opcion elegida
int Salida();

/// @brief Acomoda el string con la primera leta mayuscula
///
/// @param string uso esta variable para acomodar el string
void EmprolijarString(char string[]);



#endif /* FUNCIONES_H_ */
