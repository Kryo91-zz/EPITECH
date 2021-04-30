##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##
CC = gcc

NAME = push_swap

SRC = src/main.c \


LIB = lib/my/my_putstr.c \
		lib/my/my_putchar.c \
		lib/my/my_getnbr.c \
		lib/my/my_compute_power_rec.c \
		lib/my/my_swap.c \

TESTS = tests/tests.c \

CFLAGS = -W -Wall -Wextra -g3 -ggdb

OBJ = $(SRC:.c=.o) $(LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
