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
#define MAX_LECTURA_MENU 2

typedef struct juego{
    heap_t* gimnasios;
    gimnasio_t* gimnasio_actual;
    personaje_t* personaje;
    bool simular;
}juego_t;



juego_t* iniciar_juego(){
    juego_t* juego = calloc(1,sizeof(juego_t));

    juego->gimnasios = heap_crear(gimnasio_comparar_dificultades,gimnasio_destruir);
    juego->simular = false;
    
    return juego;
}

char leer_caracter(){
    char buffer[MAX_LECTURA_MENU] = "";

    printf("Ingrese una letra: ");
    if(leer_linea(stdin,buffer,MAX_LECTURA_MENU,NULL) == NULL){
        buffer[0] = '\0';
    }

    return buffer[0];
}

void destruir_juego(juego_t* juego){
    if (!juego){
        return;
    }

    heap_destruir(juego->gimnasios);
    gimnasio_destruir(juego->gimnasio_actual);
    personaje_destruir(juego->personaje);
    free(juego);
}

/*
 * Recive un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_gimnasio(juego_t* juego){
    char ruta_archivo[MAX_RUTA_ARCHIVO] = "./Gimnasios/";
    char nombre_archivo[MAX_NOMBRE];

    system("clear");
    mostrar_menu_inicio();
    info_cargar_gimnasio();
    printf(" Ingrese el nombre del archivo: ");

    if(leer_linea(stdin,nombre_archivo,MAX_NOMBRE,NULL) == NULL){

    }

    strcat(ruta_archivo,nombre_archivo);
    if(lectura_archivo_gimnasios(ruta_archivo,juego->gimnasios) == ERROR){
        printf("\nSe leyeron correctamente %i gimnasios\n",heap_elementos(juego->gimnasio_actual));
        printf("Si desea continuar presione N\n");
    }
}

/*
 * Recive un juego valido
 * Carga un archivo de gimnasio al heap del juego
 * Devuelve 0 si todo ocurrio con EXITO de lo contrario devuelve -1
*/
int agregar_personaje(juego_t* juego){    
    char ruta_archivo[MAX_RUTA_ARCHIVO] = "./Personajes/";
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

        ingreso = leer_caracter();
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
 * Imprime el mensaje recivido por pantalla
 * Lee el numero ingresado por el usuario y lo devuelve positivo
 * Si ocurre un error devuelve -1
*/
int obtener_pos_pokemon(const char* mensaje){
    char ingreso[6];
    int pos;

    printf("%s");
    if(leer_linea(stdin,ingreso,6,NULL) == NULL){
        return ERROR;
    }

    pos = atoi(ingreso);
    if(pos == 0){
        return ERROR;
    }
    return abs(pos);
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
        
        pos_pkm_1 = obtener_pos_pokemon("Ingresar la posicion del Pokemon de la Party: ");
    }while(pos_pkm_1 >= MAX_POKEMON_PARTY || pos_pkm_1 == ERROR);

    do{
        if (pos_pkm_2 == ERROR){
            printf("El numero ingresado no es valido\n");
            printf("Recuerde de solo ingresar numeros\n");
        }
        
        pos_pkm_2 = obtener_pos_pokemon("Ingresar la posicion del Pokemon Obtenido: ");
    }while(pos_pkm_2 == ERROR);

    if(personaje_cambiar_pokemon(juego->personaje,pos_pkm_1,pos_pkm_2) == EXITO){
        printf("Los Pokemon han sido cambiado con exito.\n");
    }else{
        printf("Ocurrio un error al cambiar los Pokemon\n");
        printf("Esto pudo ocrrir porque la posicion no existia o el Pokemon ya estaba en la party\n");
    }
    enter_para_continuar();
}

void menu_gimnasio(juego_t* juego){
    if(!juego){
        return;
    }

    char ingreso = '\0';
    bool derrotado = false;
    juego->gimnasio_actual = heap_extraer_raiz(juego->gimnasios);
    if(!juego->gimnasio_actual){
        return;
    }

    while(gimnasio_entrenadores_restantes(juego->gimnasio_actual) > 0 && !derrotado){
        menu_gimnasio(juego);
        ingreso = leer_caracter();
        
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
                break;
            default:
                // Mensaje de caracter no esperado?
                break;
        }
    }

    if(derrotado){
        menu_derrota();
    }else{

    }
}

void menu_batalla(){
    
}

void menu_victoria(juego_t* juego){
    if(!juego){
        return ERROR;
    }
    

}

void menu_derrota(){
    
}


int main(void){

    juego_t juego;


}
