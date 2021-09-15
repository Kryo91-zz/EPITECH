##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

CC = gcc

NAME = menger

SRC = main.c \
		menger.c

CFLAGS = -std=gnu11 -Wall -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) $(CFLAGS) -o $(NAME)
		rm -f $(OBJ)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all
