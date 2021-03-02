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

/*
 * Crea la lista reservando la memoria necesaria. 
 * Recive el destructor de elementos si es necesario y un comparador
 * Devuelve un puntero a la lista creada o NULL en caso de error.
 */
heap_t* heap_crear(heap_comparador comparador,heap_destructor destructor);

/*
 * Recive un heap valido que pueda destruir el elemento
 * Se inserta un elemento en el heap en la posicion correcta
 * Devuelve 0 en caso de exito o -1 en caso de error
*/
int heap_insertar(heap_t* heap,void* elemento);

/*
 * Devuelve la cantidad de elementos almacenados en el heap
*/
size_t heap_elementos(heap_t* heap);

/*
 * Se saca del heap la raiz y se devuelve su el elemento 
*/
void* heap_extraer_raiz(heap_t* heap);


/*
 * Libera la memoria almacenada por el heap
*/
void heap_destruir(heap_t* heap);


#endif /* __HEAP_H__ */
