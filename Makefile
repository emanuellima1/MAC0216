# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC=gcc
CFLAGS=-Wall -pedantic -O2
EXEC=jogo.out
OBJ_TESTE=src/elemento.o src/lista.o src/tabela.o src/teste.o
OBJ_JOGO=src/elemento.o src/lista.o src/tabela.o src/jogo.o src/comandos.o 

jogo.out: $(OBJ_JOGO)
	$(CC) $(CFLAGS) -o jogo.out $(OBJ_JOGO) 

teste.out: $(OBJ_TESTE) 
	$(CC) $(CFLAGS) -o teste.out $(OBJ_TESTE)

lista.o: src/lista.h

tabela.o: src/tabela.h src/lista.h

elemento.o: src/elemento.h src/tabela.h src/lista.h

teste.o: src/elemento.h src/tabela.h src/lista.h 

comandos.o: src/comandos.h src/elemento.h src/tabela.h src/lista.h

jogo.o: src/jogo.h src/comandos.h src/elemento.h src/tabela.h src/lista.h

.PHONY: teste
teste: ./teste.out
	./teste.out	

.PHONY: relatorio
relatorio:
	pdflatex relatorio/relatorio.tex
	-rm -f relatorio.aux relatorio.log

.PHONY: clean
clean: 
	-rm -f teste.out jogo.out $(OBJ_JOGO) src/teste.o relatorio.pdf
