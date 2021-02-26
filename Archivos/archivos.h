#ifndef __ARCHIVOS_H__
#define __ARCHIVOS_H__

#include <stdio.h>
#include "../Estructura/gimnasio.h"
#include "../Estructura/personaje.h"
#include "../TDAs/heap.h"
#include "../utiles.h"

#define MAX_RUTA_ARCHIVO 150


/*
 * Recive un archivo de gimnasios y un heap valido que lo pueda destruir
 * Leera todos los gimnasios validos y lo insertara en el heap
 * Si se leyo todo el archivo correctamente devuelve 0(EXITO)
 * de lo contrario devuelve -1(ERROR)
*/
int lectura_archivo_gimnasios(const char* ruta_archivo,heap_t* heap);

/*
 * Recive un archivo de personaje valido.
 * Llena un personaje_t con los contenidos del archivo
 * Si ocurre algun error devuelve NULL.
*/
personaje_t* lectura_archivo_personaje(const char* ruta_archivo);

#endif /* __ARCHIVOS_H__ */
