##
## EPITECH PROJECT, 2021
## B-CCP-400-MPL-4-1-theplazza-corentin.petrau
## File description:
## Makefile
##




RM			=	rm -f
CC			=	g++
CPPFLAGS	=	-W -Wall -Wextra -lpthread
CRFLAGS		= --coverage -lcriterion

SRC	=	src/main.cpp		\
		src/Reception.cpp	\
		src/Kitchen.cpp		\
		src/Ingredients.cpp	\
		src/IPC.cpp			\
		src/Client.cpp		\
		src/Logfile.cpp		\
		src/Mutex.cpp		\
		src/Thread.cpp		\
		src/Threadpool.cpp	\
		src/Safequeue.cpp	\
		src/Regina.cpp		\
		src/Margarita.cpp	\
		src/Fantasia.cpp	\
		src/Americana.cpp	\
		src/Process.cpp		\
		src/Error.cpp		\

TEST_SRC	=	tests/error_tests.cpp	\
				src/Error.cpp			\

OBJ			=	$(SRC:.cpp=.o)

NAME	=	plazza

NAME_TEST = unit_tests

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete

fclean:	clean
	rm -f $(NAME)
	-rm -f "Pizzeria"
	-rm $(NAME_TEST)

tests_run:
	$(CC) $(TEST_SRC) $(CRFLAGS) -o $(NAME_TEST)
	./$(NAME_TEST)

re:	fclean all