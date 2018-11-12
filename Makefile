# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC=gcc
CFLAGS=-Wall -pedantic -O2
EXEC=jogo.out
OBJ=src/elemento.o src/lista.o src/tabela.o src/jogo.o

jogo.out: $(OBJ)
	$(CC) $(FLAGS) -o jogo.out $(OBJ)

teste.out: $(OBJ) 
	$(CC) $(CFLAGS) -o teste.out $(OBJ) src/teste.o

jogo.o: src/tabela.h src/lista.h src/elemento.h 

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

.PHONY: clean
clean: 
	-rm -f teste.out jogo.out $(OBJ) src/jogo.o src/teste.o relatorio.pdf relatorio.aux relatorio.log
