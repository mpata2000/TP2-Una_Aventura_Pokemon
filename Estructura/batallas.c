#include "batallas.h"
#include <string.h>
#include <stdbool.h>
#include "pokemon.h"
/*
 * Se deberan implementar las 5 funciones de batalla.
 * Las reglas para decidir al ganador las inventan ustedes
 * 
 * Si el ganador es el primer pokemon, se devolvera 1
 * Si el ganador es el segundo pokemon, se devolvera -1
 * 
 * No habran empates.
 */

int funcion_batalla_1(void* pkm_1, void* pkm_2){
    int ganador = strcmp(((pokemon_t*)pkm_1)->nombre,((pokemon_t*)pkm_2)->nombre);

    if(ganador == 0){
        //Quien llego antes a tmarse lista
        if(pokemon_velocidad(((pokemon_t*)pkm_2)) > pokemon_velocidad(((pokemon_t*)pkm_1))){
            ganador = GANO_SEGUNDO;
        }else{
            ganador = GANO_PRIMERO;
        }
    }
    return ganador;
}

int funcion_batalla_2(void* pkm_1, void* pkm_2){
    if(pokemon_velocidad(((pokemon_t*)pkm_2)) > pokemon_velocidad(((pokemon_t*)pkm_1))){
        if(pokemon_ataque(((pokemon_t*)pkm_2)) > pokemon_defensa(((pokemon_t*)pkm_1))){
            return GANO_SEGUNDO;
        }else{
            return GANO_PRIMERO;
        }
    }else{
        if(pokemon_ataque(((pokemon_t*)pkm_2)) > pokemon_defensa(((pokemon_t*)pkm_1))){
            return GANO_PRIMERO;
        }else{
            return GANO_SEGUNDO;
        }
    }
}

int funcion_batalla_3(void* pkm_1, void* pkm_2){
    int stats_1 = pokemon_ataque(((pokemon_t*)pkm_1)) + pokemon_defensa(((pokemon_t*)pkm_1)) + pokemon_velocidad(((pokemon_t*)pkm_1));
    int stats_2 = pokemon_ataque(((pokemon_t*)pkm_2)) + pokemon_defensa(((pokemon_t*)pkm_2)) + pokemon_velocidad(((pokemon_t*)pkm_2));
    if(stats_1 < stats_2){
        return GANO_SEGUNDO;
    }
    return GANO_PRIMERO;
}

int funcion_batalla_4(void* pkm_1, void* pkm_2){
    if(((pokemon_t*)pkm_1)->shiny){
        return GANO_PRIMERO;
    }else if (((pokemon_t*)pkm_2)->shiny){
        return GANO_SEGUNDO;
    }
    
    return funcion_batalla_3(pkm_1,pkm_2);
}

bool es_vocal_min(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool es_vocal_may(char c){
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int cant_vocales(char nombre[MAX_NOMBRE]){
    int i = 0;
    int vocales = 0;
    while (nombre[i] != '\0'){
        if(es_vocal_min(nombre[i]) || es_vocal_may(nombre[i])){
            vocales++;
        }
        i++;
    }
    return vocales;
}

int funcion_batalla_5(void* pkm_1, void* pkm_2){
    if(cant_vocales(((pokemon_t*)pkm_1)->nombre) > cant_vocales(((pokemon_t*)pkm_2)->nombre)){
        return GANO_PRIMERO;
    }
    return GANO_SEGUNDO;
}
