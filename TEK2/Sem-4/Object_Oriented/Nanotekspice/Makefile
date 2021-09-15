##
## EPITECH PROJECT, 2020
## B-OOP-400-MPL-4-1-tekspice-lyvia.mallereau
## File description:
## Makefile
##


RM			=	rm -f
CC			=	g++
CPPFLAGS	=	-W -Wall -Wextra -Iinclude -g3

SRC	=	src/main.cpp					\
		src/Parser.cpp					\

OBJ			=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	find -type f -name "*.gcno" -delete
	find -type f -name "*.gcda" -delete

fclean:	clean
	rm -f $(NAME)

re:	fclean all