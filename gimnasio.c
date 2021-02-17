#include "gimnasio.h"



pokemon_t* pokemon_crear(char nombre[MAX_NOMBRE],int velocidad,int ataque,int defensa){
    pokemon_t* poke = calloc(1,sizeof(pokemon_t));
    if(!poke){
        return NULL;
    }

    strcpy(poke->nombre,nombre);
    poke->velocidad = velocidad;
    poke->ataque = ataque;
    poke->defensa = defensa;

    return poke;
}

void pokemon_destruir(void* pokemon){
    free((pokemon_t*)pokemon);
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

void entrenador_destruir(void* entrenador){
    if(!entrenador){
        return;
    }

    if(((entrenador_t*)entrenador)->pokemon){
        lista_destruir(((entrenador_t*)entrenador)->pokemon);
    }
    free((entrenador_t*)entrenador);
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

    strcpy(gym->nombre,nombre);
    gym->dificultad = dificultad;
    gym->id_funcion = id_funcion_batalla;
    gym->entrenadores = entrenadores_aux;

    return gym;
}

int gimnasio_comparar_dificultades(void* gym_1,void* gym_2){
    return ((gimnasio_t*)gym_1)->dificultad - ((gimnasio_t*)gym_2)->dificultad;
}

int gimnasio_insertar_entrenador(gimnasio_t* gimnasio,entrenador_t* entrenador){
    if(!gimnasio || !entrenador){
        return ERROR;
    }

    return lista_insertar(gimnasio->entrenadores,entrenador);
}

void gimnasio_destruir(void* gimnasio){
    if(!gimnasio){
        return;
    }

    if(((gimnasio_t*)gimnasio)->entrenadores){
        lista_destruir(((gimnasio_t*)gimnasio)->entrenadores);
    }
    free((gimnasio_t*)gimnasio);
}