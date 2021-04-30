##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME = my_runner

SRC = main.c \
		second_file.c

CFLAGS = -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
