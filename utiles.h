#ifndef __UTILES_H__
#define __UTILES_H__

#include <stdio.h>

#define BUFFER 1024

/*
 * Para la ejecucion del programa por el tiempo recibido
*/
void detener_tiempo(float seg);

/*
 * Se le informa al usuario que se a detenido el programa
 * y que para continuar tiene que apretar ENTER
 */
void enter_para_continuar();

/*
 * Recibe un archivo valido, un string, el tamaño del string y el numero de linea por referencia si es necesario
 * Se carga la linea leida al string
 * Si hay un error o se llega al final de archivo devuelve NULL
*/
char* leer_linea(FILE* archivo,char* memoria,size_t tam_memoria,int* num_linea);

/*
 * Para el juego hasta que el usuario aprete N
*/
char leer_caracter(const char* mensaje);

/*
 * Imprime el mensaje recivido por pantalla
 * Lee el numero ingresado por el usuario y lo devuelve positivo
 * Si ocurre un error devuelve -1
*/
int obtener_numero(const char* mensaje);


#endif /*__UTILES_H__*/