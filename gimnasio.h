#ifndef __GIMNASIO_H__
#define __GIMNASIO_H__

#include <stdlib.h>
#include <string.h>
#include "batallas.h"
#include "lista.h"
#include "heap.h"

#define MAX_NOMBRE 100
#define MAX_POKEMON 6
#define GIMNASIO 'G'
#define LIDER 'L'
#define ENTRENADOR 'E'
#define POKEMON 'P'

typedef struct pokemon{
    char nombre[MAX_NOMBRE];
    int ataque;
    int defensa;
    int velocidad;
    int evs;
}pokemon_t;

typedef struct entrenador{
    char tipo;
    char nombre[MAX_NOMBRE];
    lista_t* pokemon;
}entrenador_t;

typedef struct gimnasio{
    char nombre[MAX_NOMBRE];
    int dificultad;
    int id_funcion;
    lista_t*  entrenadores;
}gimnasio_t;


pokemon_t* pokemon_crear(char nombre[MAX_NOMBRE],int velocidad,int ataque,int defensa);

void pokemon_destruir(void* pokemon);



entrenador_t* entrenador_crear(char tipo,char nombre[MAX_NOMBRE]);

int entrenador_agregar_pokemon(entrenador_t* entrenador,pokemon_t* pokemon);

void entrenador_destruir(void* entrenador);


gimnasio_t* gimnasio_crear(char nombre[MAX_NOMBRE],int dificultad,int id_funcion_batalla);

/*
 * Comparador de elementos. Recibe dos elementos y devuelve:
 *    - 0 en caso de ser iguales, 
 *    - mayor a 0 si el primer gimnasio es mas dificil al segundo,
 *    - menor a 0 si el primer gimnasio es mas facil al segundo.
 */
int gimnasio_comparar_dificultades(void* gym_1,void* gym_2);

int gimnasio_insertar_entrenador(gimnasio_t* gimnasio,entrenador_t* entrenador);

void gimnasio_destruir(void* gimnasio);


#endif //__GIMNASIO_H__