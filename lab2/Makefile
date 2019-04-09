main.o: main.c readline.h factorial.h
	gcc -c main.c
factorial.o: factorial.c factorial.h
	gcc -c factorial.c
readline.o: readline.c readline.h
	gcc -c readline.c
all: main.o factorial.o readline.o
	gcc main.o factorial.o readline.o -o myfactorial
clean:
	rm -f *.o myfactorial
