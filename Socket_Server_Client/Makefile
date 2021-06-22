all:
	gcc -g -c -Wall server.c -o server.o
	gcc -g -c -Wall sumalong.c -o sumalong.o
	gcc -g -Wall server.o sumalong.o -o server

clean:
	rm *.o
	rm server
