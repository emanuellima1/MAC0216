# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC=gcc
CFLAGS=-Wall -pedantic -O2
EXEC=jogo.out
OBJ_TESTE=lib/elemento.o lib/lista.o lib/tabela.o src/test/teste.o
OBJ_JOGO=lib/elemento.o lib/lista.o lib/tabela.o src/jogo.o lib/comandos.o

jogo.out: $(OBJ_JOGO) src/jogo.h
	$(CC) $(CFLAGS) -o jogo.out $(OBJ_JOGO) 

teste.out: $(OBJ_TESTE) 
	$(CC) $(CFLAGS) -o teste.out $(OBJ_TESTE)

lista.o: lib/lista.h

tabela.o: lib/tabela.h lib/lista.h

elemento.o: lib/elemento.h lib/tabela.h lib/lista.h

teste.o: lib/elemento.h lib/tabela.h lib/lista.h 

comandos.o: lib/comandos.h lib/elemento.h lib/tabela.h lib/lista.h

jogo.o: src/jogo.h lib/comandos.h lib/elemento.h lib/tabela.h lib/lista.h

.PHONY: test
test: ./teste.out
	./teste.out	

.PHONY: doc
doc:
	pdflatex doc/relatorio.tex
	-rm -f relatorio.aux relatorio.log

.PHONY: clean
clean: 
	-rm -f teste.out jogo.out $(OBJ_JOGO) src/test/teste.o relatorio.pdf
