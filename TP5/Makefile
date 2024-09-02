CC=clang
CFLAGS=-std=c89 -ansi -pedantic -Wall -lncurses
SRC=./
EXEC=main
 
all: $(EXEC)
 
main: $(SRC)main.c $(SRC)graphic.o $(SRC)type.o $(SRC)monde.o
	$(CC) -o $(SRC)$@ $^ $(CFLAGS) 
 
$(SRC)%.o : $(SRC)%.c
	$(CC) -o $@ -c $< $(CFLAGS) 
 
clean:
	rm -rf $(SRC)*.o
	

