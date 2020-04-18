EXEC := cipher

all: cipher.c main.c cipher.h
	gcc cipher.c main.c -g -o $(EXEC)

run: 
	./$(EXEC) e banana THE_VOICE.txt outfile.txt
	cat outfile.txt
	./$(EXEC) d banana outfile.txt output
	cat output

test:
	./$(EXEC) e "GOODMORNING" THE_VOICE.txt outfile.txt
	./$(EXEC) d "GOODMORNING" outfile.txt rdata
	diff -s THE_VOICE.txt rdata

valgrind:
	valgrind --leak-check=yes $(EXEC) e banana THE_VOICE.txt outfile.txt

gdb:
	gdb --args $(EXEC) e banana THE_VOICE.txt outfile.txt

clean:
	$(RM) $(EXEC) outfile.txt vgcore.* rdata
