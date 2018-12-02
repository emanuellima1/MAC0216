# Makefile do Projeto Aventura
# Emanuel Lima e João Seckler

CC=gcc
CFLAGS=-Wall -lreadline -pedantic -O2
EXEC=jogo.out
OBJ_TESTE1=lib/elemento.o lib/lista.o lib/tabela.o src/test/teste.o
OBJ_TESTE2=lib/elemento.o lib/lista.o lib/tabela.o \
src/test/jogo-teste.o  lib/comandos.o
OBJ_JOGO=src/jogo.o lib/elemento.o lib/lista.o lib/tabela.o lib/comandos.o \
src/jogo.tab.o src/lex.yy.o

jogo.out: $(OBJ_JOGO) src/jogo.h
	$(CC) $(CFLAGS) -o jogo.out $(OBJ_JOGO)

jogo-teste.out: $(OBJ_TESTE2) src/jogo.h
	$(CC) $(CFLAGS) -o jogo-teste.out $(OBJ_TESTE2) 

teste.out: $(OBJ_TESTE1) 
	$(CC) $(CFLAGS) -o teste.out $(OBJ_TESTE1)

src/lex.yy.c: src/jogo.l
	flex -o src/lex.yy.c src/jogo.l 

src/lex.yy.o: src/lex.yy.c

src/jogo.tab.c: src/jogo.y
	bison -d src/jogo.y -o src/jogo.tab.c

src/jogo.tab.o: src/jogo.c

lista.o: lib/lista.h

tabela.o: lib/tabela.h lib/lista.h

elemento.o: lib/elemento.h lib/tabela.h lib/lista.h

teste.o: lib/elemento.h lib/tabela.h lib/lista.h 

comandos.o: lib/comandos.h lib/elemento.h lib/tabela.h lib/lista.h

jogo-teste.o: src/jogo.h lib/comandos.h lib/elemento.h lib/tabela.h lib/lista.h

jogo.o: src/jogo.h lib/comandos.h lib/elemento.h lib/tabela.h lib/lista.h src/tab.jogo.h

.PHONY: test
test: ./teste.out ./jogo-teste.out
	./teste.out	&& ./jogo-teste.out

.PHONY: doc
doc:
	pdflatex doc/relatorio.tex
	-rm -f relatorio.aux relatorio.log

.PHONY: clean
clean: 
	-rm -f teste.out jogo-teste.out jogo.out $(OBJ_JOGO) $(OBJ_TESTE2) src/lex.yy.c src/*tab* src/jogo.o
