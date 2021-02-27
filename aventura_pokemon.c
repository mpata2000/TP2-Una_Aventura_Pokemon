#include "gimnasio.h"
#include "personaje.h"
#include "archivos.h"
#include "heap.h"
#include "interfaz.h"

#define AGREGAR_PERSONAJE 'E'
#define MOSTRAR_PERSONAJE 'E'
#define AGREGAR_GYM 'A'
#define COMENZAR_PARTIDA 'I'
#define SIMULAR_PARTIDA 'S'
#define CAMBIAR_POKEMON 'C'
#define PROXIMA_BATALLA 'B'
#define NEXT 'N'
#define REINTENTAR 'R'
#define FIN_PARTIDA 'F'
#define TOMAR_POKEMON 'T'

typedef struct juego{
    heap_t* gimnasios;
    gimnasio_t* gimnasio_actual;
    personaje_t* personaje;
    bool simular;
}juego_t;



juego_t* crear_juego(){
    juego_t* juego = calloc(1,sizeof(juego_t));

    juego->gimnasios = heap_crear(gimnasio_comparar_dificultades,gimnasio_destruir);
    juego->simular = false;
    
    return juego;
}


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
 * Recive un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_gimnasio(juego_t* juego){
    char ruta_archivo[MAX_RUTA_ARCHIVO] = "./Archivos/Gimnasios/";
    char nombre_archivo[MAX_NOMBRE];

    system("clear");
    mostrar_menu_inicio();
    info_cargar_gimnasio();
    printf(" Ingrese el nombre del archivo: ");

    if(leer_linea(stdin,nombre_archivo,MAX_NOMBRE,NULL) == NULL){

    }

    strcat(ruta_archivo,nombre_archivo);
    if(lectura_archivo_gimnasios(ruta_archivo,juego->gimnasios) == ERROR){
        if(heap_elementos(juego->gimnasio_actual)){
            printf("Ocurrio un error");
            printf("Se leyeron correctamente %i gimnasios\n",heap_elementos(juego->gimnasio_actual));
            if(leer_caracter("Si desea continuar presione N\n") == NEXT){
                return EXITO;
            };
        }
        // TODO
    }

    return EXITO;
}

/*
 * Recive un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_personaje(juego_t* juego){    
    char ruta_archivo[MAX_RUTA_ARCHIVO] = "./Archivos/Personajes/";
    char nombre_archivo[MAX_NOMBRE];

    system("clear");
    mostrar_menu_inicio();
    info_cargar_personaje();
    printf(" Ingrese el nombre del archivo: ");

    if(leer_linea(stdin,nombre_archivo,MAX_NOMBRE,NULL) == NULL){
        return ERROR;
    }

    strcat(ruta_archivo,nombre_archivo);
    juego->personaje = lectura_archivo_personaje(ruta_archivo);
    if(!juego->personaje){
        printf("Ocurrio un error en la carga del archivo");
        enter_para_continuar();
        return ERROR;
    }
    return EXITO;
}

/*
 * Recive un juego y chequea que sea valido
 * Devuelve true cuando los gimnasios y el personaje son distintos de NULL
*/
bool juego_valido(juego_t* juego){
    return (juego->gimnasios && juego->personaje);
}


int menu_inicio(juego_t* juego){
    if(!juego){
        return ERROR;
    }
    char ingreso = '\0';
    int retorno = EXITO;

    do{
        system("clear");
        mostrar_menu_inicio();

        ingreso = leer_caracter("Ingrese una letra: ");
        // Si ocurre un error cingreso va a ser '/0' no deberia ser un problema

        if((ingreso == COMENZAR_PARTIDA || ingreso == SIMULAR_PARTIDA) && !juego_valido(juego)){
            printf(" El juego no puede ser iniciado sin tener al menos un gimnasio y un personaje\n");
            
        }


        switch (ingreso){
            case AGREGAR_GYM:
                retorno = agregar_gimnasio(juego);
                break;
            case AGREGAR_PERSONAJE:
                if(!juego->personaje){
                    retorno = agregar_personaje(juego);
                }else{
                    printf("Ya se cargo un personaje\n");
                }
                break; 
            case SIMULAR_PARTIDA:
                juego->simular = true;
                break;   
            default:
                // Mensaje de caracter no esperado?
                break;
        }
    }while (ingreso != COMENZAR_PARTIDA && ingreso != SIMULAR_PARTIDA && !juego_valido(juego) && retorno != ERROR);

    
    return retorno;
}

