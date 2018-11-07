CFLAGS = -Wall


rePython: main.o mpc.o parser.o
	gcc $(CFLAGS) main.o mpc.o parser.o -lm -o a.out

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

parser.o: headers/parser/parser.c headers/parser/parser.h mpc.o
	gcc $(CFLAGS) -c headers/parser/parser.c -o parser.o

mpc.o: headers/mpc/mpc.c headers/mpc/mpc.h
	gcc $(CFLAGS) -c headers/mpc/mpc.c -o mpc.o

clean:
	rm -f main.o mpc.o parser.o \
	./a.out