/*
 * menu.h
 *
 *  Created on: 27 abr. 2022
 *      Author: feder
 */

#ifndef MENU_H_
#define MENU_H_
#include "menu.h"
#include "funciones.h"


/// @brief muestra el menu principal
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int Menu();
/// @brief muestra el menu de modificar
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int SubMenuModificar();
/// @brief muestra el menu de listar
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int SubMenuListar();
/// @brief muestra el menu de salir
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int MenuSalida();
/// @brief muestra el menu de tipo de pasajero para modificarlo
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int SubmenuTipoPasajero();
/// @brief muestra el menu de estado de vuelo para modificarlo
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int SubMenuEstadoVuelo();
/// @brief muestra el menu de orden para elegir la opcion de como ordenar
///
/// @return retorna el numero ingresado para entrar en el case correspondiente
int MenuOrden();

#endif /* MENU_H_ */
