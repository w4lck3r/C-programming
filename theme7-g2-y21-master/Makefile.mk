CC = gcc
CFLAGS = -Wall -O0 -g -fsanitize=address
all:trie_fusion
	
all: trie_fusion.o
	$(CC) $(CFLAGS) -o trie_fusion $^

trie_fusion.o: trie_fusion.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f *.o 
	rm main_test

.PHONY: all clean
