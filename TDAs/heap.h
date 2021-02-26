#ifndef __HEAP_H__
#define __HEAP_H__

#include <stdlib.h>

#define EXITO 0
#define ERROR -1


/*
 * Comparador de elementos. Recibe dos elementos y devuelve:
 *    - 0 en caso de ser iguales, 
 *    - mayor a 0 si el primer elemento es mayor al segundo,
 *    - menor a 0 si el primer elemento es menor al segundo.
 */
typedef int (*heap_comparador)(void*, void*);

/*
 * Destructor de elementos. Libera los elementos almacenados en el heap
 */
typedef void (*heap_destructor)(void*);

typedef struct heap{
    void** vector;
    heap_comparador comparador;
    heap_destructor destructor;
    size_t tope;
}heap_t;


heap_t* heap_crear(heap_comparador comparador,heap_destructor destructor);

int heap_insertar(heap_t* heap,void* elemento);

/*
 * Devuelve la cantidad de elementos almacenados en el heap
*/
size_t heap_elementos(heap_t* heap);

void* heap_extraer_raiz(heap_t* heap);

void heap_destruir(heap_t* heap);


#endif /* __HEAP_H__ */
