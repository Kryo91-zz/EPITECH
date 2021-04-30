##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##
CC = gcc

NAME = my_sokoban

SRC = src/main.c \
		src/map_coor.c \
		src/files.c \
		src/moove.c


LIB = lib/my/my_strlen.c

CFLAGS = -W -Wall -Wextra -g3 -ggdb

OBJ = $(SRC:.c=.o) $(LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
