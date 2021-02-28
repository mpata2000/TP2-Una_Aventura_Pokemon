#ifndef __PERSONAJE_H__
#define __PERSONAJE_H__

#include "pokemon.h"

#define MAX_POKEMON_PARTY 6

typedef struct personaje{
    char nombre[MAX_NOMBRE];
    pokemon_t* party[MAX_POKEMON_PARTY];
    lista_t* pokemon_obtenidos;
}personaje_t;

/*
 * Reserva la memoria necesaria del personaje y le asigna el nombre recivido
 * Si hay un error devuelve NULL
*/
personaje_t* personaje_crear(char nombre[MAX_NOMBRE]);

/*
 * Recibe un personaje valido y dos numeros
 *    -> num_pkm_party es la posicion del pokemon que se quiere sacar(Tiene que ser meno a 6)
 *    -> num_pkm_obteni es la posicion del pokemon que se quiere poner en la party
 * Cambia los Pokemon solo si el Pokemon no esta ya en la party
 * Devuevle 0 en caso de que el cambio e exitoso o -1 en caso de ERROR
*/
int personaje_cambiar_pokemon(personaje_t* personaje,size_t num_pkm_party,size_t num_pkm_obtenido);

/*
 * Muestra un personaje valido y todo sus Pokemon
*/
void personaje_mostrar(personaje_t* personaje);

/*
 * Recibe un personaje y un Pokemon validos
 * Agrega el pokemon al personaje
 * Si el jugador tiene menos de 6 jugadores el Pokemon tambien se agrega a la party
 * Si tuvo exito devuelve 0 de lo contrario devuelve -1
*/
int personaje_agregar_pokemon(personaje_t* personaje,pokemon_t* pokemon);

/*
 * Recibe un personaje_t valido
 * Devuelve la cantidad de pokemones que tiene.
*/
size_t personaje_cantidad_pokemon(personaje_t* personaje);

/*
 * Recibe un personaje valido y la posicion del pokemon en la party
 * Devuelve el Pokemon en esa posicion de la party o en caso de error NULL
*/
pokemon_t* personaje_pokemon_party(personaje_t* personaje,size_t pos);

/*
 * Libera la memoria reservada por el personaje
*/
void personaje_destruir(personaje_t* personaje);



#endif /* __PERSONAJE_H__ */