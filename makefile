CC = gcc
CFILES = find . -name '*.c'
HFILES = find . -name '*.h'
MAIN = juego.c
OBJETOS = ./Estructura/gimnasio.o ./Estructura/personaje.o ./Estructura/pokemon.o ./Estructura/batallas.o ./Estructura/aventura_pokemon.o \
          ./TDAs/lista.o ./TDAs/heap.o /Archivos/archivos.o utiles.o interfaz.o 
FILES = Enunciado makefile Archivos Estructura TDAs
EXEC = prueba
CFLAGS =  -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0
GFLAGS = --tui
VFLAGS = --leak-check=full --track-origins=yes --show-reachable=yes 

$(EXEC): $(MAIN) $(OBJETOS)
	$(CC) $^ $(CFLAGS) -o $(EXEC)

debug: $(EXEC)
	gdb $(GFLAGS) $(EXEC)

test: $(EXEC)
	valgrind $(VFLAGS) ./$(EXEC) $(arg_1) $(arg_2) $(arg_3)

run: $(EXEC)
	./$(EXEC) $(arg_1) $(arg_2) $(arg_3)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

zip: 
	zip -r $(EXEC).zip *.c *.h $(FILES)

.PHONY: clean
clean:
	rm -f *.o $(EXEC)

