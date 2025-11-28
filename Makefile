flags=-Wall -std=c2x -O2 
ldflags=

tree: tree.o
	cc ${flags} $^ -o $@ ${ldflags}

tree.o: tree.c
	cc ${flags} -c $^

clean:
	rm -f *.o tree