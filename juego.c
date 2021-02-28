#include "aventura_pokemon.h"
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



int menu_inicio(juego_t* juego){
    if(!juego){
        return ERROR;
    }
    char ingreso = '\0';
    int retorno = EXITO;

    do{
        mostrar_menu_inicio(juego);

        ingreso = leer_caracter("Ingrese una letra: ");
        // Si ocurre un error ingreso va a ser '/0' no deberia ser un problema

        if((ingreso == COMENZAR_PARTIDA || ingreso == SIMULAR_PARTIDA) && !juego_valido(juego)){
            printf(" El juego no puede ser iniciado sin tener al menos un gimnasio y un personaje\n");
            enter_para_continuar();
        }


        switch (ingreso){
            case AGREGAR_GYM:
                if(agregar_gimnasio(juego) == ERROR){
                    if(leer_caracter("Ingrese N para continuar o cualquier otro caracter para terminar el juego: ") != NEXT){
                        retorno = ERROR;
                    }
                }else{
                    printf("Se cargo el archivo con Exito\n");
                    enter_para_continuar();
                }
                break;

            case AGREGAR_PERSONAJE:
                if(!juego->personaje){
                    if(agregar_personaje(juego) == ERROR){
                        if(leer_caracter("Ingrese N para continuar o cualquier otro caracter para terminar el juego: ") != NEXT){
                            retorno = ERROR;
                        }
                    }else{
                        printf("Se cargo el archivo con Exito\n");
                        enter_para_continuar();
                    }

                }else{
                    printf("Ya se cargo un personaje\n");
                    enter_para_continuar();
                }
                break; 

            case SIMULAR_PARTIDA:
                juego->simular = true;
                break;

            default:
                // Mensaje de caracter no esperado?
                break;
        }
    }while(retorno != ERROR && ((ingreso != COMENZAR_PARTIDA && ingreso != SIMULAR_PARTIDA) || !juego_valido(juego)));

    
    
    return retorno;
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
        ingreso = leer_caracter(" Ingrese una letra: ");
        
        switch (ingreso){
            case CAMBIAR_POKEMON:
                cambiar_pokemon(juego);               
                break;
            case GIMNASIO:
                gimnasio_mostrar(juego->gimnasio_actual);
                enter_para_continuar();
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


/*
 *
 * 
*/
void menu_victoria(juego_t* juego){
    if(!juego){
        return;
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
                tomar_pokemon(juego);
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
                retorno = false;
                break;
            default:
                // Mensaje de caracter no esperado?
                break;
        }
    } while (ingreso != REINTENTAR && ingreso != FIN_PARTIDA); 
    
    return retorno;
}


bool jugar(juego_t* juego){
    bool derrota = false;

    juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);

    while(juego->gimnasio_actual && !derrota){
        derrota = menu_gimnasio(juego);

        if(derrota){
            derrota = menu_derrota(juego);
        }else{
            menu_victoria(juego);
        }

        juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);
    }

    return derrota;
}

bool simular(juego_t* juego){
    bool derrota = false;

    do{
        juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);

        while(gimnasio_entrenadores_restantes(juego->gimnasio_actual) > 0){
            if(batalla(juego)){
                gimnasio_sacar_ultimo_entrenador(juego->gimnasio_actual);
            }else{
                derrota = true;
            }
        }
    }while(juego->gimnasio_actual && !derrota);

    //TODO: Pantalla de carga falsa

    return derrota;
}

int main(void){
    bool derrota;
    juego_t* juego = crear_juego();

    //TODO: Pantalla de carga falsa

    if(menu_inicio(juego) == EXITO){
        if(juego->simular){
            derrota = simular(juego);
        }else{
             derrota = jugar(juego);
        }

        if(!derrota && !juego->gimnasio_actual){
            //MAestro pokemon
        }else{
            //Mensaje de derrota
        }
    }

    destruir_juego(juego);

}