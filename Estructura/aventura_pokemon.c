#include "aventura_pokemon.h"
#include "interfaz.h"

#define NEXT 'N'

/*
 * Reserva la memoria de un juego 
 * Devuelve un puntero al entrenador creado o NULL en caso de error.
*/
juego_t* crear_juego(){
    juego_t* juego = calloc(1,sizeof(juego_t));

    juego->gimnasios = heap_crear(gimnasio_comparar_dificultades,gimnasio_destruir);
    juego->simular = false;
    
    return juego;
}

/*
 * Recibe un juego y chequea que sea valido
 * Devuelve true cuando haya almenos un gimnasio gimnasios y el personaje es distinto de NULL
*/
bool juego_valido(juego_t* juego){
    return (heap_elementos(juego->gimnasios) && juego->personaje);
}

/*
 * Libera la memoria almacenada por un juego
*/
void destruir_juego(juego_t* juego){
    if (!juego){
        return;
    }

    heap_destruir(juego->gimnasios);
    if(!juego->gimnasio_actual){
        gimnasio_destruir(juego->gimnasio_actual);
    }
    personaje_destruir(juego->personaje);
    free(juego);
}

/*
 * Recibe un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_gimnasio(juego_t* juego){
    char ruta_archivo[MAX_RUTA_ARCHIVO] = "./Archivos/Gimnasios/";
    char nombre_archivo[MAX_NOMBRE];

    mostrar_menu_inicio(juego);
    info_cargar_gimnasio();
    printf(" Ingrese el nombre del archivo: ");

    if(leer_linea(stdin,nombre_archivo,MAX_NOMBRE,NULL) == NULL){
        return ERROR;
    }

    strcat(ruta_archivo,nombre_archivo);

    //TODO: Pantalla de carga falsa

    if(lectura_archivo_gimnasios(ruta_archivo,juego->gimnasios) == ERROR){
        if(heap_elementos(juego->gimnasios)){
            printf("Ocurrio un error");
            printf("Se leyeron correctamente %li gimnasios\n",heap_elementos(juego->gimnasios));
            if(leer_caracter("Si desea continuar presione N sino cualquier otro caracter\n") == NEXT){
                return EXITO;
            };
        }
        enter_para_continuar();
        return ERROR;
    }
    
    return EXITO;
}

/*
 * Recibe un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_personaje(juego_t* juego){    
    char ruta_archivo[MAX_RUTA_ARCHIVO] = "./Archivos/Personajes/";
    char nombre_archivo[MAX_NOMBRE];

    mostrar_menu_inicio(juego);
    info_cargar_personaje();
    printf(" Ingrese el nombre del archivo: ");

    if(leer_linea(stdin,nombre_archivo,MAX_NOMBRE,NULL) == NULL){
        return ERROR;
    }

    strcat(ruta_archivo,nombre_archivo);

    //TODO: Pantalla de carga falsa

    juego->personaje = lectura_archivo_personaje(ruta_archivo);
    if(!juego->personaje){
        printf("Ocurrio un error en la carga del archivo\n");
        return ERROR;
    }
    return EXITO;
}



/*
 * Recibe un juego valido
 * Pelea contra el proximo entrenador planeado
 * Si pierde gana el personaje devuelve true
 * En el caso contrario devuelve false
*/
bool batalla(juego_t* juego){
    if(!juego){
        return false;
    }
    entrenador_t* entrenador_actual = gimnasio_entrenador_a_pelear(juego->gimnasio_actual);
    if(!entrenador_actual){
        return false;
    }
    size_t contador_personaje = 0;
    size_t contador_entrenador = 0;
    pokemon_t* pkm_jugador = NULL;
    pokemon_t* pkm_entrenador = NULL;

    do{
        pkm_jugador = personaje_pokemon_party(juego->personaje,contador_personaje);
        pkm_entrenador = entrenador_pokemon(entrenador_actual,contador_entrenador);
        if(!juego->simular){
            mostrar_batalla(juego,pkm_jugador,pkm_entrenador);
        }
        /*Talvez abstraer funcion?*/
        if(juego->gimnasio_actual->funcion_batalla(pkm_jugador,pkm_entrenador) == GANO_PRIMERO){ // El que pierde tiene que pasar de Pokemon
            /* TODO: Mostrar quien gano?*/
            contador_entrenador++;
        }else{
            contador_personaje++;
        }

        if (!juego->simular){
            while(leer_caracter("Ingrese N para continuar: ") != NEXT);
        }
        
    }while (pkm_jugador && pkm_entrenador); // El primero que se quede sin pokemon pierde
    
    if(pkm_jugador){
        return true;
    }else{
        return false;
    }

}

