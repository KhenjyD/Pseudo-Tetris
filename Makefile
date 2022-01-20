CC=g++
SRC= main.cpp grille.cpp bloc.cpp jeu.cpp autre.cpp
OBJ=$(SRC:.c=.o)
FLAGS=-Wall

tetris:    $(OBJ) tetris.hpp
	$(CC) -o $@ $(OBJ)
%.o:	%.c
	$(CC) -c $< $(CFLAGS)

clean:
	rm *.o *~ core