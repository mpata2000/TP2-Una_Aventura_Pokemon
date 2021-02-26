#include "gimnasio.h"


#define EXITO 0
#define ERROR -1

/***************************/
/*   FUNCIONES ENTRENDOR   */
/***************************/

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


size_t entrenador_cantidad_pokemon(entrenador_t* entrenador){
    if(!entrenador){
        return 0;
    }
    return lista_elementos(entrenador->pokemon);
}

void entrenador_mostrar_pokemon(entrenador_t* entrenador){
    if(!entrenador){
        return;
    }
    //Nombre maybe

    pokemon_mostrar(entrenador->pokemon);

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

/***************************/
/*   FUNCIONES GIMNASIO    */
/***************************/

funcion_batalla funcion_de_batalla_segun_id(int id){
    funcion_batalla retorno;
    switch (id){
        case 1:
            retorno = funcion_batalla_1;
            break;
        case 2:
            retorno = funcion_batalla_2;
            break;
        case 3:
            retorno = funcion_batalla_3;
            break;
        case 4:
            retorno = funcion_batalla_4;
            break;
        case 5:
            retorno = funcion_batalla_5;
            break;
        default:
            retorno = funcion_batalla_1;
            break;
    }

    return retorno;
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
    gym->funcion_batalla = funcion_de_batalla_segun_id(id_funcion_batalla);
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

entrenador_t* gimnasio_entrenador_a_pelear(gimnasio_t* gimnasio){
    if(!gimnasio){
        return NULL;
    }
    return lista_ultimo(gimnasio->entrenadores);
}

size_t gimnasio_entrenadores_restantes(gimnasio_t* gimnasio){
    if(!gimnasio){
        return NULL;
    }
    return lista_elementos(gimnasio->entrenadores);
}

int gimnasio_sacar_ultimo_entrenador(gimnasio_t* gimnasio){
    if(!gimnasio){
        return ERROR;
    }
    return lista_borrar(gimnasio->entrenadores);
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