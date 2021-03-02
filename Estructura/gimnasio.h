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
    bool pokemon_tomado;
    funcion_batalla funcion_batalla;
    lista_t*  entrenadores;
}gimnasio_t;


/***************************/
/*   FUNCIONES ENTRENDOR   */
/***************************/

/*
 * Crea y reserva la memoria de un entrenador con los parametros recividos 
 * Devuelve un puntero al entrenador creado o NULL en caso de error.
*/
entrenador_t* entrenador_crear(char tipo,char nombre[MAX_NOMBRE]);


/*
 * Recibe un entrenador y un Pokemon validos
 * Agrega el pokemon al entrnador meintras que tenga menos de 6 Pokemon
 * Si tuvo exito devuelve 0 de lo contrario devuelve -1
*/
int entrenador_agregar_pokemon(entrenador_t* entrenador,pokemon_t* pokemon);

/*
 * Recibe un entrenador valido
 * Devuelve la cantidad de pokemones que tiene.
*/
size_t entrenador_cantidad_pokemon(entrenador_t* entrenador);



/*
 * Imprime por pantalla el entrenador recivido con sus Pokemon
*/
void entrenador_mostrar_pokemon(entrenador_t* entrenador);

/*
 * Recibe un personaje valido y la posicion del pokemon en la party
 * Devuelve el Pokemon en esa posicion de la party o en caso de error NULL
*/
pokemon_t* entrenador_pokemon(entrenador_t* entrenador,size_t pos);

/*
 * Libera la memoria almacenada por un entrenador
*/
void entrenador_destruir(void* entrenador);


/***************************/
/*   FUNCIONES GIMNASIO    */
/***************************/


/*
 * Crea y reserva la memoria de un gimnasio con los parametros recividos 
 * Devuelve un puntero al gimnasio creado o NULL en caso de error.
*/
gimnasio_t* gimnasio_crear(char nombre[MAX_NOMBRE],int dificultad,int id_funcion_batalla);


/*
 * Comparador de elementos. Recibe dos elementos y devuelve:
 *    - 0 en caso de ser iguales, 
 *    - mayor a 0 si el primer gimnasio es mas dificil al segundo,
 *    - menor a 0 si el primer gimnasio es mas facil al segundo.
 */
int gimnasio_comparar_dificultades(void* gym_1,void* gym_2);

/*
 * Imprime por pantalla la informacion de un gimnasio
*/
void gimnasio_mostrar(gimnasio_t* gimnasio);

/*
 * Recibe un gimnasio y un entrenador validos
 * Agrega el entrenador al Gimnasio
 * Si tuvo exito devuelve 0 de lo contrario devuelve -1
*/
int gimnasio_insertar_entrenador(gimnasio_t* gimnasio,entrenador_t* entrenador);

/*
 * Recibe un gimnasio valido
 * Devuelve true si ya se tomo un pokemon del lider
*/
bool gimnasio_pokemon_tomado(gimnasio_t* gimnasio);

/*
 * Recibe un gimnasio valido
 * Actualiza el gimnasio a que se tomo el pokemon del lider
 * Devuelve 0 si ocurrio con exito o -1 en caso de error
*/
int gimnasio_tomar_pokemon(gimnasio_t* gimnasio);

/*
 * Recive un gimnasio y dos pokemon
 * Se llama a la funcion de batalla del gimnasio
 * 
 * Si el ganador es el primer pokemon, se devolvera 1
 * Si el ganador es el segundo pokemon, se devolvera -1
 * 
 * En caso de error se devuelve 1
*/
int gimnasio_batalla(gimnasio_t* gimnasio,pokemon_t* pkm_1,pokemon_t* pkm_2);

/*
 * Recibe un gimnasio valido
 * Devuelve el proximo entrenador a pelear(el ultimo insertado)
 * En caso de error devuelve NULL
*/
entrenador_t* gimnasio_entrenador_a_pelear(gimnasio_t* gimnasio);

/*
 * Recibe un gimnasio valido
 * Devuelve el tipo del ultimo entrenador(o sea entrenador a pelear)
 * En caso de error devuelve '\0'
*/
char gimnasio_tipo_entrenador(gimnasio_t* gimnasio);


/*
 * Recibe un gimnasio valido
 * Devuelve la cantidad de entrenadores que siguen en el gimnasio
*/
size_t gimnasio_entrenadores_restantes(gimnasio_t* gimnasio);

/*
 * Recibe un gimnasio valido
 * Saca el ultimo entenador(entrenador a pelear) del gimnasio
 * Devuelve 0 si salio bien o -1 en caso de ERROR
*/
int gimnasio_sacar_ultimo_entrenador(gimnasio_t* gimnasio);

/*
 * Libera la memoria almacenada por un gimnasio
*/
void gimnasio_destruir(void* gimnasio);


#endif //__GIMNASIO_H__