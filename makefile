all: main

main: vector.o main.o
	gcc -g vector.o main.o -o main
vector.o:  vector.h vector.c
	gcc -c -g vector.c -o vector.o
main.o: vector.h main.c
	gcc -c -g main.c -o main.o
run: all
	./main
checkmem: all
	valgrind -v ./main
clean:
	rm -f vector.o main.o main
