##
## EPITECH PROJECT, 2020
## Virtual Machine
## File description:
## Compile everything
##

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-W -Wall -Wextra -Iinclude
LDFLAGS		=	-L./ -lmy
TEST_FLAGS	=	-lcriterion

SRC		=	src/main.c			\

SRC_NO_MAIN =	src/file.c		\

SRC_TEST =	tests/help_test.c	\

OBJ		=	$(SRC:.c=.o)

TEST_NAME	=	unit_tests

TEST_FLAG = -lcriterion --coverage

NAME	=	corewar

all:	$(NAME)

re:	fclean all

$(NAME): $(OBJ)
	make -C ./lib/my > /dev/null
	$(CC) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) *~
	$(RM) $(TEST_OBJ)
	$(RM) *.gcno
	$(RM) *.gcda
	$(RM) unit_tests
	$(RM) libmy.a

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TEST_NAME)

tests_run:	$(TEST_NAME)

$(TEST_NAME):	$(SRC_TEST) $(SRC)
				make -C ./lib/my > /dev/null
				gcc -Iinclude $(TEST_FLAG) $(SRC_NO_MAIN) $(SRC_TEST) -o $(TEST_NAME) $(LDFLAGS)
				./unit_tests
				gcovr --exclude tests
				gcovr --exclude tests -b
