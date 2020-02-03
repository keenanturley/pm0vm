# Makefile

pm0vm : main.o pm0.o loader.o debug.o
	gcc -o pm0vm main.o pm0.o loader.o debug.o

main.o : pm0.o loader.o debug.o
	gcc -c main.c

pm0.o : pm0.c pm0.h debug.h
	gcc -c pm0.c

loader.o : loader.c loader.h debug.h
	gcc -c loader.c

debug.o : debug.c debug.h
	gcc -c debug.c

clean:
	rm -f pm0vm *.o