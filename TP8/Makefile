CC=gcc
CFLAGS=-std=c89 -ansi -lm -Wall -lncurses
SRC=./
EXEC=main
 
all: $(EXEC)
 
main: $(SRC)main.c $(SRC)position.o $(SRC)graphic.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	

