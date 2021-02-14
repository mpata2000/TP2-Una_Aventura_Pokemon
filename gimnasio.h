#ifndef __GIMNASIO_H__
#define __GIMNASIO_H__

#include <stdlib.h>
#include <string.h>
#include "batallas.h"
#include "lista.h"
#include "heap.h"

#define MAX_NOMBRE 100

typedef struct pokemon{
    char nombre[MAX_NOMBRE];
    int ataque;
    int defensa;
    int velocidad;
    int evs;
}pokemon_t;

typedef struct entrenador{
    char nombre[MAX_NOMBRE];
    lista_t pokemon;
}entrenador_t;

typedef struct gimnasio{
    char nombre[MAX_NOMBRE];
    int dificultad;
    int id_funcion;
    lista_t  entrenadores;
};



#endif //__GIMNASIO_H__