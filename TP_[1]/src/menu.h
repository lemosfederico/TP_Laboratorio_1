/*
 * menu.h
 *
 *  Created on: 12 abr. 2022
 *      Author: feder
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * \brief Esta funcion me muestra el menu con las 6 opciones para que ingrese el usuario
 *
 * \param kilometros, Son los kilometros ingresados que le paso por parametro para ir mostrando lo que se ingresa en el menu
 * \param precioVueloAerolineas, Es el precio que le paso por parametros para ir mostrando lo que se ingresa en el menu
 * \param precioVueloLatam, Es el precio que le paso por parametros para ir mostrando lo que se ingresa en el menu
 * \return retorna un int que es la opcion elegida por el usuario
 */
int Menu(float kilometros,float precioVueloAerolineas,float precioVueloLatam);
/**
 * \brief Esta funcion muestra el Submenu con las 3 opciones del case 2 donde se ingresa el precio de
 * 		  vuelo aerolineas o latam para que ingrese el usuario
 *
 * \return retorna un int que es la opcion elegida por el usuario
 */
int SubMenu();

#endif /* MENU_H_ */
