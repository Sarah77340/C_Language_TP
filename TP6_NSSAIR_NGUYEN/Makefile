CC=gcc
CFLAGS=-std=c89 -ansi -pedantic -Wall -lncurses
SRC=./
EXEC=main
 
all: $(EXEC)
 
main: $(SRC)main.c $(SRC)fichier.o $(SRC)test.o $(SRC)tableau.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	

