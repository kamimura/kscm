CC = cc

CFLAGS=	-g -Wall -Werror -O3\
		`pkg-config --cflags glib-2.0`
LDLIBS=\
	`pkg-config --libs glib-2.0`\
	-L/opt/local/lib -lgmp -lmpfr -lmpc -lfl

sample: sample.scm
	cp sample.scm input.scm
	time ../compiler/ksc
	$(CC) $(CFLAGS) -I../src $(LDLIBS) -L../src -lkscm output.c -o sample
	./sample
