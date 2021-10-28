all : duplicate_test

duplicate.o : dupliquer_chaine.c
	gcc -c duplicate.c -o duplicate.o

duplicate_test : duplicate.o 
	gcc duplicate.o -o duplicate_test

clean :
	rm -f *.o duplicate_test

.PHONY: all clean 