#include "utiles.h"
#include <stdlib.h>
#include <unistd.h>


#define EXITO 0
#define ERROR -1

void detener_tiempo(float seg){
    char comando[30];

    sprintf(comando,"sleep %0.1f",seg);
    system(comando);
}

void enter_para_continuar(){
    printf("Presione ENTER para continuar...\n");
    fflush(stdout);
    fflush(stdin);
    getchar();
    fflush(stdin);
}

/*
 * Recive un archivo valido, un string de tamaño BUFFER(1024) y el numero de linea por referencia
 * Se carga la linea leida al string
 * Si hay un error o se llega al final de archivo devuelve NULL
*/
char* leer_linea(FILE* archivo,char* memoria,size_t tam_memoria,int* num_linea){
    if(!archivo){
        return NULL;
    }

    if(!fgets(memoria,(int)tam_memoria,archivo)){
        return NULL;
    }

    size_t pos = strlen(memoria);

    if(pos == 0 || memoria[pos-1] != '\n'){
        char descartar[BUFFER];
        leer_linea(archivo,descartar,BUFFER,NULL);
    }
    memoria[pos-1] = 0;
    (*num_linea)++;
    return memoria;
}


char leer_caracter(const char* mensaje){
    char buffer[2] = "";

    printf("%s",mensaje);
    if(leer_linea(stdin,buffer,2,NULL) == NULL){
        buffer[0] = '\0';
    }

    return buffer[0];
}

/*
 * Imprime el mensaje recivido por pantalla
 * Lee el numero ingresado por el usuario y lo devuelve positivo
 * Si ocurre un error devuelve -1
*/
int obtener_numero(const char* mensaje){
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