##
## EPITECH PROJECT, 2020
## B-CPP-300-MPL-3-1-CPPD03-alec.ferrari
## File description:
## Makefile for unit tests
##

RM			=	rm -f
CC			=	g++
CFLAGS		=	-W -Wall -Wextra -std=gnu11

SRC	=	ex00/Picture.cpp	\
		ex00/Toy.cpp		\

OBJ			=	$(SRC:.cpp=.o)

NAME	=	unit_tests

TEST_SRC	=	tests/Picture_tests.cpp	\
				tests/Toy_tests.cpp		\

TEST_NAME	=	unit_tests

TEST_FLAGS	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):	tests_run

clean:
	rm -f $(OBJ)
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete
	find -type f -name "$(TEST_NAME)" -delete

fclean:	clean

re:	fclean all

tests_run:
	$(CC) $(SRC) $(TEST_SRC) $(TEST_FLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)