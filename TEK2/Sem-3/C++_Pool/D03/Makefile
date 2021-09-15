##
## EPITECH PROJECT, 2020
## B-CPP-300-MPL-3-1-CPPD03
## File description:
## Makefile
##

RM =    rm -f

CFLAGS = -std=gnu11 -Wall -Wextra

SRC = string.c \
		assign.c \
		append.c \
		at.c \
		compare.c \
		tools.c \


OBJ = $(SRC:.c=.o)

NAME = libstring

TEST_SRC = tests/*.c \

TEST_NAME = unit_tests

TEST_FLAGS = --coverage -lcriterion

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME).a $(OBJ)
		rm -f $(NAME)
clean:
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda
	rm -f tests/*.gcno
	rm -f tests/*.gcda

fclean:    clean
	rm -f $(NAME).a
	rm -f $(TEST_NAME)

re: fclean all

tests_run:
	gcc $(TEST_SRC) $(TEST_FLAGS) $(SRC) -o $(TEST_NAME)
	./$(TEST_NAME)