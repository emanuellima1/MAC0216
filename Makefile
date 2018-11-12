# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC=gcc
CFLAGS=-Wall -pedantic -O2
EXEC=jogo.out
OBJ=src/elemento.o src/lista.o src/tabela.o src/jogo.o src/comandos.o
OBJ_FULL=src/elemento.o src/lista.o src/tabela.o src/jogo.o src/comandos.o src/teste.o 

jogo.out: $(OBJ)
	$(CC) $(CFLAGS) -o jogo.out $(OBJ) 

teste.out: $(OBJ_FULL) 
	$(CC) $(CFLAGS) -o teste.out $(OBJ_FULL)

jogo.o: src/tabela.h src/lista.h src/elemento.h 

comandos.o: src/comandos.h src/elemento.h

elemento.o: src/elemento.h 

lista.o: src/lista.h

tabela.o: src/tabela.h

teste.o: src/tabela.h

.PHONY: teste
teste: ./teste.out
	./teste.out	

.PHONY: relatorio
relatorio:
	pdflatex relatorio/relatorio.tex
	-rm -f relatorio.aux relatorio.log

.PHONY: clean
clean: 
	-rm -f teste.out jogo.out $(OBJ_FULL) relatorio.pdf
