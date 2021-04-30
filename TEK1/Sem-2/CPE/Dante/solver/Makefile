##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME = solver

SRC = main.c \
	my_str_to_word_array.c \
	tools.c \
	solver.c \

OBJ = $(SRC:.c=.o)

CFLAG = -W -Wall -Wextra -Werror -fno-stack-limit -fsplit-stack

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $(NAME)
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
