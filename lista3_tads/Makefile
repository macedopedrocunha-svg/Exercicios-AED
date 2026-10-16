CC = gcc
CFLAGS = -Wall -Wextra

all: main.o personagem.o
	$(CC) $(CFLAGS) -o jogo main.o personagem.o

main.o: main.c personagem.h
	$(CC) $(CFLAGS) -c main.c

personagem.o: personagem.c personagem.h
	$(CC) $(CFLAGS) -c personagem.c

.PHONY: clean
clean:
	rm -f *.o jogo
