/*
 * menu.h
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#ifndef MENU_H_
#define MENU_H_
#include "arrayPassenger.h"

/// @brief Es el menu principal para el inicio del programa
///
/// @return retorna la opcion elegida
int Menu();

/// @brief Es el menu que uso para seleccionar que quiere modificar
///
/// @return retorna la opcion elegida
int SubMenuModificar();

/// @brief Es el menu que uso para seleccionar que quiere listar
///
/// @return retorna la opcion elegida
int SubMenuListar();

/// @brief Es el menu que uso para seleccionar si quiere salir o no
///
/// @return retorna la opcion elegida
int MenuSalida();

#endif /* MENU_H_ */
