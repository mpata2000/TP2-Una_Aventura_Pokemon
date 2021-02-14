#include "gimnasio.h"


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
    int id_funcion_batalla;
    lista_t* entrenadores;
}gimnasio_t;


pokemon_t* pokemon_crear(char nombre[MAX_NOMBRE],int ataque,int defensa,int velocidad){
    pokemon_t* poke = calloc(1,sizeof(pokemon_t));
    if(!poke){
        return NULL;
    }

    strcpy(poke->nombre,nombre);
    poke->ataque = ataque;
    poke->defensa = defensa;
    poke->velocidad = velocidad;

    return poke;
}

void pokemon_destruir(pokemon_t* pokemon){
    free(pokemon);
}



entrenador_t* entrenador_crear(char tipo,char nombre[MAX_NOMBRE]){
    lista_t* pokemon_aux = lista_crear(pokemon_destruir);
    if(!pokemon_aux){
        return NULL;
    }
    
    entrenador_t* entrenador = calloc(1,sizeof(entrenador_t));
    if (!entrenador){
        return NULL;
    }
    

    entrenador->tipo = tipo;
    strcpy(entrenador->nombre,nombre);
    entrenador->pokemon = pokemon_aux;
   
    return entrenador;
}


int entrenador_agregar_pokemon(entrenador_t* entrenador,pokemon_t* pokemon){
    if(!entrenador || !pokemon){
        return ERROR;
    }

    return lista_insertar(entrenador->pokemon,pokemon);
}

void entrenador_destruir(entrenador_t* entrenador){
    if(!entrenador){
        return;
    }

    if(entrenador->pokemon){
        lista_destruir(entrenador->pokemon);
    }
    free(entrenador);
}


gimnasio_t* gimnasio_crear(char nombre[MAX_NOMBRE],int dificultad,int id_funcion_batalla){
    lista_t* entrenadores_aux = lista_crear(entrenador_destruir);
    if(!entrenadores_aux){
        return NULL;
    }
    gimnasio_t* gym = calloc(1,sizeof(gimnasio_t));
    if(!gym){
        return NULL;
    }

    stpcpy(gym->nombre,nombre);
    gym->dificultad = dificultad;
    gym->id_funcion_batalla == id_funcion_batalla;
    gym->entrenadores = entrenadores_aux;

    return gym;
}

void gimnasio_destruir(gimnasio_t* gimnasio){
    if(!gimnasio){
        return;
    }

    if(gimnasio->entrenadores){
        lista_destruir(gimnasio->entrenadores);
    }
    free(gimnasio);
}