##
## EPITECH PROJECT, 2020
## B-CPP-300-MPL-3-1-CPPD17-corentin.petrau
## File description:
## Makefile for unit test
##



RM			=	rm -f
CC			=	g++
CFLAGS		=	-W -Wall -Wextra -std=gnu11

SRC	=	*.cpp		\

OBJ			=	$(SRC:.cpp=.o)

NAME	=	unit_tests

TEST_SRC	=	tests/criterion_ex00.cpp	\
				tests/criterion_ex01.cpp	\
				tests/criterion_ex02.cpp	\
				ex02/Cesar.cpp				\
				ex02/OneTime.cpp			\

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