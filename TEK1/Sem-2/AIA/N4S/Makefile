##
## EPITECH PROJECT, 2019
## AIA_n4s_2019
## File description:
## Makefile
##

CC	=	gcc
RM	=	rm -rf
CFLAGS	=	-W -Wall -Wextra -Iinclude
SRC	=	src/check_str_empty.c	\
		src/my_strcat.c			\
		src/my_word_array.c		\
		src/commands.c			\
		src/get_dir.c			\
		src/main.c
OBJ	=	$(SRC:.c=.o)
NAME = ai

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $@ $^

.SILENT: clean

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ:.o=.gcno)
	$(RM) $(OBJ:.o=.gcda)

fclean: clean
	$(RM) $(NAME)
	$(RM) log
	$(RM) n4s_package/ai

re: fclean all

run: all
	rm -rf ./n4s_package/ai
	mv ai n4s_package/