##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = cat

SRC = cat.c \


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
