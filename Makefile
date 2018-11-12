# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC=gcc
CFLAGS=-Wall -pedantic -O2
EXEC=teste.out
OBJ=src/elemento.o src/lista.o src/tabela.o src/teste.o

teste.out: $(OBJ) 
	$(CC) $(CFLAGS) -o teste.out $(OBJ)

elemento.o: src/elemento.h

lista.o: src/lista.h

tabela.o: src/tabela.h

teste.o: src/tabela.h

.PHONY: teste
teste: 
	./teste.out	

.PHONY: relatorio
relatorio:
	pdflatex relatorio/relatorio.tex

.PHONY: clean
clean: 
	-rm -f teste.out $(OBJ) relatorio.pdf relatorio.aux relatorio.log
