#FINAL Juan Cruz Vidiri - Teoria de Lenguajes

Instalar gcc, flex y bison con apt-get

## Compilar

Compilar los archivos fuente del compilador, usando los instrucciones del makefile

```{r, engine='bash', count_lines}
    $ make
```


El comando MAKE genera un archivo ejecutable de nombre tiny.exe. Este archivo permite compilar un programa (codigo fuente) con el nuevo compilador (tiny)

```{r, engine='bash', count_lines}
    $ ./tiny sample.tny
```

El compilador tiny genera un archivo con extensión tm (sample.tm), el cual contiene las instrucciones que el programa que compiló va a llevar a cabo. Para poder ejecutar el programa que se compiló, es necesario contar con un programa que traduzca las instrucciones del lenguaje ensamblador, para ello está el programa TM

```{r, engine='bash', count_lines}
    $ gcc tm.c –o tm
```

El archivo resultante (tm) nos permitira traducir las instrucciones en lenguaje ensamblador

```{r, engine='bash', count_lines}
    $ ./tm sample.tm
```

TM ejecutará las instrucciones del programa (sample.tny) que tiny compilo
Modo de uso:
            - Para poder introducir el número a calcular, poner el comando “go” y después el número.
            - Para ingresar otro numero, poner el comando "clear" y luego "go".
            - Usar el comando “quit” para poder salir del programa.


## Usar Flex / Bison

Primero mover los archivos en las carpetas lex y yacc a la carpeta donde se encuentran el resto de los archivos. Luego ejecutar las siguientes lineas

```{r, engine='bash', count_lines}
    yacc –d tiny.y	# crea los archivos y.tab.h e y.tab.c
    lex tiny.l		  # crea el archivo lex.yy.c utilizando y.tab.h
```

Ahora si queremos utilizar el scanner y el parser generados por Lex y Yacc, debemos modificar nuestro makefile para hacer uso de los archivos lex.yy.c e y.tab.c en lugar de scan.c y parse.c respectivamente.

MAKEFILE
```{r, engine='bash', count_lines}
#
# Makefile for TINY
# Gnu C Version
# K. Louden 2/3/98
#

CC = gcc

CFLAGS =

OBJS = main.o util.o lex.yy.o y.tab.o symtab.o analyze.o code.o cgen.o

tiny: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o tiny -lfl

main.o: main.c globals.h util.h scan.h parse.h analyze.h cgen.h y.tab.h
	$(CC) $(CFLAGS) -c main.c

util.o: util.c util.h globals.h
	$(CC) $(CFLAGS) -c util.c

lex.yy.c: tiny.l y.tab.h
	lex tiny.l

lex.yy.o: lex.yy.c scan.h util.h globals.h
	$(CC) $(CFLAGS) -c lex.yy.c

y.tab.c y.tab.h: tiny.y
	yacc --defines=y.tab.h tiny.y

y.tab.o: y.tab.c parse.h scan.h globals.h util.h
	$(CC) $(CFLAGS) -c y.tab.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c

analyze.o: analyze.c globals.h symtab.h analyze.h
	$(CC) $(CFLAGS) -c analyze.c

code.o: code.c code.h globals.h
	$(CC) $(CFLAGS) -c code.c

cgen.o: cgen.c globals.h symtab.h code.h cgen.h
	$(CC) $(CFLAGS) -c cgen.c

clean:
	rm -f tiny
	rm -f tm
	rm -f y.tab.c y.tab.h lex.yy.c
	rm -f $(OBJS)

tm: tm.c
	$(CC) $(CFLAGS) tm.c -o tm

all: tiny tm
```
