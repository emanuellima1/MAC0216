CC = gcc -Wall -pedantic -O2
LIB_OBJ = lib/comandos.o lib/elemento.o lib/tabela.o lib/lista.o
LANG_OBJ = src/jogo-y.o src/jogo-l.o

##################################
# Programa principal
##################################

jogo.out: src/jogo.o src/jogo-y.o src/jogo-l.o
	${CC} -o jogo.out ${LIB_OBJ} ${LANG_OBJ} src/jogo.o -lreadline

src/jogo-y.o: src/jogo-y.c

src/jogo-y.c: src/jogo-y.y
	bison -d src/jogo-y.y -o src/jogo-y.c

src/jogo-l.o: src/jogo-l.c

src/jogo-l.c: src/jogo-l.l

src/jogo.o: lib/comandos.o

lib/comandos.o: lib/elemento.o 

lib/elemento.o: lib/tabela.o

lib/tabela.o: lib/lista.o

lib/lista.o: 

%.o: %.c %.h
	${CC} -c $< -o $@

clean:
	rm -f src/jogo-y.c src/jogo-y.h src/jogo-l.c *.out
	rm -f src/*.o src/test/*.o lib/*.o

##################################
# Rotinas de teste (partes 1 e 2)
##################################

test: jogo-test.out lib-test

jogo-test.out: src/test/jogo-test.o 
	${CC} -o $@ ${LIB_OBJ} src/test/jogo-test.o
src/test/jogo-test.o: lib/comandos.o

lib-test: src/test/lib-test.o
	${CC} -o $@ lib/lista.o lib/tabela.o lib/elemento.o src/test/lib-test.o

src/test/lib-test.o: lib/elemento.o

clean-test:
	rm -f src/test/*.o lib-test jogo-test.out
