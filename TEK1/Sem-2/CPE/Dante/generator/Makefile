##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME = generator

SRC = 	main.c \
		print_map.c \
		perfect_maze.c \
		imperfect_maze.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -W -Wall -Wextra -g3 $(OBJ) -o $(NAME)
	rm -f $(OBJ)

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
