
#include "gimnasio.h"
#include <stdio.h>
#include "../Utiles/ANSI-color-codes.h"

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
    
    printf("####################################\n");
    printf("#                                  #\n");
    printf("#       %-22s    #\n",entrenador->nombre);
    printf("#                                  #\n");
    printf("####################################\n");
    printf("\n");

    pokemon_mostrar(entrenador->pokemon);

}

pokemon_t* entrenador_pokemon(entrenador_t* entrenador,size_t pos){
    if(!entrenador){
        return 0;
    }
    return lista_elemento_en_posicion(entrenador->pokemon,pos);
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

/*
 * Recibe un numero de id de funcion de batalla
 * Devuelve la funcion segun la id
 * En caso de que no exista la id se devuelve funcion_batalla_1
*/
funcion_batalla funcion_de_batalla_segun_id(int id){
    if(id >= MAX_FUNCIONES_BATALLA || id < 0){
        return funcion_batalla_1;
    }
    funcion_batalla funcion[MAX_FUNCIONES_BATALLA] = {funcion_batalla_1,funcion_batalla_2,funcion_batalla_3,funcion_batalla_4,funcion_batalla_5};

    return funcion[id];
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
    gym->pokemon_tomado = false;

    return gym;
}

int gimnasio_comparar_dificultades(void* gym_1,void* gym_2){
    if(!gym_1){
        return -1;
    }else if(!gym_2){
        return 1;
    }
    return ((gimnasio_t*)gym_1)->dificultad - ((gimnasio_t*)gym_2)->dificultad;
}


void gimnasio_mostrar(gimnasio_t* gimnasio){
    if(!gimnasio){
        return;
    }
    system("clear");
    printf("\n");
    lista_iterador_t* iterador_entrenador = lista_iterador_crear(gimnasio->entrenadores);

    printf("» "BGRN"%s"reset"\n",gimnasio->nombre);
    printf("    » Dificultad: %i\n",gimnasio->dificultad);
    printf("    » Entrenadores restantes: %li\n",lista_elementos(gimnasio->entrenadores));
    printf("    » Entrenadores:\n");
    while (lista_iterador_tiene_siguiente(iterador_entrenador)){
        entrenador_t* entrenador = lista_iterador_elemento_actual(iterador_entrenador);
        lista_iterador_t* iterador_pkm = lista_iterador_crear(entrenador->pokemon);
        if(entrenador->tipo == LIDER){
             printf("        » "BYEL"%s"reset"\n",entrenador->nombre);
        }else{
            printf("        » "BMAG"%s"reset"\n",entrenador->nombre);
        }
        while (lista_iterador_tiene_siguiente(iterador_pkm)){
            pokemon_t* pkm = lista_iterador_elemento_actual(iterador_pkm);
            printf("            · "BYEL"%s"reset"\n",pkm->nombre);
            printf("                - Ataque:     [%i]\n",pokemon_ataque(pkm));
            printf("                - Defensa:    [%i]\n",pokemon_defensa(pkm));
            printf("                - Velocidad:  [%i]\n",pokemon_velocidad(pkm));

            lista_iterador_avanzar(iterador_pkm);
        }
        lista_iterador_destruir(iterador_pkm);
        lista_iterador_avanzar(iterador_entrenador);
    }
    
    lista_iterador_destruir(iterador_entrenador);
    
}


int gimnasio_insertar_entrenador(gimnasio_t* gimnasio,entrenador_t* entrenador){
    if(!gimnasio || !entrenador){
        return ERROR;
    }

    return lista_insertar(gimnasio->entrenadores,entrenador);
}


bool gimnasio_pokemon_tomado(gimnasio_t* gimnasio){
    if(!gimnasio ){
        return true;
    }
    
    return gimnasio->pokemon_tomado;
}


int gimnasio_tomar_pokemon(gimnasio_t* gimnasio){
    if(!gimnasio || gimnasio->pokemon_tomado){
        return ERROR;
    }
    gimnasio->pokemon_tomado = true;
    return EXITO;
}

/*
 * Recive un gimnasio y dos pokemon
 * Se llama a la funcion de batalla del gimnasio
 * 
 * Si el ganador es el primer pokemon, se devolvera 1
 * Si el ganador es el segundo pokemon, se devolvera -1
 * 
 * En caso de error se devuelve 1
*/
int gimnasio_batalla(gimnasio_t* gimnasio,pokemon_t* pkm_1,pokemon_t* pkm_2){
    if(!gimnasio){
        return GANO_PRIMERO;
    }
    return gimnasio->funcion_batalla(pkm_1,pkm_2);
}

entrenador_t* gimnasio_entrenador_a_pelear(gimnasio_t* gimnasio){
    if(!gimnasio){
        return NULL;
    }
    return lista_ultimo(gimnasio->entrenadores);
}


char gimnasio_tipo_entrenador(gimnasio_t* gimnasio){
    entrenador_t* entrenador = gimnasio_entrenador_a_pelear(gimnasio);
    if(!entrenador){
        return '\0';
    }
    return entrenador->tipo;
}


size_t gimnasio_entrenadores_restantes(gimnasio_t* gimnasio){
    if(!gimnasio){
        return 0;
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