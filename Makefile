g=gcc -Wall -g

param=-lpthread -lmysqlclient

test:test.o
	$(g) test.o -o debug/test

test.o:
	$(g) -c test.c

clean:
	@rm *.o main *.h.gch *.exe

run:clean all
	./main

	