#include "heap.h"
#include <stdbool.h>



/*
 * Devuelve la posicion del padre de la posicion dada
*/
size_t posicion_padre(size_t pos){
    return (pos-1)/2;
}

/*
 * Devuelve la posicion del hijo derecho de la posicion dada
*/
size_t posicion_hijo_derecho(size_t pos){
    return (pos*2)+2;
}

/*
 * Devuelve la posicion del hijo izquierdo de la posicion dada
*/
size_t posicion_hijo_izquierdo(size_t pos){
    return (pos*2)+1;
}

heap_t* heap_crear(heap_comparador comparador,heap_destructor destructor){
    if(!comparador){
        return NULL;
    }
    heap_t* heap = calloc(1,sizeof(heap_t));
    heap->comparador = comparador;
    heap->destructor = destructor;
    return heap;
}

bool heap_vacio(heap_t* heap){
    if(!heap){
        return true;
    }
    return !heap->tope;
}

/*
 *
*/
void swap(void** vector,size_t i,size_t j){
    void* aux = vector[i];
    vector[i] = vector[j];
    vector[j] = aux;
}


/*
 * 
*/
void sift_up(heap_t* heap,size_t pos){
    if(heap_vacio(heap) || pos==0){
        return;
    }

    size_t pos_padre = posicion_padre(pos);

    if(heap->comparador(heap->vector[pos],heap->vector[pos_padre]) < 0){
        swap(heap->vector,pos,pos_padre);
        sift_up(heap,pos_padre);
    }
}

/*
 *
*/
void sift_down(heap_t* heap,size_t pos){
    if(heap_vacio(heap)){
        return;
    }

    size_t pos_izquierdo = posicion_hijo_izquierdo(pos);
    if(pos_izquierdo >= heap->tope){
        return;
    }
    size_t pos_menor = pos_izquierdo;
    size_t pos_derecha = posicion_hijo_derecho(pos);

    if(pos_derecha < heap->tope){
        if(heap->comparador(heap->vector[pos_derecha],heap->vector[pos_menor]) < 0){
            pos_menor = pos_derecha;
        }
    }

    if(heap->comparador(heap->vector[pos],heap->vector[pos_menor]) > 0){
        swap(heap->vector,pos,pos_menor);
        sift_down(heap,pos_menor);
    }
}

int heap_insertar(heap_t* heap,void* elemento){
    if(!heap){
        return ERROR;
    }

    void* aux = realloc(heap->vector,sizeof(void*) * (heap->tope+1));
    if(!aux){
        return ERROR;
    }

    heap->vector = aux;
    heap->vector[heap->tope] = elemento;
    sift_up(heap,heap->tope);
    heap->tope++;
    return EXITO;
}

/*
 * Devuelve la cantidad de elementos almacenados en el heap
*/
size_t heap_elementos(heap_t* heap){
    if(!heap){
        return 0;
    }
    return heap->tope;
}

void* heap_extraer_raiz(heap_t* heap){
    if(heap_vacio(heap)){
        return NULL;
    }

    void* elemento = heap->vector[0];
    swap(heap->vector,0,heap->tope-1);

    void* aux = realloc(heap->vector,sizeof(void*) * (heap->tope-1));
    /*if(!aux){
        return elemento; // Chequear despues
    }*/
    heap->vector = aux;

    heap->tope--;
    if(heap->tope > 0){
        sift_down(heap,0);
    }

    return elemento;
}

void heap_destruir(heap_t* heap){
    if(!heap){
        return;
    }

    if(heap->destructor){
        for(int i=0; i < heap->tope;i++){
            heap->destructor(heap->vector[i]);
        }
    }
    free(heap->vector);
    free(heap);
}

