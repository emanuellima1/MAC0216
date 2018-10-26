# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC = gcc
CFLAGS = -Wall -pedantic -O2
EXEC = teste.out
OBJ = src/elemento.o src/lista.o src/tabela.o src/teste.o

teste.out : $(OBJ) 
	gcc -o teste.out $(OBJ)

elemento.o : src/elemento.h

lista.o : src/lista.h

tabela.o : src/tabela.h

teste.o : src/tabela.h

.PHONY : clean
clean : 
	-rm teste.out $(OBJ)
