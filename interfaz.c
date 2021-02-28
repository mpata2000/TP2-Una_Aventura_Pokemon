#include "interfaz.h"
#include "./Estructura/gimnasio.h"
#include "./Estructura/personaje.h"
#include "./TDAs/heap.h"


void menu_inicio_header(){
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                         MENU INICIO                                         #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");

}

/*
 * E: Ingresa el archivo del entrenador principal.
 * A: Agrega un gimnasio al árbol de gimnasios.
 * I: Comienza la partida.
 * S: Simula la partida.
*/
void mostrar_menu_inicio(juego_t* juego){
    system("clear");

    menu_inicio_header();

    printf("#                                                                                             #\n");
    printf("#   Presione:                                                                                 #\n");
    printf("#                                                                                             #\n");
    printf("#   ");
    if(juego->personaje){
        printf("- 'E' para Ingresar Entrenador Principal");
    }else{
        printf("- 'E' para Ingresar Entrenador Principal");
    }
    printf("              - 'A' para Agregar un Gimnasio      #\n");

    // TODO: Cambiar color cuando la partida sea valida
    printf("#   - 'I' Comenzar la partida                             - 'S' Simular la Partida            #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");


}

void info_cargar_personaje(){
    system("clear");
    menu_inicio_header();

    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#   Esta Ingresando el Entrenador Principal recuerde:                                         #\n");
    printf("#      - El archivo tiene que estar en Archivos/Personaje                                     #\n");
    printf("#      - El archivo tiene que tener el formato que se encuentra en el README                  #\n");
    printf("#      - Solo puede cargar un Entrenador Principal por partida                                #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
}



void info_cargar_gimnasio(){
    system("clear");
    menu_inicio_header();

    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#   Esta Ingresando uno o varios Gimnasios:                                                   #\n");
    printf("#      - El archivo tiene que estar en Archivos/Gimnasios                                     #\n");
    printf("#      - El archivo tiene que tener el formato que se encuentra en el README                  #\n");
    printf("#      - Puede haber uno o mas gimnasios en el archivo                                        #\n");
    printf("#      - Todos los gimnasios tienen que tener un lider con Pokemon                            #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
}

/*
 * E: Muestra al entrenador principal junto a sus Pokémon.
 * G: Muestra la información del gimnasio actual.
 * C: Permite cambiar los Pokémon de batalla.
 * B: Realiza la próxima batalla planificada.
 *      - Si se derrotó al líder del gimnasio se deberá mostrar el Menú de victoria
 *      - Si se sufre una derrota frente a cualquier entrenador se deberá mostrar el Menú de derrot
*/
void mostrar_menu_gimnasio(juego_t* juego){
    system("clear");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                        MENU GIMNASIO                                        #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#   Ingrese:                                                                                  #\n");
    printf("#                                                                                             #\n");
    printf("#   - 'E' Mostrar Entrenador Principal                    - 'G' Mostrar Gimnasio actual       #\n");
    printf("#   - 'C' Cambiar Pokemon                                 - 'B' Proxima batalla               #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
}

/*
 * Aquí se mostrará la información de la batalla, Pokémon vs Pokémon.
 * Deberá ser informativa: mostrar cuál es el Pokémon del rival y cuál es el tuyo, sus características y el resultado del
 * combate.
 * 
 * N: Próximo combate.
*/
void mostrar_batalla(juego_t* juego,pokemon_t* pkm_jugador,pokemon_t* pkm_entrenador){
    system("clear");
}


/*
 * C: Permite cambiar los Pokémon de batalla.
 * R: Reintenta el gimnasio.
 * F: Finaliza la partida.
*/
void mostrar_menu_derrota(juego_t* juego){
    system("clear");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                         MENU DERROTA                                        #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#   Su Party ha sido derrotada, pero eso no significa que usted haya perdido. Usted puede     #\n");
    printf("#   cambiar su Pokemon y reintentar el gimnasio, derrotar al entrenador que te gano y seguir  #\n");
    printf("#   tu aventura para converitrte en un Maestro Pokemon                                        #\n");
    printf("#                                                                                             #\n");
    printf("#   Ingrese:                                                                                  #\n");
    printf("#                                                                                             #\n");
    printf("#   - 'C' Cambiar Pokemon                                                                     #\n");
    printf("#   - 'R' Reintentar el gimnasio                            - 'F' Finalizar la Partida        #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
}


/*
 * T: Toma un Pokémon del líder y lo incorpora en los Pokémon obtenidos del jugador.
 *       - Una vez realizada dicha operación, esta opción desaparece del menú.
 * C: Permite cambiar los Pokémon de batalla.
 * N: Próximo gimnasio.
 *       - Si no hay próximo gimnasio, se deberá notificar al usuario que se convirtió en Maestro Pokémon.
*/
void mostrar_menu_victoria(juego_t* juego){
    system("clear");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                         MENU VICTORIA                                       #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#                                                                                             #\n");
    printf("#   Presione:                                                                                 #\n");
    printf("#                                                                                             #\n");
    printf("#   - 'T' Tomar Pokemon del Lider                         - 'C' Cambiar Pokemon               #\n");
    printf("#   - 'N' Pelear el Proximo Gimnasio                                                          #\n");
    printf("#                                                                                             #\n");
    printf("###############################################################################################\n");
    printf("#                                                                                             #\n");
}

void pantalla_maestro_pokemon(juego_t* juego){
    system("clear");
}