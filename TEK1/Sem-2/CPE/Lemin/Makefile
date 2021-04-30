##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC = gcc

NAME = lem_in

SRC = src/main.c \
	src/my_str_to_word_array.c \
	src/my_strncmp.c \
	src/my_strlen.c \
	src/create_graph.c \
	src/continue_graph.c \
	src/graph.c \
	src/parsing.c \
	src/read_file.c \
	src/error_management.c \
	src/free_fonc.c \
	src/error_man2.c \

CFLAGS = -g3 -W -Wextra

OBJ = $(SRC:.c=.o) $(LIB:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all