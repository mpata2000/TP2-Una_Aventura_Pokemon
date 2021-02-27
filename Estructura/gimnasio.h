#ifndef __GIMNASIO_H__
#define __GIMNASIO_H__


#include <string.h>
#include "pokemon.h"
#include "./batallas.h"
#include "../TDAs/lista.h"

#define MAX_NOMBRE 100
#define MAX_POKEMON_ENTRENADOR 6
#define GIMNASIO 'G'
#define LIDER 'L'
#define ENTRENADOR 'E'
#define POKEMON 'P'
#define MAX_FUNCIONES_BATALLA 5 



typedef int (* funcion_batalla)(void*, void *);

typedef struct entrenador{
    char tipo;
    char nombre[MAX_NOMBRE];
    lista_t* pokemon;
}entrenador_t;

typedef struct gimnasio{
    char nombre[MAX_NOMBRE];
    int dificultad;
    funcion_batalla funcion_batalla;
    lista_t*  entrenadores;
}gimnasio_t;


/***************************/
/*   FUNCIONES ENTRENDOR   */
/***************************/

entrenador_t* entrenador_crear(char tipo,char nombre[MAX_NOMBRE]);

int entrenador_agregar_pokemon(entrenador_t* entrenador,pokemon_t* pokemon);

size_t entrenador_cantidad_pokemon(entrenador_t* entrenador);

pokemon_t* entrenador_pokemon(entrenador_t* entrenador,size_t pos);

void entrenador_destruir(void* entrenador);


/***************************/
/*   FUNCIONES GIMNASIO    */
/***************************/

gimnasio_t* gimnasio_crear(char nombre[MAX_NOMBRE],int dificultad,int id_funcion_batalla);

/*
 * Comparador de elementos. Recibe dos elementos y devuelve:
 *    - 0 en caso de ser iguales, 
 *    - mayor a 0 si el primer gimnasio es mas dificil al segundo,
 *    - menor a 0 si el primer gimnasio es mas facil al segundo.
 */
int gimnasio_comparar_dificultades(void* gym_1,void* gym_2);


int gimnasio_insertar_entrenador(gimnasio_t* gimnasio,entrenador_t* entrenador);

entrenador_t* gimnasio_entrenador_a_pelear(gimnasio_t* gimnasio);

char gimnasio_tipo_entrenador(gimnasio_t* gimnasio);

size_t gimnasio_entrenadores_restantes(gimnasio_t* gimnasio);

int gimnasio_sacar_ultimo_entrenador(gimnasio_t* gimnasio);

void gimnasio_destruir(void* gimnasio);


#endif //__GIMNASIO_H__