P=ksc

CC = cc
YACC = bison -d
LEX = flex

CFLAGS=	-g -Wall -Werror -O3\
		`pkg-config --cflags glib-2.0` -I/opt/local/include

LDLIBS= `pkg-config --libs glib-2.0`\
		-L/opt/local/lib \
		-lgmp -lmpfr -lmpc -lfl -lgc

SRC = .
OBJS = parse.tab.o lex.yy.o
OBJS += obj.o

libkscm: $(OBJS)
	ar -rcs libkscm.a $(OBJS)

ksc: $(OBJS) ksc.scm
	./ksc ksc
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) ksc.c -o $@

runksc: $(OBJS) runksc.scm
	./ksc runksc
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) runksc.c -o $@

temp: $(OBJS) ksc.scm temp.scm
	./ksc temp
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) temp.c -o $@
	./temp

gosh: $(OBJS) ksc.scm
	gosh ksc.scm ksc
	clang-format-mp-3.9 -i ksc.c
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) ksc.c -o ksc

goshtemp: $(OBJS) ksc.scm temp.scm
	gosh ksc.scm temp
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) temp.c -o temp

parse.tab.o: parse.tab.c parse.tab.h

parse.tab.c parse.tab.h: parse.y obj.h
	$(YACC) parse.y

lex.yy.o: lex.yy.c
lex.yy.c: lex.l parse.tab.h
	$(LEX) lex.l

obj.o: obj.h obj.c

