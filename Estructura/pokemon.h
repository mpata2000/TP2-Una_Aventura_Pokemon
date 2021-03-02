#ifndef __POKEMON_H__
#define __POKEMON_H__

#include <stdlib.h>
#include "../TDAs/lista.h"


#define MAX_NOMBRE 100
#define MAX_EVS 63

typedef struct pokemon{
    char nombre[MAX_NOMBRE];
    int ataque;
    int defensa;
    int velocidad;
    int evs;
    bool shiny;
}pokemon_t;


/*
 * Crea y reserva la memoria de un pokemon con los stats recividos 
 * Devuelve un puntero al Pokemon creado o NULL en caso de error.
*/
pokemon_t* pokemon_crear(char nombre[MAX_NOMBRE],int velocidad,int ataque,int defensa);

/*
 * Recibe un pokemon valido
 * Copia al pokemon recivido y reserva la memoria de un pokemon igual
 * Devuelve un puntero al Pokemon creado o NULL en caso de error.
*/
pokemon_t* pokemon_recrear(pokemon_t* pokemon);

/*
 * Recibe un Pokemon valido y si es posible aumenta su evs(Maximo de 63)
*/
void pokemon_aumentrar_evs(pokemon_t* pokemon);

/*
 * Recibe un Pokemon y devuelve su nombre
*/
char* pokemon_nombre(pokemon_t* pokemon);

/*
 * Recibe un Pokemon y devuelve su ataque
 * En caso de no recivir un Pokemon valido devuelve 0
*/
int pokemon_ataque(pokemon_t* pokemon);

/*
 * Recibe un Pokemon y devuelve su defensa
 * En caso de no recivir un Pokemon valido devuelve 0
*/
int pokemon_defensa(pokemon_t* pokemon);

/*
 * Recibe un Pokemon y devuelve su velocidad
 * En caso de no recivir un Pokemon valido devuelve 0
*/
int pokemon_velocidad(pokemon_t* pokemon);

/*
 * Recibe una lista de Pokemon y las imprime por pantalla
*/
void pokemon_mostrar(lista_t* pokemon);

/*
 * Libera la memoria almcenada por un Pokemon
*/
void pokemon_destruir(void* pokemon);

#endif /*__POKEMON_H__*/