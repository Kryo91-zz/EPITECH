##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

NAME = z

SRC = z.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -std=gnu11 -Wall -Wextra $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f units

re: fclean all

test_run :
		gcc error.c ./tests/criterion.c -lcriterion --coverage -o units