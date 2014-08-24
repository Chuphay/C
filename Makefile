CFLAGS=-Wall -g 

clean:
	rm -f ex1

all: graph_easy

graph_easy: queue.o

bond_perc: union_find.o

galaxy: union_find.o

A_star: heap.o myData.o

hash: stack.o myData.o



