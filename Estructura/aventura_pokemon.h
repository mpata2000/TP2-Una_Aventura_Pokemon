#ifndef __AVENTURA_POKEMON_H__
#define __AVENTURA_POKEMON_H__

#include "Estructura/gimnasio.h"
#include "Estructura/personaje.h"
#include "Archivos/archivos.h"
#include "TDAs/heap.h"



typedef struct juego{
    heap_t* gimnasios;
    gimnasio_t* gimnasio_actual;
    personaje_t* personaje;
    bool simular;
}juego_t;


/*
 * Reserva la memoria de un juego 
 * Devuelve un puntero al entrenador creado o NULL en caso de error.
*/
juego_t* crear_juego();

/*
 * Recibe un juego y chequea que sea valido
 * Devuelve true cuando los gimnasios y el personaje son distintos de NULL
*/
bool juego_valido(juego_t* juego);

/*
 * Libera la memoria almacenada por un juego
*/
void destruir_juego(juego_t* juego);

/*
 * Recibe un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_gimnasio(juego_t* juego);

/*
 * Recibe un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_personaje(juego_t* juego);


/*
 * Recibe un juego valido
 * Pelea contra el proximo entrenador planeado
 * Si pierde gana el personaje devuelve true
 * En el caso contrario devuelve false
*/
bool batalla(juego_t* juego);

/*
 * Recibe un juego valido
 * Si es posible va a tomar un Pokemon del Lider del gimnasio
 * En caso de exito o error se le informa al usuario por pantalla
*/
void tomar_pokemon(juego_t* juego);

/*
 * Recibe un juego valido
 * Si es posible cambia los pokemon de la party
 * En caso de exito o error se le informa al usuario por pantalla 
*/
void cambiar_pokemon(juego_t* juego);


#endif /*__AVENTURA_POKEMON_H__*/