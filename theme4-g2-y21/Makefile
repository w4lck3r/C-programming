CC ?= gcc
CFLAGS ?= -Wall -Werror -ansi -pedantic  


swap_int: src/swap_int.o 
	$(CC) $(CFLAGS) $^ -o build/swap_int

division: src/division.o 
	$(CC) $(CFLAGS) $^ -o build/division

dicho: src/dicho.o 
	$(CC) $(CFLAGS) $^ -o build/dicho

mecho: src/mecho.o 
	$(CC) $(CFLAGS) $^ -o build/mecho

strip_spaces_tst: src/strip_spaces_tst.o 
	$(CC) $(CFLAGS) $^ -o build/strip_spaces_tst

src/swap_int.o: src/swap_int.c
	$(CC) $(CFLAGS) -c -o $@ $^

src/division.o: src/division.c
	$(CC) $(CFLAGS) -c -o $@ $^

src/strip_spaces_tst.o: src/strip_spaces_tst.c
	$(CC) $(CFLAGS) -c -o $@ $^

src/mecho.o: src/mecho.c
	$(CC) $(CFLAGS) -c -o $@ $^


src/dicho.o: src/dicho.c
	$(CC) $(CFLAGS) -c -o $@ $^


clean : 
	rm -f *.o 

.PHONY: all clean
