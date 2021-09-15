##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME = my_convert_temp

SRC = temperature.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -W -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

re: fclean all

tests_run :
		gcc error.c ./tests/criterion.c -lcriterion --coverage -o unit_tests