/*
 * Recive un juego valido
 * 
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
            menu_batalla(juego,pkm_jugador,pkm_entrenador);
        }
        /*Talvez abstraer funcion?*/
        if(juego->gimnasio_actual->funcion_batalla(pkm_jugador,pkm_entrenador) == GANO_PRIMERO){ // El que pierde tiene que pasar de Pokemon
            /* TODO: Mostrar quien gano?*/
            contador_entrenador++;
        }else{
            contador_personaje++;
        }

        if (!juego->simular){
            n_para_continuar();
        }
        
    }while (!pkm_jugador && !pkm_entrenador); // El primero que se quede sin pokemon pierde
    
    if(pkm_jugador){
        return true;
    }else{
        return false;
    }

}



void cambiar_pokemon(juego_t* juego){
    if(!juego){
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

    if(personaje_cambiar_pokemon(juego->personaje,pos_pkm_1,pos_pkm_2) == EXITO){
        printf("Los Pokemon han sido cambiado con exito.\n");
    }else{
        printf("Ocurrio un error al cambiar los Pokemon\n");
        printf("Esto pudo ocrrir porque la posicion no existia o el Pokemon ya estaba en la party\n");
    }
    enter_para_continuar();
}

/*
 * 
*/
bool menu_gimnasio(juego_t* juego){
    char ingreso = '\0';
    bool gimnasio_derrotado = false;
    bool jugador_derrotado = false;

    if(!juego || !juego->gimnasio_actual){
        return true;
    }


    while(gimnasio_entrenadores_restantes(juego->gimnasio_actual) > 0 && !jugador_derrotado && !gimnasio_derrotado){
        mostrar_menu_gimnasio(juego);
        ingreso = leer_caracter("Ingrese una letra: ");
        
        switch (ingreso){
            case CAMBIAR_POKEMON:
                cambiar_pokemon(juego);
                break;
            case GIMNASIO:
                //Mostrar Info del Gimnasio
                break; 
            case MOSTRAR_PERSONAJE:
                personaje_mostrar(juego->personaje);
                enter_para_continuar();
                break;
            case PROXIMA_BATALLA:
                if(batalla(juego)){
                    if(gimnasio_tipo_entrenador(juego->gimnasio_actual) == LIDER){
                        gimnasio_derrotado = true;
                    }else{
                        gimnasio_sacar_ultimo_entrenador(juego->gimnasio_actual);
                    }
                }else{
                    jugador_derrotado = true;
                }
                break;
            default:
                // Mensaje de caracter no esperado?
                break;
        }
    }

    return jugador_derrotado;
}



void menu_victoria(juego_t* juego){
    if(!juego){
        return ERROR;
    }
    
    char ingreso = '\0';

    do{
        mostrar_menu_victoria(juego);
        ingreso = leer_caracter("Ingrese una letra: ");
        
        switch (ingreso){
            case CAMBIAR_POKEMON:
                cambiar_pokemon(juego);
                break;
            case TOMAR_POKEMON:
                //Mostrar Info del Gimnasio
                break; 
            case NEXT:
                gimnasio_destruir(juego->gimnasio_actual);
                juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);
                break;
            default:
                // Mensaje de caracter no esperado?
                break;
        }
    } while (ingreso != NEXT);
    
    

}

/*
 * Recive un juego valido
 * Devuelve:
 *     - True si el jugador quiere terminar la partida
 *     - False si quiere reintentar el gimnasio
*/
bool menu_derrota(juego_t* juego){
   if(!juego){
        return false;
    }
    bool retorno = true;
    char ingreso = '\0';

    do{
        mostrar_menu_derrota(juego);
        ingreso = leer_caracter("Ingrese una letra: ");
        
        switch (ingreso){
            case CAMBIAR_POKEMON:
                cambiar_pokemon(juego);
                break;
            case FIN_PARTIDA:
                gimnasio_destruir(juego->gimnasio_actual);
                //Terminar Juego
                break; 
            case REINTENTAR:
                retorno = false
                break;
            default:
                // Mensaje de caracter no esperado?
                break;
        }
    } while (ingreso != REINTENTAR && ingreso != FIN_PARTIDA); 
    
    return retorno;
}


int main(void){
    bool derrota = false;
    juego_t* juego = crear_juego();


    if(menu_inicio(juego) == EXITO){
        juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);
        do{
            derrota = menu_gimnasio(juego);

            if(derrota){
                derrota = menu_derrota(juego);
            }else{
                menu_victoria(juego);
            }
        }while(juego->gimnasio_actual && !derrota);
    }

    destruir_juego(juego);

}
