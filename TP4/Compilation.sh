#!/bin/bash
gcc -c Tablette.c
gcc -c Position.c
gcc -c Joueur.c
gcc -c Coup.c
gcc -c Main.c
gcc -Wall -ansi -pedantic Main.o Tablette.o Position.o Joueur.o Coup.o -lncurses
