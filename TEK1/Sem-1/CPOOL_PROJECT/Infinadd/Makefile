##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = infin_add

SRC = my_revstr.c \
			my_putchar.c \
			my_putstr.c \
			my_strlen.c \
			infin_add.c \



CFLAGS = -W -Wall -Wextra -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) -lm -o $(NAME)

clean:
		rm *.o -f

fclean: clean
		rm $(NAME)

re: fclean all
