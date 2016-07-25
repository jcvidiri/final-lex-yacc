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
