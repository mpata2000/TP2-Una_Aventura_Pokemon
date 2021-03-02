#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__

#include <stdio.h>
#include "../Estructura/aventura_pokemon.h"
#include "../Utiles/ANSI-color-codes.h"
#include "ascii_pokemon.h"


void pantalla_de_carga(const char* mensaje);
/*
 * Muestra un Pantalla de carga al inicio del juego
*/
void mostrar_carga_juego();

/*
 * Muestra el menu Incio
*/
void mostrar_menu_inicio(juego_t* juego);


void info_cargar_personaje();


void mostrar_error_carga_personaje();


void info_cargar_gimnasio();

/*
 * Muestra el menu Incio
*/
void mostrar_menu_gimnasio(juego_t* juego);

/*
 * Muestra una batalla pokemon entre dos entrenadores
*/
void mostrar_batalla(juego_t* juego,pokemon_t* pkm_jugador,pokemon_t* pkm_entrenador,int ganador);

/*
 * Muestra el menu derrota
*/
void mostrar_menu_derrota(juego_t* juego);

/*
 * Muestra el menu Victoria
*/
void mostrar_menu_victoria(juego_t* juego);


void pantalla_maestro_pokemon(juego_t* juego);


void mostrar_pantalla_derrota(juego_t* juego);

/*
 * Imprime un easter egg
*/
void easter_egg();

#endif // __INTERFAZ_H__