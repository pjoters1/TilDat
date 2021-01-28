.DEFAULT_GOAL := taco

CC := gcc
CFLAGS := -O0 -g3 -std=c99
OBJ = taco_krydder.o taco_saus.o taco_lefse.o protein.o grønnsaker.o drikke.o main.o

.PHONY: clean
clean :
	rm -f *.o

taco : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
