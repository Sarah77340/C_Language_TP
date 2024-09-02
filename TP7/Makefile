CC=gcc
CFLAGS=-std=c89 -ansi -lm -pedantic -Wall -lncurses
SRC=./
EXEC=main
 
all: $(EXEC)
 
main: $(SRC)main.c $(SRC)graphic.o $(SRC)joueur.o $(SRC)jeu.o $(SRC)dico.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	

