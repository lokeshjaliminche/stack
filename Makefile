CC=gcc
CFLAGS=-I.
DEPS = stack.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stack: stack.o
	gcc -o stack stack.o -I.

clean:
	rm -rf *.o stack a.out
