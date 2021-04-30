##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME = my_defender

SRC = $(wildcard src/*.c) \

CFLAGS = -C -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all
