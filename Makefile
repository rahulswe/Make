CC = gcc

main: main.c
	$(CC) main.c -o main

.PHONY: clean

clean:
	-rm -f main