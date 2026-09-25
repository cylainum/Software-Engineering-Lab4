.PHONY: clean program

program : all

all : task1 task2

task1 : task1.o
	gcc task1.o -o task1

task2 : task2.o
	gcc task2.o -o task2

task1.o: task1.c
	gcc -c task1.c

task2.o: task2.c
	gcc -c task2.c
clean:
	rm -f all task1.o task2.o

#Thank you for the help :)