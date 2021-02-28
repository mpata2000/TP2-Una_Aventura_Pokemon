#include "archivos.h"
#include <stdbool.h>



#define FORMATO_GIMNASIO "%c;%99[^;];%8i;%5i\n"       //G;nombre_gimnasio; dificultad; id_puntero_funcion
#define ERROR_FORMATO_GYM "G;nombre_gimnasio; dificultad; id_puntero_funcion" 
#define CAMPOS_GIMNASIO 4
#define FORMATO_ENTRENADOR "%c;%99[^\n]\n"          //L;nombre_lider || E;nombre_entrenador  
#define ERROR_FORMATO_ENTRENADOR "E;nombre_entrenador" 
#define ERROR_FORMATO_LIDER "L;nombre_lider" 
#define CAMPOS_ENTRENADOR 2
#define FORMATO_POKEMON "%c;%99[^;];%8i;%8i;%8i\n"     //P;nombre_pokemon1; velocidad; ataque; defensa
#define ERROR_FORMATO_POKEMON "P;nombre_pokemon; velocidad; ataque; defensa" 
#define CAMPOS_POKEMON 5



/*
 * Recive la linea leida, el numero de esa linea y el formato que se esperaba
*/
void mensaje_error_formato(char linea[BUFFER],int num_linea,char formato_esperado[BUFFER]){
    printf(" ERROR: \n");
    printf(" En la linea %i se leyo:\n %s\n",num_linea,linea);
    printf(" Se esperaba algo del formato: %s\n",formato_esperado);
}


/*
 * Lee un string con el formato: FORMATO_GIMNASIO y llena los parametros recividos
 * con lo que se leyo.
 * Leera solo los primeros:
 *    - 99 caracteres del nombre
 *    - 8 numeros de la dificultad
 *    - 5 numeros de la id_funcion
 * Si tuvo exito la lectura devuelve CAMPOS_GIMNASIO
*/
int lectura_formato_gimnasio(char linea[BUFFER],char* tipo,char nombre[MAX_NOMBRE],int* dificultad,int* id_funcion){
    return sscanf(linea,FORMATO_GIMNASIO,tipo,nombre,dificultad,id_funcion);
}

/*
 * Lee un string con el formato: FORMATO_ENTRENADOR y llena los parametros recividos
 * con lo que se leyo
 * Leera solo los primeros 99 caracteres del nombre
 * Si tuvo exito la lectura devuelve CAMPOS_ENTRENADOR = 2
*/
int lectura_formato_entrenador(char linea[BUFFER],char* tipo,char nombre[MAX_NOMBRE]){
    return sscanf(linea,FORMATO_ENTRENADOR,tipo,nombre);
}

/*
 * Lee un string con el formato: FORMATO_POKEMON y llena los parametros recividos
 * con lo que se leyo.
 * Leera solo los primeros:
 *    - 99 caracteres del nombre
 *    - 8 numeros de los stats
 * Si tuvo exito la lectura devuelve CAMPOS_POKEMON = 5
*/
int lectura_formato_pokemon(char linea[BUFFER],char nombre[MAX_NOMBRE],int* velocidad,int* ataque,int* defensa){
    char tipo;
    return sscanf(linea,FORMATO_POKEMON,&tipo,nombre,velocidad,ataque,defensa);
}

/*
 * Recive un string de un pokemon y lo crea
 * Si hubo algun error devuelve NULL y error_lectura se vuelve true.
*/
pokemon_t* leer_pokemon(char linea[BUFFER],int* num_linea,bool* error_lectura){
    if(linea[0] != POKEMON){
        *error_lectura = true;
        return  NULL;
    }

    char nombre[MAX_NOMBRE];
    int velocidad;
    int ataque;
    int defensa;

    if (lectura_formato_pokemon(linea,nombre,&velocidad,&ataque,&defensa) != CAMPOS_POKEMON){
        *error_lectura = true;
        mensaje_error_formato(linea,*num_linea,ERROR_FORMATO_POKEMON);
        return NULL;
    }
    
    return pokemon_crear(nombre,velocidad,ataque,defensa);
}

/*
 * Recive: un string de entrenador/lider, un archivo de gimnasio,
 *         el numero de linea leido y el estado de lectura.
 * Se va a crear un pokemon con data leida y va a leer todos su pokemon:ç.
 * Devuelve: UN entrenador completo si se
 * 
*/
entrenador_t* leer_entrenador(FILE* archivo,char linea[BUFFER],int* num_linea,bool* error_lectura){
    if(!archivo){
        return NULL;
    }

    char tipo;
    char nombre[MAX_NOMBRE];

    if(lectura_formato_entrenador(linea,&tipo,nombre) != CAMPOS_ENTRENADOR){
        (*error_lectura) = true;
        if (linea[0] == LIDER){
            mensaje_error_formato(linea,*num_linea,ERROR_FORMATO_LIDER);
        }else{
            mensaje_error_formato(linea,*num_linea,ERROR_FORMATO_ENTRENADOR);
        }   
        return NULL;
    }

    entrenador_t* entrenador = entrenador_crear(tipo,nombre);

    while (leer_linea(archivo,linea,BUFFER,num_linea) && linea[0] == POKEMON && (lista_elementos(entrenador->pokemon) < MAX_POKEMON_ENTRENADOR) && !(*error_lectura)){
        pokemon_t* pokemon = leer_pokemon(linea,num_linea,error_lectura);
        if(entrenador_agregar_pokemon(entrenador,pokemon) == ERROR){
            entrenador_destruir(entrenador);
            return NULL;
        }
    }

    if(entrenador_cantidad_pokemon(entrenador) == 0){
        printf("Todos los entrenadores tienen que tener al menos un pokemon\n");
        (*error_lectura) = true;
    }

    if(*error_lectura){
        entrenador_destruir(entrenador);
        return NULL;
    }

    return entrenador;
}

