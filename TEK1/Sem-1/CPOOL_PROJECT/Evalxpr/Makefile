##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME = eval_expr

SRC = eval_expr.c \
		calc_priority.c \
		priority_add_sub.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -c $(SRC)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all