/*
 * Recibe un juego valido
 * Si es posible va a tomar un Pokemon del Lider del gimnasio
 * En caso de exito o error se le informa al usuario por pantalla
*/
void tomar_pokemon(juego_t* juego){
    if(!juego || gimnasio_tipo_entrenador(juego->gimnasio_actual) != LIDER){
        return;
    }

    entrenador_t* lider = gimnasio_entrenador_a_pelear(juego->gimnasio_actual);
    if(!lider){
        return;
    }
    int pos_pkm = 0;
    pokemon_t* pokemon_lider = NULL;
    entrenador_mostrar_pokemon(lider);
    
    do{
        pos_pkm = obtener_numero(" Ingrese el numero del Pokemon que quiere tomar: ");
        pokemon_lider = entrenador_pokemon(lider,(size_t)abs(pos_pkm));
        if(!pokemon_lider){
            printf(" No se pudo obtener ese Pokemon.\n");
            enter_para_continuar();
        }
    } while (!pokemon_lider);
    
    pokemon_t* pkm_copia = pokemon_recrear(pokemon_lider);
    if(!pkm_copia){
        printf(" No se pudo tomar ese Pokemon.\n");
        enter_para_continuar();
    }else{
        personaje_agregar_pokemon(juego->personaje,pkm_copia);
        gimnasio_tomar_pokemon(juego->gimnasio_actual);
    }    
}

/*
 * Recibe un juego valido
 * Si es posible cambia los pokemon de la party
 * En caso de exito o error se le informa al usuario por pantalla 
*/
void cambiar_pokemon(juego_t* juego){
    if(!juego){
        return;
    }

    if(personaje_cantidad_pokemon(juego->personaje) < MAX_POKEMON_PARTY){
        printf(" Necesita tener mas de 6 Pokemon para cambiar la party.\n");
        enter_para_continuar();
        return;
    }

    int pos_pkm_1 = 0;
    int pos_pkm_2 = 0;
    personaje_mostrar(juego->personaje);
    
    do{
        if (pos_pkm_1 >= MAX_POKEMON_PARTY || pos_pkm_1 == ERROR){
            printf("El numero ingresado no es valido\n");
            printf("Recuerde de solo ingresar numeros y que el numero pertenesca a la party\n");
        }
        
        pos_pkm_1 = obtener_numero("Ingresar la posicion del Pokemon de la Party: ");
    }while(pos_pkm_1 >= MAX_POKEMON_PARTY || pos_pkm_1 == ERROR);

    do{
        if (pos_pkm_2 == ERROR){
            printf("El numero ingresado no es valido\n");
            printf("Recuerde de solo ingresar numeros\n");
        }
        
        pos_pkm_2 = obtener_numero("Ingresar la posicion del Pokemon Obtenido: ");
    }while(pos_pkm_2 == ERROR);

    if(personaje_cambiar_pokemon(juego->personaje,(size_t)pos_pkm_1,(size_t)pos_pkm_2) == EXITO){
        printf("Los Pokemon han sido cambiado con exito.\n");
    }else{
        printf("Ocurrio un error al cambiar los Pokemon\n");
        printf("Esto pudo ocrrir porque la posicion no existia o el Pokemon ya estaba en la party\n");
    }
    enter_para_continuar();
}


