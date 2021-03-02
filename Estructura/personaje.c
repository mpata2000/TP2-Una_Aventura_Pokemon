#include "personaje.h"
#include <string.h>
#include <stdio.h>

#define EXITO 0
#define ERROR -1

/*
 * Reserva la memoria necesaria del personaje y le asigna el nombre recivido
 * Si hay un error devuelve NULL
*/
personaje_t* personaje_crear(char nombre[MAX_NOMBRE]){
    personaje_t* personaje = calloc(1,sizeof(personaje_t));
    if(!personaje){
        
        return NULL;
    }

    lista_t* lista_aux = lista_crear(pokemon_destruir);
    if(!lista_aux){
        free(personaje);
        return NULL;
    }
    strcpy(personaje->nombre,nombre);
    personaje->pokemon_obtenidos=lista_aux;
    return personaje;
}

/*
 * Chequea si un Pokemon recibido esta en la party
 * Devuelve true si esta
*/
bool pokemon_esta_en_party(pokemon_t* party[MAX_POKEMON_PARTY],pokemon_t* pokemon){
    bool esta = false;
    int i = 0;

    while(!esta && i<MAX_POKEMON_PARTY){
        if(party[i] == pokemon){
            esta = true;
        }
        i++;
    }
    return esta;
}

/*
 * Devuelve la posicion del Pokemon en la party
 * 
*/
int pos_en_party(pokemon_t* party[MAX_POKEMON_PARTY],pokemon_t* pokemon){
    int pos = ERROR;
    int i = 0;

    while(pos == -1 && i<MAX_POKEMON_PARTY){
        if(party[i] == pokemon){
            pos = i;
        }
        i++;
    }
    return pos;
}

/*
 * Recibe un personaje valido y dos numeros
 *    -> num_pkm_party es la posicion del pokemon que se quiere sacar(Tiene que ser meno a 6)
 *    -> num_pkm_obteni es la posicion del pokemon que se quiere poner en la party
 * Cambia los Pokemon solo si el Pokemon no esta ya en la party
 * Devuevle 0 en caso de que el cambio e exitoso o -1 en caso de ERROR
*/
int personaje_cambiar_pokemon(personaje_t* personaje,size_t num_pkm_party,size_t num_pkm_obtenido){
    if(!personaje || num_pkm_party >= MAX_POKEMON_PARTY || personaje_cantidad_pokemon(personaje) < MAX_POKEMON_PARTY){
        return ERROR;
    }

    pokemon_t* pokemon_aux = lista_elemento_en_posicion(personaje->pokemon_obtenidos,num_pkm_obtenido);
    if(!pokemon_aux){
        return ERROR;
    }

    if(pokemon_esta_en_party(personaje->party,pokemon_aux)){  
        int i = pos_en_party(personaje->party,pokemon_aux);
        if(i == ERROR){
            return ERROR;
        }
        personaje->party[i] = personaje->party[num_pkm_party];
    }
    personaje->party[num_pkm_party] = pokemon_aux;
    
    return EXITO;
}

/*
 * Muestra la party del personaje por pantalla
*/
void mostrar_party(pokemon_t* party[MAX_POKEMON_PARTY]){
    printf("#############################################################################################################\n");
    printf("#                                                                                                           #\n");
    printf("#                                               POKEMON PARTY                                               #\n");
    printf("#                                                                                                           #\n");
    printf("#############################################################################################################\n");
    printf("# Posicion  #       0       #       1       #       2       #       3       #       4       #       5       #\n");
            
    printf("# Nombre:   ");
    for(int i = 0;i<MAX_POKEMON_PARTY;i++){
        if(party[i]){
            printf("# %13s ",party[i]->nombre);
        }else{
            printf("#               ");
        }
    }
    printf("#\n");

    printf("# Ataque    ");
    for(int i = 0;i<MAX_POKEMON_PARTY;i++){
        if(party[i]){
            printf("# %13i ",party[i]->ataque);
        }else{
            printf("#               ");
        }
    }
    printf("#\n");

    printf("# Defensa   ");
    for(int i = 0;i<MAX_POKEMON_PARTY;i++){
        if(party[i]){
            printf("# %13i ",party[i]->defensa);
        }else{
            printf("#               ");
        }
    }
    printf("#\n");

    printf("# Velocidad ");
    for(int i = 0;i<MAX_POKEMON_PARTY;i++){
        if(party[i]){
            printf("# %13i ",party[i]->velocidad);
        }else{
            printf("#               ");
        }
    }
    printf("#\n");

    printf("# EVs       ");
    for(int i = 0;i<MAX_POKEMON_PARTY;i++){
        if(party[i]){
            printf("# %13i ",party[i]->evs);
        }else{
            printf("#               ");
        }
    }
    printf("#\n");
    printf("#############################################################################################################\n");
}



/*
 * Muestra un personaje valido y todo sus Pokemon
 * Es medio feo
*/
void personaje_mostrar(personaje_t* personaje){
    if(!personaje){
        return;
    }
    system("clear");

    //mostrar_nombre
    printf("####################################\n");
    printf("#                                  #\n");
    printf("#       %-20s       #\n",personaje->nombre);
    printf("#                                  #\n");
    printf("####################################\n");
    printf("\n");

    mostrar_party(personaje->party);
    printf("\n");
    printf("##################################################################################\n");
    printf("#                               POKEMON OBTENIDOS                                #\n");
    pokemon_mostrar(personaje->pokemon_obtenidos);
}


/*
 * Recibe un personaje_t valido
 * Devuelve la cantidad de pokemones que tiene.
*/
size_t personaje_cantidad_pokemon(personaje_t* personaje){
    if(!personaje){
        return 0;
    }
    return lista_elementos(personaje->pokemon_obtenidos);
}


/*
 * Recibe un personaje valido y la posicion del pokemon en la party
 * Devuelve el Pokemon en esa posicion de la party o en caso de error NULL
*/
pokemon_t* personaje_pokemon_party(personaje_t* personaje,size_t pos){
    if(!personaje || pos >= MAX_POKEMON_PARTY){
        return NULL;
    }
    return personaje->party[pos];
}

/* REWORK */
/*
 * Recibe un personaje y un pokemon validos
 * Agrega el pokemon al personaje
 * Si tuvo exito devuelve 0 de lo contrario devuelve -1
*/
int personaje_agregar_pokemon(personaje_t* personaje,pokemon_t* pokemon){
    if(!personaje || !pokemon){
        return ERROR;
    }
    if(personaje_cantidad_pokemon(personaje) < MAX_POKEMON_PARTY){
        personaje->party[personaje_cantidad_pokemon(personaje)] = pokemon;
    }
    return lista_insertar(personaje->pokemon_obtenidos,pokemon); // SI me devuelve ERROR y la ultima posicion del vector no se sobrescribe va a perder memoria
}


/*
 * Libera la memoria reservada por el personaje
*/
void personaje_destruir(personaje_t* personaje){
    if(!personaje){
        return;
    }

    if (personaje->pokemon_obtenidos){
        lista_destruir(personaje->pokemon_obtenidos);
    }
    
    free(personaje);
}