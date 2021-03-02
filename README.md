# Aventura Pokemon

Aventura Pokemon es un juego de texto interactivo que te hara combatir con tu entrenador contra todos los gimnasios Pokemon que tu ingrese, para ser un MAESTRO POKEMON

## Compilacion y Ejecucion

Este programa se compila con `make` y se ejecuta con `make run` o `make test` si se quiere testear la memoria

## **Cambios a TDAs**

Al TDA lista se le agrego un destructor ya que facilita el manejo de la memoria

## **Archivos**

Los archivos solo seran leidos si son colocados en los archivos correctos.

### **Archivos Gimnasio:**

Todos los gimnasios que quieran ser usados debera estar en `./Archivos/Gimnasios` tener el siguiente formato:

    G;nombre_gimnasio; dificultad; id_puntero_funcion
    L;nombre_lider
    P;nombre_pokemon1; velocidad; ataque; defensa
    P;nombre_pokemon2; velocidad; ataque; defensa
    P;nombre_pokemon3; velocidad; ataque; defensa
    E;nombre_entrenador1
    P;nombre_pokemon1; velocidad; ataque; defensa
    P;nombre_pokemon2; velocidad; ataque; defensa
    E;nombre_entrenador2
    P;nombre_pokemon1; velocidad; ataque; defensa
    ...

### **Archivos Personaje:**

Todos los gimnasios que quieran ser usados debera estar en `./Archivos/Personajes` tener el siguiente formato:

    E;nombre_entrenador
    P;nombre_pokemon1; velocidad; ataque; defensa
    P;nombre_pokemon2; velocidad; ataque; defensa
    P;nombre_pokemon3; velocidad; ataque; defensa
    P;nombre_pokemon4; velocidad; ataque; defensa
    P;nombre_pokemon5; velocidad; ataque; defensa
    P;nombre_pokemon6; velocidad; ataque; defensa
    P;nombre_pokemon7; velocidad; ataque; defensa
    ...

## **Estructura**

### **Juego**

```c
typedef struct juego{
    heap_t* gimnasios;
    gimnasio_t* gimnasio_actual;
    personaje_t* personaje;
    bool simular;
    int gimnasios_derrotados;
}juego_t;
```

La estructura del juego principal se llamo `juego_t`, en esta se utilizo un heap para guardar los gimnasios ya que permite al usuario ingresar los archivos de los gimnasios en cualquier orden y que sigan estando ordenados. Ademas se guardan el gimansio actual y el personaje para facilitar el manejo de memoria

### **Gimnasio**

```c
typedef struct gimnasio{
    char nombre[MAX_NOMBRE];
    int dificultad;
    bool pokemon_tomado;
    funcion_batalla funcion_batalla;
    lista_t*  entrenadores;
}gimnasio_t;
```

Para el `gimnasio_t` se utilizo una lista para guardar los entrenadores ya que no se puede nunca saber la cantidad exacta de entrenadores que va a tener un gimnasio. Ademas permite que al agregarse entrenadores siempre se inserte al final y que se pueda sacar siempre con facilidad el ultimo entrenador ingresado, dando asi el orden correcto de combate.

Tambien la utilizacion de una lista con destructor facilita mucho el manejo de la memoria tanto al crearse como al liberarse

### **Entrenadores**

``` c
typedef struct entrenador{
    char tipo;
    char nombre[MAX_NOMBRE];
    lista_t* pokemon;
}entrenador_t;
```

Para almacenar los Pokemon se utilizo una lista, esto se debe a que los entrenadores siempre van a tener un numero fijo de pokemones y seria un gasto de memoria usar algo que sea un vector estatico.

### **Personaje**

```c
 typedef struct personaje{
    char nombre[MAX_NOMBRE];
    pokemon_t* party[MAX_POKEMON_PARTY];
    lista_t* pokemon_obtenidos;
  }personaje_t;
```

#### **El conjunto de pokemones obtenidos**

Para los pokemon de combate se utilizo una lista ya que la cantidad de pokemon puede ser "infinita" y no valdria la pena tener algo estatico. La utilizacion de una lista siempre facilita el manejo de memoria y es mejor que que un vector dinamico al poder los nodos de la lista estar en distintos espacios de memoria a diferencia de todos juntos.

La lista ademas permite ingresar y borra Pokemon facilmente sin perder la facilidad de obtener una posicion de la lista para buscar un Pokemon. Ademas la lista permite que se usen sus iteradores que deja recorrer cada pokemon con facilidad.

#### **El conjunto de pokemones que combate**

Para los Pokemon de combate se utilizo un vector estatico de punteros. Esto se debe a que realmente este puntero no almacena los Pokemon si no que solo apunta a los Pokemon de la lista que se quieren en combate.

Tambien se eligio un vector estatico ya que al trascurso de una partida el jugador puede tomar mas pokemon haciendo mas probable que esos espacios de memoria no sean desperdiciados.

Por ultimo este vector evita que este manejando dos listas o repetidos, y facilita mucho las batallas ya que solo tengo que recorrer el vector para obtener cada pokemon.
