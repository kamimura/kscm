P=ksc

CC = cc
YACC = bison -d
LEX = flex

CFLAGS=	-g -Wall -Werror -O3\
		`pkg-config --cflags glib-2.0`
LDLIBS=\
	`pkg-config --libs glib-2.0`\
	-L/opt/local/lib -lgmp -lmpfr -lmpc -lfl
n

SRC = .
OBJS = parse.tab.o lex.yy.o  init.o

OBJS += memory.o
OBJS += object.o
OBJS += boolean.o
OBJS += env.o
OBJS += symbol.o
OBJS += number.o
OBJS += bytevector.o
OBJS += char.o
OBJS += empty.o
OBJS += eof.o
OBJS += pair.o
OBJS += port.o
OBJS += proc.o
OBJS += proc_compiled.o
OBJS += scm_string.o
OBJS += syntax.o
OBJS += undef.o
OBJS += vector.o
OBJS += system.o
OBJS += scm_complex.o
OBJS += rational.o
OBJS += byte.o

sample: sample.scm libkscm
	cp sample.scm input.scm
	time ../compiler/ksc
	$(CC) $(CFLAGS) -I./ $(LDLIBS) -L./ -lkscm output.c -o sample
	time ./sample
	$(CC) $(CFLAGS) -I./ $(LDLIBS) -L./ -lkscm output.c -o sample
	time ./sample

parse.tab.c parse.tab.h: parse.y scm_string.h bytevector.h
	$(YACC) parse.y

lex.yy.o: lex.yy.c
lex.yy.c: lex.l parse.tab.h char.h byte.h
	$(LEX) lex.l

libkscm: $(OBJS)
	ar -rcs libkscm.a $(OBJS)

memory.o: object.h memory.h memory.c

object.o: kscm.h memory.h boolean.h env.h symbol.h object.h object.c

boolean.o: object.h boolean.h boolean.c

env.o: object.h env.h env.c

symbol.o: object.h symbol.h symbol.c

number.o: object.h number.h number.c

bytevector.o: object.h bytevector.h bytevector.c

char.o: object.h char.h char.c

empty.o: object.h empty.h empty.c

eof.o: object.h eof.h eof.c

pair.o: object.h pair.h pair.c

port.o: object.h port.h port.c

proc.o: object.h proc.h proc.c

proc_compiled.o: object.h proc_compiled.h proc_compiled.c

scm_string.o: object.h scm_string.h scm_string.c

syntax.o: object.h syntax.h syntax.c

undef.o: object.h undef.h undef.c

vector.o: object.h vector.h vector.c

system.o: scm_string.h system.h system.c

scm_complex.o: number.h scm_complex.h scm_complex.c

rational.o: scm_complex.h rational.h rational.c

byte.o: rational.h byte.h byte.c

gosh: $(OBJS)
	cp ksc.scm input.scm
	gosh -r7 < ksc.scm
	cp compiler.log compiler1.log
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJS) output.c -o sample
	cp sample ksc

