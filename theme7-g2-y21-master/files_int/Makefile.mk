CC = gcc
CFLAGS = -Wall -O0 -g -fsanitize=address
all:files_int
	
all: files_int.o
	$(CC) $(CFLAGS) -o files_int $^

files_int.o: files_int.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o 
	rm files_int

.PHONY: all clean
