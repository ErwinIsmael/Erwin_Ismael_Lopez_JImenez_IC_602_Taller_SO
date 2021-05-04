all:
	gcc -g -c -Wall main.c -o main.o -l pthread
	gcc -g -c -Wall scheduler.c -o scheduler.o -l pthread
	gcc -g -Wall main.o scheduler.o -o ejecutable -l pthread

clean:
	rm *.o
	rm ejecutable