/*
 * Recive un numero y devuelve una id de funcion de batalla valida
 * Entre 0 y 4
*/
int id_funcion_valida(int id_funcion){
    return abs(id_funcion)%MAX_FUNCIONES_BATALLA;
}

/*
 * Lee un gimnasio de un archivo y todos sus entrenadores
 * Devolvera:
 *   - Un gimnasio_t* si se leyo todo correctamente
 *   - NULL si hubo un error
*/
gimnasio_t* leer_gimnasio(FILE* archivo,char linea[BUFFER],int* num_linea,bool* error_lectura,char* estado_archivo){
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
        mensaje_error_formato(linea,*num_linea,ERROR_FORMATO_GYM);
        return NULL;
    }

    gimnasio_t* gym = gimnasio_crear(nombre,dificultad,id_funcion_valida(id_funcion));

    estado_archivo = leer_linea(archivo,linea,BUFFER,num_linea);

    if(!estado_archivo || linea[0] != LIDER){
        *error_lectura = true;
        mensaje_error_formato(linea,*num_linea,ERROR_FORMATO_LIDER);
        gimnasio_destruir(gym);
        return NULL; 
    }

    entrenador_t* lider = leer_entrenador(archivo,linea,num_linea,error_lectura);
    if(gimnasio_insertar_entrenador(gym,lider) == ERROR){
        return NULL;
    }
    
    while (estado_archivo && linea[0] == ENTRENADOR && !(*error_lectura)){
        entrenador_t* entrenador = leer_entrenador(archivo,linea,num_linea,error_lectura);
        if(gimnasio_insertar_entrenador(gym,entrenador) == ERROR){
            gimnasio_destruir(gym);
            return NULL;
        }
    }    
    return gym;
}

/*
 * Recive un archivo de gimnasios y un heap que lo pueda destruir
 * Leera todos los gimnasios validos y lo insertara en el heap
 * Si se leyo todo el archivo correctamente devuelve 0(EXITO)
 * de lo contrario devuelve -1(ERROR)
*/
int lectura_archivo_gimnasios(const char* ruta_archivo,heap_t* heap){
    if(!heap){
        return ERROR;
    }

    FILE* archivo = fopen(ruta_archivo,"r");
    if(!archivo){
        perror(ruta_archivo);
        return ERROR;
    }

    char linea[BUFFER]; 
    int num_linea = 0;
    bool error_lectura = false;

    char* linea_gimnasio = leer_linea(archivo,linea,BUFFER,&num_linea);

    if(!linea_gimnasio || linea_gimnasio[0] != GIMNASIO){
        error_lectura = true;
        mensaje_error_formato(linea,num_linea,ERROR_FORMATO_GYM);
        printf("Todos los gimnasios deben tener primero un lider\n");
    }

    while (linea[0] == GIMNASIO && !error_lectura && linea_gimnasio){

        gimnasio_t* gym = leer_gimnasio(archivo,linea,&num_linea,&error_lectura,linea_gimnasio);
        if(gym){
            heap_insertar(heap,gym);
        }
    }

    fclose(archivo);

    if(error_lectura){
        return ERROR;
    }
    return EXITO;
}



/*
 * Recive un archivo de personaje valido.
 * Llena un personaje_t con los contenidos del archivo
 * Si ocurre algun error devuelve NULL.
*/
personaje_t* lectura_archivo_personaje(const char* ruta_archivo){
    FILE* archivo = fopen(ruta_archivo,"r");
    if(!archivo){
        perror(ruta_archivo);
        return NULL;
    }

    char linea[BUFFER]; 
    int num_linea = 0;
    bool error_lectura = false;

    char* linea_personaje = leer_linea(archivo,linea,BUFFER,&num_linea);
    char tipo;
    char nombre[MAX_NOMBRE];

    if(lectura_formato_entrenador(linea_personaje,&tipo,nombre) != CAMPOS_ENTRENADOR && tipo != ENTRENADOR){
        mensaje_error_formato(linea,num_linea,ERROR_FORMATO_ENTRENADOR);
        return NULL;
    }

    personaje_t* personaje = personaje_crear(nombre);

    int i = 0;
    while (leer_linea(archivo,linea,BUFFER,&num_linea) && linea[0] == POKEMON && !error_lectura){
        pokemon_t* pokemon = leer_pokemon(linea,&num_linea,&error_lectura);
        if(pokemon){
            if(personaje_agregar_pokemon(personaje,pokemon) == ERROR){
                personaje_destruir(personaje);
                return NULL;
            }
        }
        i++;
    }

    if(personaje_cantidad_pokemon(personaje) == 0){
        return NULL;
    }

    return personaje;
}
