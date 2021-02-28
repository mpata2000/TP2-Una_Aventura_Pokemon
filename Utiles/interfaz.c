#include "interfaz.h"
#include "../Estructura/gimnasio.h"
#include "../Estructura/personaje.h"
#include "../TDAs/heap.h"


/***
 *           d8888                            888                                  8888888b.          888                                               
 *          d88888                            888                                  888   Y88b         888                                               
 *         d88P888                            888                                  888    888         888                                               
 *        d88P 888 888  888  .d88b.  88888b.  888888 888  888 888d888 8888b.       888   d88P .d88b.  888  888  .d88b.  88888b.d88b.   .d88b.  88888b.  
 *       d88P  888 888  888 d8P  Y8b 888 "88b 888    888  888 888P"      "88b      8888888P" d88""88b 888 .88P d8P  Y8b 888 "888 "88b d88""88b 888 "88b 
 *      d88P   888 Y88  88P 88888888 888  888 888    888  888 888    .d888888      888       888  888 888888K  88888888 888  888  888 888  888 888  888 
 *     d8888888888  Y8bd8P  Y8b.     888  888 Y88b.  Y88b 888 888    888  888      888       Y88..88P 888 "88b Y8b.     888  888  888 Y88..88P 888  888 
 *    d88P     888   Y88P    "Y8888  888  888  "Y888  "Y88888 888    "Y888888      888        "Y88P"  888  888  "Y8888  888  888  888  "Y88P"  888  888 
 *                                                                                                                                                      
 *                                                                                                                                                      
 *                                                                                                                                                      
 */

/***
 *                                                                                                                                       
 *                                                                                                                                       
 *    PPPPPPPPPPPPPPPPP                   kkkkkkkk                                                                                       
 *    P::::::::::::::::P                  k::::::k                                                                                       
 *    P::::::PPPPPP:::::P                 k::::::k                                                                                       
 *    PP:::::P     P:::::P                k::::::k                                                                                       
 *      P::::P     P:::::P  ooooooooooo    k:::::k    kkkkkkk eeeeeeeeeeee       mmmmmmm    mmmmmmm      ooooooooooo   nnnn  nnnnnnnn    
 *      P::::P     P:::::Poo:::::::::::oo  k:::::k   k:::::kee::::::::::::ee   mm:::::::m  m:::::::mm  oo:::::::::::oo n:::nn::::::::nn  
 *      P::::PPPPPP:::::Po:::::::::::::::o k:::::k  k:::::ke::::::eeeee:::::eem::::::::::mm::::::::::mo:::::::::::::::on::::::::::::::nn 
 *      P:::::::::::::PP o:::::ooooo:::::o k:::::k k:::::ke::::::e     e:::::em::::::::::::::::::::::mo:::::ooooo:::::onn:::::::::::::::n
 *      P::::PPPPPPPPP   o::::o     o::::o k::::::k:::::k e:::::::eeeee::::::em:::::mmm::::::mmm:::::mo::::o     o::::o  n:::::nnnn:::::n
 *      P::::P           o::::o     o::::o k:::::::::::k  e:::::::::::::::::e m::::m   m::::m   m::::mo::::o     o::::o  n::::n    n::::n
 *      P::::P           o::::o     o::::o k:::::::::::k  e::::::eeeeeeeeeee  m::::m   m::::m   m::::mo::::o     o::::o  n::::n    n::::n
 *      P::::P           o::::o     o::::o k::::::k:::::k e:::::::e           m::::m   m::::m   m::::mo::::o     o::::o  n::::n    n::::n
 *    PP::::::PP         o:::::ooooo:::::ok::::::k k:::::ke::::::::e          m::::m   m::::m   m::::mo:::::ooooo:::::o  n::::n    n::::n
 *    P::::::::P         o:::::::::::::::ok::::::k  k:::::ke::::::::eeeeeeee  m::::m   m::::m   m::::mo:::::::::::::::o  n::::n    n::::n
 *    P::::::::P          oo:::::::::::oo k::::::k   k:::::kee:::::::::::::e  m::::m   m::::m   m::::m oo:::::::::::oo   n::::n    n::::n
 *    PPPPPPPPPP            ooooooooooo   kkkkkkkk    kkkkkkk eeeeeeeeeeeeee  mmmmmm   mmmmmm   mmmmmm   ooooooooooo     nnnnnn    nnnnnn
 *                                                                                                                                       
 *                                                                                                                                       
 *                                                                                                                                       
 *                                                                                                                                       
 *                                                                                                                                       
 *                                                                                                                                       
 *                                                                                                                                       
 */

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
        printf("- 'E' para Ingresar Entrenador Principal"); // Cambio de color
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