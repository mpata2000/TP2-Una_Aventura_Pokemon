#include "archivos.h"
#include <stdbool.h>

#define FORMATO_GIMNASIO "%c;%99[^;];%5i;%1i\n"       //G;nombre_gimnasio; dificultad; id_puntero_funcion
#define CAMPOS_GIMNASIO 4
#define FORMATO_ENTRENADOR "%c;%99[^\n]\n"          //L;nombre_lider || E;nombre_entrenador  
#define CAMPOS_ENTRENADOR 2
#define FORMATO_POKEMON "%c;%99[^;];%5i;%5i;%5i\n"     //P;nombre_pokemon1; velocidad; ataque; defensa
#define CAMPOS_POKEMON 5
#define BUFFER 1024






/*
 * Recive un archivo valido, un string de tamaño BUFFER y el numero de linea por referencia
 * Se carga la linea leida al string
 * Si hay un error o se llega al final de archivo devuelve NULL
*/
void* leer_linea(FILE* archivo,char linea[BUFFER],int* num_linea){
    if(!archivo){
        return NULL;
    }
    (*num_linea)++;
    return fgets(linea,BUFFER,archivo);
}

/*
 * Lee un string con el formato: FORMATO_GIMNASIO y llena los parametros recividos
 * con lo que se leyo
 * Si tuvo exito la lectura devuelve CAMPOS_GIMNASIO
*/
int lectura_formato_gimnasio(char linea[BUFFER],char* tipo,char nombre[MAX_NOMBRE],int* dificultad,int* id_funcion){
    return sscanf(linea,FORMATO_GIMNASIO,tipo,nombre,dificultad,id_funcion);
}

/*
 * Lee un string con el formato: FORMATO_ENTRENADOR y llena los parametros recividos
 * con lo que se leyo
 * Si tuvo exito la lectura devuelve CAMPOS_ENTRENADOR
*/
int lectura_formato_entrenador(char linea[BUFFER],char* tipo,char nombre[MAX_NOMBRE]){
    return sscanf(linea,FORMATO_ENTRENADOR,tipo,nombre);
}

/*
 * Lee un string con el formato: FORMATO_POKEMON y llena los parametros recividos
 * con lo que se leyo
 * Si tuvo exito la lectura devuelve CAMPOS_POKEMON
*/
int lectura_formato_pokemon(char linea[BUFFER],char nombre[MAX_NOMBRE],int* velocidad,int* ataque,int* defensa){
    char tipo;
    return sscanf(linea,FORMATO_POKEMON,&tipo,nombre,velocidad,ataque,defensa);
}

pokemon_t* leer_pokemon(char linea[BUFFER],int* num_linea,bool* error_lectura){
    if(linea[0] != POKEMON){
        return  NULL;
    }

    char nombre[MAX_NOMBRE];
    int velocidad;
    int ataque;
    int defensa;

    if (lectura_formato_pokemon(linea,nombre,&velocidad,&ataque,&defensa) != CAMPOS_POKEMON){
        *error_lectura = true;
        //mensaje_error_pokemon();
        return NULL;
    }
    
    return pokemon_crear(nombre,velocidad,ataque,defensa);
}

entrenador_t* leer_entrenador(FILE* archivo,char linea[BUFFER],int* num_linea,bool* error_lectura){
    if(!archivo){
        return NULL;
    }

    if(linea[0] != LIDER && linea[0] != ENTRENADOR){
        (*error_lectura) = true;
        return NULL;
    }

    char tipo;
    char nombre[MAX_NOMBRE];


    if(lectura_formato_entrenador(linea,&tipo,nombre) != CAMPOS_ENTRENADOR){
        //mensaje_error_entrenador();
        return NULL;
    }

    entrenador_t* entrenador = entrenador_crear(tipo,nombre);


    while (leer_linea(archivo,linea,num_linea) && linea[0] == POKEMON && (lista_elementos(entrenador->pokemon) < MAX_POKEMON) && !(*error_lectura)){
        pokemon_t* pokemon = leer_pokemon(linea,num_linea,error_lectura);
        if(pokemon){
            if(lista_insertar(entrenador->pokemon,pokemon) == ERROR){
                return NULL;
            }
        }
    }

    if(*error_lectura){
        return NULL;
    }

    return entrenador;
}

gimnasio_t* leer_gimnasio(FILE* archivo,char linea[BUFFER],int* num_linea,bool* error_lectura,void* estado_archivo){
    if(!archivo){
        return NULL;
    }

    char tipo;
    char nombre[MAX_NOMBRE];
    int dificultad;
    int id_funcion;

    int leidos = lectura_formato_gimnasio(linea,&tipo,nombre,&dificultad,&id_funcion);

    if(tipo != GIMNASIO || leidos != CAMPOS_GIMNASIO){
        *error_lectura = true;
        //mensaje_error_gimnasio();
        return NULL;
    }

    gimnasio_t* gym = gimnasio_crear(nombre,dificultad,id_funcion);

    estado_archivo = leer_linea(archivo,linea,num_linea);

    if(linea[0] != LIDER && estado_archivo != NULL){
        *error_lectura = true;
        //mensaje_error_lider();
        return NULL; 
    }

    entrenador_t* lider = leer_entrenador(archivo,linea,num_linea,error_lectura);
    if(gimnasio_insertar_entrenador(gym,lider) == ERROR){
        return NULL;
    }
    
    while (linea[0] == ENTRENADOR && estado_archivo != NULL){
        entrenador_t* entrenador = leer_entrenador(archivo,linea,num_linea,error_lectura);
        if(gimnasio_insertar_entrenador(gym,entrenador) == ERROR){
            return NULL;
        }
    }    
    return gym;
}


heap_t* lectura_archivo_gimnasios(const char* ruta_archivo){

    heap_t* heap = heap_crear(gimnasio_comparar_dificultades,gimnasio_destruir);
    if(!heap){
        return NULL;
    }

    FILE* archivo = fopen(ruta_archivo,"r");
    if(!archivo){
        heap_destruir(heap);
        return NULL;
    }

    char linea[BUFFER]; 
    int num_linea = 0;
    bool error_lectura = false;

    void* estado_archivo = leer_linea(archivo,linea,&num_linea);

    if(linea[0] != GIMNASIO){
        error_lectura = true;
        //mensaje_error_gimnasio();
    }

    while (linea[0] == GIMNASIO && !error_lectura && estado_archivo != NULL){

        gimnasio_t* gym = leer_gimnasio(archivo,linea,&num_linea,&error_lectura,estado_archivo);
        if(gym){
            heap_insertar(heap,gym);
        }
    }

    if(error_lectura){
        heap_destruir(heap);
        return NULL;
    }
    
    fclose(archivo);
    return heap;
}