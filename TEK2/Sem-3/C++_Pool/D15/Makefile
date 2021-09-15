##
## EPITECH PROJECT, 2020
## B-CPP-300-MPL-3-1-CPPD03-alec.ferrari
## File description:
## Makefile for unit tests
##

RM			=	rm -f
CC			=	g++
CFLAGS		=	-W -Wall -Wextra -std=gnu11

SRC	=	*.cpp		\

OBJ			=	$(SRC:.cpp=.o)

NAME	=	unit_tests

TEST_SRC	=	tests/ex00_tests.cpp	\
				tests/ex01_tests.cpp	\
				tests/ex02_tests.cpp	\
				tests/ex03_tests.cpp	\
				tests/ex04_tests.cpp	\
				ex04/ex04.cpp			\

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
	$(CC) $(TEST_SRC) $(TEST_FLAGS) -o $(TEST_NAME)
	./$(TEST_NAME)