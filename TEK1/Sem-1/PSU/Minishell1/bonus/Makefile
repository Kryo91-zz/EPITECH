##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC = gcc

NAME = mysh

SRC =  src/main.c	\
		src/exit.c \
		src/env.c \
		src/shell.c \
		src/my_cd.c \
		src/cat.c \
		lib/my_str_to_word_array.c \
		lib/my_compute_power_rec.c  		\
		lib/my_compute_square_root.c		\
		lib/my_find_prime_sup.c 			\
		lib/my_getnbr.c 				\
		lib/my_isneg.c  				\
		lib/my_is_prime.c   			\
		lib/my_putchar.c    			\
		lib/my_put_nbr.c    			\
		lib/my_putstr.c 				\
		lib/my_revstr.c 				\
		lib/my_showmem.c    			\
		lib/my_showstr.c    			\
		lib/my_sort_int_array.c 			\
		lib/my_strcapitalize.c  			\
		lib/my_strcat.c 				\
		lib/my_strcmp.c 				\
		lib/my_strcpy.c 				\
		lib/my_str_isalpha.c			\
		lib/my_str_islower.c			\
		lib/my_str_isnum.c			\
		lib/my_str_isprintable.c			\
		lib/my_str_isupper.c				\
		lib/my_strlen.c 				\
		lib/my_strlowcase.c 			\
		lib/my_strncat.c    			\
		lib/my_strncmp.c    			\
		lib/my_strncpy.c    			\
		lib/my_strstr.c 				\
		lib/my_strupcase.c  			\
		lib/my_swap.c					\
		lib/redirec.c					\
		lib/my_printf.c						\
		lib/func_use.c					\
		lib/my_strlen_perc.c			\
		lib/func_use2.c					\
		lib/my_put_nbr_base.c			\
		lib/func_use3.c					\
		lib/my_put_unsi_nbr.c			\
		lib/my_strdup.c 				\

CFLAGS = -g3 -W

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
