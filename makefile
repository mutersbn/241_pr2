EXEC := cipher

all: cipher.c main.c cipher.h
	gcc cipher.c main.c -g -o $(EXEC)

run: 
	./$(EXEC) e banana THE_VOICE.txt outfile.txt

test:
	./$(EXEC) e "GOODMORNING" datap outfile.txt
	./$(EXEC) d "GOODMORNING" outfile.txt rdata
	diff -s datap rdata

clean:
	$(RM) $(EXEC) outfile.txt
