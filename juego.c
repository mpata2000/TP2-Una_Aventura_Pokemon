#include "./Estructura/aventura_pokemon.h"
#include "./Utiles/interfaz.h"
#include "./Utiles/ascii_pokemon.h"
#include <time.h>

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
#define CHAR_MENU_INICIO "E, A, I, S"
#define CHAR_MENU_GYM "E, G, C, B"
#define CHAR_MENU_VIC "T, C, N"
#define CHAR_MENU_DERR "C, R, F"


/*
 * Recive una letra ingresada y lo que se esperaba
 * Se le informa por pantalla al usuario que caracteres se esperaban
 * Para el juego hasta que aprete enter
*/
void error_caracter_menu(const char* esperdo){
    printf(" Se esperaban alguno de los siguientes caraceres: %s\n",esperdo);
    enter_para_continuar();
}

void error_juego_valido(char* ingreso){
    printf(" El juego no puede ser iniciado sin tener al menos un gimnasio y un personaje\n");
    enter_para_continuar();
    *ingreso = '\0';
}

/*
 * menu de Incio recive un juego reservado en memoria
 * Carga un personaje y gimnasios al juego
 * Devuelve -1 en caso de error , 0 de lo contrario
*/
int menu_inicio(juego_t* juego){
    if(!juego){
        return ERROR;
    }
    char ingreso = '\0';
    int retorno = EXITO;

    do{
        mostrar_menu_inicio(juego);

        ingreso = leer_caracter(" Ingrese una letra: ");
        // Si ocurre un error ingreso va a ser '/0' no deberia ser un problema


        switch (ingreso){
            case AGREGAR_GYM:
                if(agregar_gimnasio(juego) == ERROR){
                    if(leer_caracter(" Ingrese N para continuar o cualquier otro caracter para terminar el juego: ") != NEXT){
                        retorno = ERROR;
                    }
                }else{
                    printf(BGRN" » Se cargo el archivo con Exito!"reset"\n");
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
                        printf(BGRN" » Se cargo el archivo con Exito!"reset"\n");
                        enter_para_continuar();
                    }

                }else{
                    printf("  Ya se cargo un personaje\n");
                    enter_para_continuar();
                }
                break; 

            case SIMULAR_PARTIDA:
                if(juego_valido(juego)){
                    juego->simular = true;
                }else{
                    error_juego_valido(&ingreso);
                }
                break;
            case COMENZAR_PARTIDA:
                if(!juego_valido(juego)){
                    error_juego_valido(&ingreso); 
                }
                break;
            default:
                error_caracter_menu(CHAR_MENU_INICIO);
                break;
        }
    }while(retorno != ERROR && ((ingreso != COMENZAR_PARTIDA && ingreso != SIMULAR_PARTIDA) || !juego_valido(juego)));
  
    return retorno;
}


/*
 * Pelea contra el gimnasio
 * Devuelve true si el personaje fue derrotado por el gimnasio
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
        ingreso = leer_caracter("  Ingrese una letra: ");
        
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
                error_caracter_menu(CHAR_MENU_GYM);
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
        ingreso = leer_caracter(" Ingrese una letra: ");
        
        switch (ingreso){
            case CAMBIAR_POKEMON:
                cambiar_pokemon(juego);
                break;
            case TOMAR_POKEMON:
                if (!gimnasio_pokemon_tomado(juego->gimnasio_actual)){
                    tomar_pokemon(juego);
                }else{
                    printf("  Ya se a tomado un Pokemon del Lider\n");
                    enter_para_continuar();
                }
                break; 
            case NEXT:
                gimnasio_destruir(juego->gimnasio_actual);
                juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);
                break;
            default:
                error_caracter_menu(CHAR_MENU_VIC);
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
        ingreso = leer_caracter(" Ingrese una letra: ");
        
        switch (ingreso){
            case CAMBIAR_POKEMON:
                cambiar_pokemon(juego);
                break;
            case FIN_PARTIDA:
                //gimnasio_destruir(juego->gimnasio_actual);  Esto causaba doble free
                //Terminar Juego
                break; 
            case REINTENTAR:
                retorno = false;
                break;
            default:
                error_caracter_menu(CHAR_MENU_DERR);
                break;
        }
    } while (ingreso != REINTENTAR && ingreso != FIN_PARTIDA); 
    
    return retorno;
}

/*
 * Juega un partida entera
 * Devuelve true si el jugador fue derrotado
*/
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
        juego->gimnasios_derrotados++;
    }

    return derrota;
}

/*
 * Simula una partida entera
 * Devuelve true si el jugador fue derrotado
*/
bool simular(juego_t* juego){
    bool derrota = false;
    

    do{
        if(juego->gimnasio_actual){
            gimnasio_destruir(juego->gimnasio_actual);
        }
        juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);

        //Si el gimnasio_actual es NULL lo saltea
        while(gimnasio_entrenadores_restantes(juego->gimnasio_actual) > 0){
            if(batalla(juego)){
                gimnasio_sacar_ultimo_entrenador(juego->gimnasio_actual);
            }else{
                derrota = true;
            }
        }
        juego->gimnasios_derrotados++;
    }while(juego->gimnasio_actual && !derrota);

    pantalla_de_carga("Simulando...");

    return derrota;
}

int main(void){
    srand((unsigned int)time(0));
    bool derrota;
    juego_t* juego = crear_juego();

    mostrar_carga_juego();


    if(menu_inicio(juego) == EXITO){
        if(juego->simular){
            derrota = simular(juego);
        }else{
             derrota = jugar(juego);
        }

        if(!derrota && !juego->gimnasio_actual){
            pantalla_maestro_pokemon(juego);
        }else{
            mostrar_pantalla_derrota(juego);
        }
        detener_tiempo(5);
    }
    system("clear");
    destruir_juego(juego);
    return 0;
}