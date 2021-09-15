##
## EPITECH PROJECT, 2020
## B-NWP-400-MPL-4-1-myftp-corentin.petrau
## File description:
## Makefile
##

NAME = myftp

SRC = src/main.c \
	src/create_socket.c \
	src/client_respond.c \
	src/my_str_to_word_array.c \
	src/which_cmd.c \
	src/server.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g3 -W -Wall -Wextra -Werror $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f units

re: fclean all