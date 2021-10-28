CC = gcc
CFLAGS = -Wall -O0 -g -fsanitize=address
all:files_generique
	
all: files_generique.o
	$(CC) $(CFLAGS) -o files_generique $^

files_generique.o: files_generique.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o 
	rm main_test

.PHONY: all clean
