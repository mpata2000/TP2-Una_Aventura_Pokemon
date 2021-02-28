#ifndef __INTERFAZ_H__
#define __INTERFAZ_H__

#include <stdio.h>
#include "aventura_pokemon.h"


void mostrar_menu_inicio(juego_t* juego);


void info_cargar_personaje();

void mostrar_error_carga_personaje();


void info_cargar_gimnasio();


void mostrar_menu_gimnasio(juego_t* juego);


void mostrar_batalla(juego_t* juego,pokemon_t* pkm_jugador,pokemon_t* pkm_entrenador);


void mostrar_menu_derrota(juego_t* juego);


void mostrar_menu_victoria(juego_t* juego);


void pantalla_maestro_pokemon(juego_t* juego);

#endif // __INTERFAZ_H__