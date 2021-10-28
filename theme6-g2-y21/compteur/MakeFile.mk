all : compteur_test

compteur.o : compteur.c
	cgcc - compteur.c -o compteur.o

compteur_test : compteur.o 
	gcc compteur.o -o compteur_test

clean :
	rm -f *.o compteur_test

.PHONY: all clean 