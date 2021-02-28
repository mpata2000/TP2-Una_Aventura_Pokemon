#include "pokemon.h"
#include <string.h>
#include <stdio.h>

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

pokemon_t* pokemon_recrear(pokemon_t* pokemon){
    if(!pokemon){
        return NULL;
    }
    pokemon_t* pkm = pokemon_crear(pokemon->nombre,pokemon->velocidad,pokemon->ataque,pokemon->defensa);
    pkm->evs = pokemon->evs;
    
    return pkm;
}

void pokemon_aumentrar_evs(pokemon_t* pokemon){
    if(!pokemon){
        return;
    }
    if(pokemon->evs < MAX_EVS){
        pokemon->evs++;
    }
}

char* pokemon_nombre(pokemon_t* pokemon){
    if(!pokemon){
        return NULL;
    }
    return pokemon->nombre;
}

int pokemon_ataque(pokemon_t* pokemon){
    if(!pokemon){
        return 0;
    }
    return (pokemon->ataque + pokemon->evs);
}

int pokemon_defensa(pokemon_t* pokemon){
    if(!pokemon){
        return 0;
    }
    return (pokemon->defensa + pokemon->evs);
}

int pokemon_velocidad(pokemon_t* pokemon){
    if(!pokemon){
        return 0;
    }
    return (pokemon->velocidad + pokemon->evs);
}

void pokemon_mostrar(lista_t* pokemon){
    if(!pokemon){
        return;
    }

    lista_iterador_t* iterdor = lista_iterador_crear(pokemon);
    if(!iterdor){
        return;
    }

    printf("##########################################################################\n");
    printf("# Poscision #     Nombre    #  Ataque  #  Defensa  #  Velocidad  #  EVs  #\n");

    int i = 0;
    while (lista_iterador_tiene_siguiente(iterdor)){
        pokemon_t* pkm = (pokemon_t*)lista_iterador_elemento_actual(iterdor);
        if(pkm){
            printf("#  %7i  # %13s #  %6i  #  %7i  #  %9i  #  %3i  #\n",i,pkm->nombre,pkm->ataque,pkm->defensa,pkm->velocidad,pkm->evs);
        }
        lista_iterador_avanzar(iterdor);
        i++;
    }
    printf("##########################################################################\n");
    lista_iterador_destruir(iterdor);
}


void pokemon_destruir(void* pokemon){
    free((pokemon_t*)pokemon);
}