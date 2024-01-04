all: prog

prog: main.o csv.o tsv.o
	gcc -o prog main.o csv.o tsv.o

main.o: main.c csv.h tsv.h
	gcc -c main.c

csv.o: csv.c csv.h
	gcc -c csv.c

tsv.o: tsv.c tsv.h
	gcc -c tsv.c

clean:
	rm *.o
